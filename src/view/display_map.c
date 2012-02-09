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
	float zoom;

	while(!key[KEY_ESC])
	{
		usleep(LONG_SLEEPING_TIME);

		dx = camera->dx;
		dy = camera->dy;
		zoom = camera->zoom;

		clear_bitmap(buffer);

		if (camera->floor==0)
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
				}
			}
		}
		else if (camera->floor==-1)
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
				}
			}
		}

		display_menu(buffer, menu);
		info_click(tab, buffer, camera);
		draw_sprite(screen, buffer, 0, 0);
	}
	return NULL;
}
