#ifndef SCROLL_H_INCLUDED
#define SCROLL_H_INCLUDED

#include <allegro.h>

#include "../shared/val.h"
#include "menu.h"

//Gestion du scrolling et du zoom
typedef struct scroll
{
	int dx;
	int dy;
	float zoom;
	int floor;
	int temp_dx;
	int temp_dy;
	float temp_zoom;
	int temp_floor;
	t_menu* menu;
} t_scroll;

//Initialisation camera
t_scroll * init_scroll ();

//Gestion camera
void update_camera (t_scroll* camera);
void* zoom (void * camera);
void* scrolling (void * camera);
void* floor_c (void * camera);

#endif // SCROLL_H_INCLUDED
