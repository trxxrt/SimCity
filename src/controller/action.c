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
		if(mouse_b&1)
		{
			xx=mouse_x+cam->dx;
			yy=mouse_y+cam->dy;

			x2d = (yy / (TILE_H * cam->zoom) + xx / (TILE_W * cam->zoom));
			y2d = (yy / (TILE_H * cam->zoom) - xx / (TILE_W * cam->zoom));

			while(mouse_b&1){}

			printf("clicked : (%0.1f, %0.1f) -> (%d, %d)\n", xx, yy, x2d, y2d);
		}
	}

	return NULL;
}
