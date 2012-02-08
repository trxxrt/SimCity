#include "display_map.h"

void print_map (t_case **tab, BITMAP * buffer, t_scroll * camera, t_tiles * tiles)
{
    int i,j;
    int x,y;
    int x_screen, y_screen;
    clear_bitmap(buffer);

    if (camera->floor==0)
        for (i=0; i<size_map; i++)
        {
            for(j=0; j<size_map; j++)
            {
                x= i;
                y= j;
                x_screen= ((x - y) * TILE_W/2 * camera->zoom) - 64*camera->zoom - camera->dx;
                y_screen= ((x + y) * TILE_H/2 * camera->zoom) - camera->dy;
                if(tab[i][j].state0==SEA)
                    stretch_sprite(buffer,tiles->sea, x_screen, y_screen, tiles->sea->w * camera->zoom, tiles->sea->h * camera->zoom);
                else if(tab[i][j].state0==GROUND)
                    stretch_sprite(buffer,tiles->ground, x_screen, y_screen, tiles->ground->w * camera->zoom, tiles->ground->h * camera->zoom);
            }
        }
    else if (camera->floor==-1)
        for (i=0; i<size_map; i++)
        {
            for(j=0; j<size_map; j++)
            {
                x= i;
                y= j;
                x_screen= ((x - y) * TILE_W/2 * camera->zoom) - 64*camera->zoom - camera->dx;
                y_screen= ((x + y) * TILE_H/2 * camera->zoom) - camera->dy;
                if(tab[i][j].state1==SEA)
                    stretch_sprite(buffer,tiles->sea, x_screen, y_screen, tiles->sea->w * camera->zoom, tiles->sea->h * camera->zoom);
                else if(tab[i][j].state1==GROUND)
                    stretch_sprite(buffer,tiles->ground, x_screen, y_screen, tiles->ground->w * camera->zoom, tiles->ground->h * camera->zoom);
                else if(tab[i][j].state1==ELECTRIC)
                    stretch_sprite(buffer,tiles->electric, x_screen, y_screen, tiles->electric->w * camera->zoom, tiles->electric->h * camera->zoom);
            }
        }
    info_click(tab, buffer, camera);
    draw_sprite(screen, buffer, 0, 0);
}
