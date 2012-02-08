#ifndef DISPLAY_MAP_H_INCLUDED
#define DISPLAY_MAP_H_INCLUDED

#include <allegro.h>

#include "../shared/val.h"
#include "../model/scroll.h"
#include "../model/bitmaps.h"
#include "../model/case.h"
#include "../view/click.h"

void print_map (t_case **tab, BITMAP * buffer, t_scroll * camera, t_tiles * tiles);

#endif // DISPLAY_MAP_H_INCLUDED
