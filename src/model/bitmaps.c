#include "bitmaps.h"

t_tiles * load_tiles()
{
	t_tiles * tiles;
	tiles=malloc(sizeof(t_tiles));

	tiles->sea=load_bitmap("res/game/sea.bmp", NULL);
	tiles->ground=load_bitmap("res/game/ground.bmp",NULL);
	tiles->electric=load_bitmap("res/game/elec.bmp", NULL);
	tiles->in_construction=load_bitmap("res/game/small_construct.bmp",NULL);
	tiles->house=load_bitmap("res/game/small_house.bmp",NULL);
	tiles->powerplant=load_bitmap("res/game/power_plant.bmp",NULL);
	tiles->water=load_bitmap("res/game/water.bmp",NULL);
	tiles->road=load_bitmap("res/game/road.bmp",NULL);
	tiles->construct=load_bitmap("res/game/construct.bmp",NULL);
	tiles->conduct=load_bitmap("res/game/conduct.bmp", NULL);

	return tiles;
}
