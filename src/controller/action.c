#include "action.h"

void* action(void* camera)
{
	// 0. déclaration des variables locales
	static int x2d, y2d;
	static float xx, yy;
	t_scroll* cam = (t_scroll*)camera;

	// 1. cas du clic gauche
	while(1)
	{
		usleep(500);
		if(mouse_b&1)
		{
			if(!is_active_menu(cam->menu))
			{
				xx=mouse_x+cam->dx;
				yy=mouse_y+cam->dy;

				x2d = (yy / (TILE_H * cam->zoom) + xx / (TILE_W * cam->zoom));
				y2d = (yy / (TILE_H * cam->zoom) - xx / (TILE_W * cam->zoom));

				while(mouse_b&1){ usleep(500); }

				if(!(x2d > size_map || x2d < 0 || y2d > size_map || y2d < 0))
				{
					printf("clicked : (%0.1f, %0.1f) -> (%d, %d)\n", xx, yy, x2d, y2d);
					/// TODO : ajout de maison, éléctricité ou eau
				}
			}
			else
			{
				click_menu(cam->menu);
				while(mouse_b&1){ usleep(500); }
			}
		}
	}

	return NULL;
}
