#include "action.h"

void* action(void* game_r)
{
	// 0. déclaration des variables locales
	static int x2d, y2d;
	static float xx, yy;
	t_game* game = (t_game*)game_r;
	t_scroll* cam = game->camera;

	// 1. cas du clic gauche
	while(!key[KEY_ESC])
	{
		usleep(SLEEPING_TIME);
		if(mouse_b&1)
		{
			if(!is_active_menu(game->menu))
			{
				xx=mouse_x+cam->dx;
				yy=mouse_y+cam->dy;

				x2d = (yy / (TILE_H * cam->zoom) + xx / (TILE_W * cam->zoom));
				y2d = (yy / (TILE_H * cam->zoom) - xx / (TILE_W * cam->zoom));

				while(mouse_b&1){ usleep(LONG_SLEEPING_TIME); }

				if(!(x2d > size_map-1 || x2d < 0 || y2d > size_map-1 || y2d < 0))
				{
					//printf("* clicked : CASE (%0.1f, %0.1f) -> (%d, %d)\n", xx, yy, x2d, y2d);
					printf("clicked : CASE (%d, %d)\n", x2d, y2d);
					/// TODO : ajout de maison, éléctricité ou eau
				}
			}
			else
			{
				click_menu(game->menu);
				while(mouse_b&1){ usleep(LONG_SLEEPING_TIME); }
			}
		}
	}

	return NULL;
}
