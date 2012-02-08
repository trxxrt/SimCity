#include "bitmaps.h"

t_tiles * load_tiles()
{
    t_tiles * tiles;
    tiles=malloc(sizeof(t_tiles));

    tiles->sea=load_bitmap("res/game/sea.bmp", NULL);
    tiles->ground=load_bitmap("res/game/ground.bmp",NULL);
    tiles->electric=load_bitmap("res/game/elec.bmp", NULL);

    return tiles;
}
