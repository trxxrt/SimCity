#include "display_map.h"

void* print_map (void* game_r)
{
	t_game* game = (t_game*)game_r;
	int i,j;
	int x,y;
	int x_screen, y_screen;
	t_case **tab = game->tab;
	BITMAP * buffer = game->buffer;
	t_scroll * camera = game->camera;
	t_menu * menu = game->menu;
	t_tiles * tiles = game->tiles;
	int dx;
	int dy;
	int floor;
	float zoom;

	while(!end_of_game)
	{
		usleep(SLEEPING_TIME);

		dx = camera->dx;
		dy = camera->dy;
		floor = camera->floor;
		zoom = camera->zoom;

		clear_bitmap(buffer);

		if (floor==0)
		{
			for (i=0; i<size_map; i++)
			{
				for(j=0; j<size_map; j++)
				{
					x= i;
					y= j;
					x_screen= ((x - y) * TILE_W/2 * zoom) - 64*zoom - dx;
					y_screen= ((x + y) * TILE_H/2 * zoom) - dy;
					if(tab[i][j].state0==SEA)
						stretch_sprite(buffer,tiles->sea, x_screen, y_screen, tiles->sea->w * zoom, tiles->sea->h * zoom);
					else if(tab[i][j].state0==GROUND)
						stretch_sprite(buffer,tiles->ground, x_screen, y_screen, tiles->ground->w * zoom, tiles->ground->h * zoom);
					else if(tab[i][j].state0==CONSTRUCT)
						stretch_sprite(buffer,tiles->construct, x_screen, y_screen, tiles->construct->w * zoom, tiles->construct->h * zoom);
					else if(tab[i][j].state0==HOUSE)
						stretch_sprite(buffer,tiles->house, x_screen, y_screen, tiles->house->w * zoom, tiles->house->h * zoom);
					else if(tab[i][j].state0==POWER_PLANT)
						stretch_sprite(buffer,tiles->powerplant, x_screen, y_screen, tiles->powerplant->w * zoom, tiles->powerplant->h * zoom);
					else if(tab[i][j].state0==WATER)
						stretch_sprite(buffer,tiles->water, x_screen, y_screen, tiles->water->w * zoom, tiles->water->h * zoom);
					else if(tab[i][j].state0==IN_CONSTRUCTION)
						stretch_sprite(buffer,tiles->in_construction, x_screen, y_screen, tiles->in_construction->w * zoom, tiles->in_construction->h * zoom);
					else if(tab[i][j].state0==ROAD)
						stretch_sprite(buffer,tiles->road, x_screen, y_screen, tiles->road->w * zoom, tiles->road->h * zoom);
				}
			}
			textprintf_ex(buffer, font, SCREEN_W-155, SCREEN_H-20, makecol(0,0,0), makecol(255,255,255), "étage CONSTRUCTION");
		}
		else if (floor==-1)
		{
			for (i=0; i<size_map; i++)
			{
				for(j=0; j<size_map; j++)
				{
					x= i;
					y= j;
					x_screen= ((x - y) * TILE_W/2 * zoom) - 64*zoom - dx;
					y_screen= ((x + y) * TILE_H/2 * zoom) - dy;
					if(tab[i][j].state1==SEA)
						stretch_sprite(buffer,tiles->sea, x_screen, y_screen, tiles->sea->w * zoom, tiles->sea->h * zoom);
					else if(tab[i][j].state1==GROUND)
						stretch_sprite(buffer,tiles->ground, x_screen, y_screen, tiles->ground->w * zoom, tiles->ground->h * zoom);
					else if(tab[i][j].state1==ELECTRIC)
						stretch_sprite(buffer,tiles->electric, x_screen, y_screen, tiles->electric->w * zoom, tiles->electric->h * zoom);
					else if(tab[i][j].state1==POWER_PLANT)
						stretch_sprite(buffer,tiles->powerplant, x_screen, y_screen, tiles->powerplant->w * zoom, tiles->powerplant->h * zoom);
				}
			}
			textprintf_ex(buffer, font, SCREEN_W-150, SCREEN_H-20, makecol(0,0,0), makecol(255,255,255), "étage ELECTRICITE");
		}
		else if (floor==-2)
		{
			for (i=0; i<size_map; i++)
			{
				for(j=0; j<size_map; j++)
				{
					x= i;
					y= j;
					x_screen= ((x - y) * TILE_W/2 * zoom) - 64*zoom - dx;
					y_screen= ((x + y) * TILE_H/2 * zoom) - dy;
					if(tab[i][j].state2==SEA)
						stretch_sprite(buffer,tiles->sea, x_screen, y_screen, tiles->sea->w * zoom, tiles->sea->h * zoom);
					else if(tab[i][j].state2==GROUND)
						stretch_sprite(buffer,tiles->ground, x_screen, y_screen, tiles->ground->w * zoom, tiles->ground->h * zoom);
					else if(tab[i][j].state2==CONDUCT)
						stretch_sprite(buffer,tiles->conduct, x_screen, y_screen, tiles->conduct->w * zoom, tiles->conduct->h * zoom);
					else if(tab[i][j].state2==WATER)
						stretch_sprite(buffer,tiles->water, x_screen, y_screen, tiles->water->w * zoom, tiles->water->h * zoom);
				}
			}
			textprintf_ex(buffer, font, SCREEN_W-80, SCREEN_H-20, makecol(0,0,0), makecol(255,255,255), "étage EAU");
		}

		//affichage du nombre d'habitants :
		textprintf_ex(buffer, font, 20, SCREEN_H-20, makecol(0,0,0), makecol(255,255,255), "Population : %d", game->nb_habitant);
		display_menu(buffer, menu);
		info_click(tab, buffer, camera);
		draw_sprite(screen, buffer, 0, 0);
	}
	return NULL;
}
