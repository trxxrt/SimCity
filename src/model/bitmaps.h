#ifndef BITMAPS_H_INCLUDED
#define BITMAPS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>


typedef struct _tiles
{
	BITMAP * ground;
	BITMAP * sea;
	BITMAP * road;
	BITMAP * construct;
	BITMAP * house;
	BITMAP * powerplant;
	BITMAP * water;
	BITMAP * electric;
	BITMAP * conduct;
	BITMAP * in_construction;
} t_tiles;

t_tiles * load_tiles();

#endif // BITMAPS_H_INCLUDED
