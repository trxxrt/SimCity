#include "./tools.h"

BITMAP * load_bitmap_check(char *pictureName)
{
    BITMAP *bmp;
    bmp=load_bitmap(pictureName,NULL);
    if (!bmp)
    {
        allegro_message("cant find %s",pictureName);
        exit(EXIT_FAILURE);
    }
    return bmp;
}
