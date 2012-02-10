#include "scroll.h"

void* update_camera (void* camera)
{
	t_scroll* cam = (t_scroll*)camera;

	while(!end_of_game)
	{
		usleep(SLEEPING_TIME);
		cam->dx = cam->temp_dx;
		cam->dy = cam->temp_dy;
		cam->floor = cam->temp_floor;
		cam->zoom = cam->temp_zoom;
	}
	return NULL;
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

	while(!end_of_game)
	{
		usleep(LONG_SLEEPING_TIME);
		if(key[KEY_PLUS_PAD] && cam->temp_zoom<2.0)
		{
		while(key[KEY_PLUS_PAD]){ usleep(LONG_SLEEPING_TIME); }
			cam->temp_zoom=cam->temp_zoom*2.0;
			cam->temp_dx*=2;
			cam->temp_dy*=2;
		}
		if(key[KEY_MINUS_PAD]&& cam->temp_zoom>0.125)
		{
		while(key[KEY_MINUS_PAD]){ usleep(LONG_SLEEPING_TIME); }
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

	while(!end_of_game)
	{
		usleep(LONG_SLEEPING_TIME);
		if(key[KEY_PGDN] && cam->temp_floor >-2)
		{
			while(key[KEY_PGDN]){ usleep(LONG_SLEEPING_TIME); }
			cam->temp_floor--;
		}
		if(key[KEY_PGUP] && cam->temp_floor<0)
		{
			while(key[KEY_PGUP]){ usleep(LONG_SLEEPING_TIME); }
			cam->temp_floor++;
		}
	}

	return NULL;
}

void* scrolling (void * camera)
{
	t_scroll* cam = (t_scroll*)camera;
	int taped = 0;

	while(!end_of_game)
	{
		if(taped)
		{
			usleep(SHORT_SLEEPING_TIME);
			if(!key[KEY_DOWN] && !key[KEY_UP] && !key[KEY_RIGHT] && !key[KEY_LEFT]) taped = 0;
			if(key[KEY_DOWN]) cam->temp_dy ++;
			if(key[KEY_UP]) cam->temp_dy --;
			if(key[KEY_LEFT]) cam->temp_dx --;
			if(key[KEY_RIGHT]) cam->temp_dx ++;
		}
		else
		{
			usleep(LONG_SLEEPING_TIME);
			if(key[KEY_DOWN] || key[KEY_UP] || key[KEY_RIGHT] || key[KEY_LEFT]) taped = 1;
			if(key[KEY_DOWN]) cam->temp_dy ++;
			if(key[KEY_UP]) cam->temp_dy --;
			if(key[KEY_LEFT]) cam->temp_dx --;
			if(key[KEY_RIGHT]) cam->temp_dx ++;
		}
	}
	return NULL;
}
