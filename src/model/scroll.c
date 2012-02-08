#include "scroll.h"

void update_camera (t_scroll* camera)
{
	camera->dx = camera->temp_dx;
	camera->dy = camera->temp_dy;
	camera->floor = camera->temp_floor;
	camera->zoom = camera->temp_zoom;
}

t_scroll * init_scroll ()
{
    t_scroll * camera=malloc(sizeof(t_scroll));

    camera->dx=0;
    camera->dy=0;
    camera->zoom=1.0;
    camera->floor=0;
    camera->temp_dx=0;
    camera->temp_dy=0;
    camera->temp_zoom=1.0;
    camera->temp_floor=0;

    return camera;
}

void* zoom (void * camera)
{
	t_scroll* cam = (t_scroll*)camera;

	while(1)
	{
		usleep(500);
		if(key[KEY_PLUS_PAD] && cam->temp_zoom<2.0)
		{
		while(key[KEY_PLUS_PAD]){ usleep(500); }
			cam->temp_zoom=cam->temp_zoom*2.0;
			cam->temp_dx*=2;
			cam->temp_dy*=2;
		}
		if(key[KEY_MINUS_PAD]&& cam->temp_zoom>0.5)
		{
		while(key[KEY_MINUS_PAD]){ usleep(500); }
			cam->temp_zoom=cam->temp_zoom*0.5;
			cam->temp_dx/=2;
			cam->temp_dy/=2;
		}
	}

    return NULL;
}

void* floor_c (void * camera)
{
	t_scroll* cam = (t_scroll*)camera;

	while(1)
	{
		usleep(500);
		if(key[KEY_PGDN] && cam->temp_floor >-2)
		{
			while(key[KEY_PGDN]){ usleep(500); }
			cam->temp_floor--;
		}
		if(key[KEY_PGUP] && cam->temp_floor<0)
		{
			while(key[KEY_PGUP]){ usleep(500); }
			cam->temp_floor++;
		}
	}

    return NULL;
}

void* scrolling (void * camera)
{
	t_scroll* cam = (t_scroll*)camera;

	while(1)
	{
		usleep(250);
		if(key[KEY_DOWN] && cam->temp_dy < size_map * TILE_H / 2 *cam->temp_zoom + SCREEN_H) cam->temp_dy ++;
		if(key[KEY_UP]) cam->temp_dy --;
		if(key[KEY_LEFT]) cam->temp_dx --;
		if(key[KEY_RIGHT]) cam->temp_dx ++;
	}
	return NULL;
}
