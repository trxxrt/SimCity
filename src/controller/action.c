#include "action.h"

void* check_end_of_game(void* game_r)
{
	t_game* game = (t_game*)game_r;

	while(!end_of_game)
	{
		usleep(LONG_SLEEPING_TIME);
		if(key[KEY_ESC]) end_of_game = 1;
	}

	return NULL;
}

void* action(void* game_r)
{
	// 0. déclaration des variables locales
	static int x2d, y2d;
	static float xx, yy;
	t_game* game = (t_game*)game_r;
	t_scroll* cam = game->camera;

	// 1. cas du clic gauche
	while(!end_of_game)
	{
		usleep(SHORT_SLEEPING_TIME);
		if(mouse_b&1)
		{
			if(!is_active_menu(game->menu))
			{
				xx=mouse_x+cam->dx;
				yy=mouse_y+cam->dy;

				x2d = (yy / (TILE_H * cam->zoom) + xx / (TILE_W * cam->zoom));
				y2d = (yy / (TILE_H * cam->zoom) - xx / (TILE_W * cam->zoom));

				usleep(LONG_SLEEPING_TIME);

				if(!(x2d > size_map-1 || x2d < 0 || y2d > size_map-1 || y2d < 0))
				{
					//printf("* clicked : CASE (%0.1f, %0.1f) -> (%d, %d)\n", xx, yy, x2d, y2d);
					printf("clicked : CASE (%d, %d)\n", x2d, y2d);
					/// TODO : ajout de maison, éléctricité ou eau

					switch (game->menu->last_choice)
					{
						case MENU_ROAD :

							printf("AJOUT route\n");
							game->tab[x2d][y2d].state0 = ROAD;

							break;

						case MENU_B_AREA :

							printf("AJOUT zone d'habitation\n");
							game->tab[x2d][y2d].state0 = CONSTRUCT;

							break;

						case MENU_WATER :

							printf("AJOUT central d'eau\n");
							game->tab[x2d][y2d].state0 = WATER;
							game->tab[x2d][y2d].state2 = WATER;
							game->tab[x2d][y2d].build_age = 100;

							break;

						case MENU_POWER_PLANT :

							printf("AJOUT central electrique\n");
							game->tab[x2d][y2d].state0 = POWER_PLANT;
							game->tab[x2d][y2d].state1 = POWER_PLANT;
							game->tab[x2d][y2d].build_age = 100;

							break;

						case MENU_CONDUCT :

							printf("AJOUT tuyau d'eau\n");
							game->tab[x2d][y2d].state2 = CONDUCT;

							break;

						case MENU_ELECTRIC :

							printf("AJOUT electricite\n");
							game->tab[x2d][y2d].state1 = ELECTRIC;

							break;

						default :
							break;
					}

				}
			}
			else
			{
				click_menu(game->menu);
				while(mouse_b&1){ usleep(SLEEPING_TIME); }
			}
		}
	}

	return NULL;
}
