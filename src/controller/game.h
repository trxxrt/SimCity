#ifndef HEADER_CONTROLLER_GAME_INCLUDED
#define HEADER_CONTROLLER_GAME_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <string.h>
#include <time.h>
#include "../view/music.h"
#include "../shared/platform.h"

#ifdef LINUX
	#include <pthread.h>
#endif

#ifndef LINUX
	#include "../shared/pthreadwin32/pthread.h"
#endif

#include "../model/bitmaps.h"
#include "../model/menu.h"
#include "../model/case.h"
#include "../model/scroll.h"
#include "../view/display_map.h"
#include "../shared/val.h"
#include "action.h"
#include "simu.h"

typedef struct _game {

	int simulateur;
	int nb_habitant;
	int temps;
	t_tiles * tiles;
	BITMAP * buffer;
	t_case **tab;
	t_scroll * camera;
	t_menu * menu;

}t_game;

void start_game();

#endif // HEADER_CONTROLLER_GAME_INCLUDED

