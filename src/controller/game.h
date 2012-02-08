#ifndef HEADER_CONTROLLER_GAME_INCLUDED
#define HEADER_CONTROLLER_GAME_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <string.h>
#include "../shared/platform.h"

#ifdef LINUX
	#include <pthread.h>
#endif

#ifdef WINDOWS
	#include "../shared/pthreadwin32/pthread.h"
#endif

#include "../model/bitmaps.h"
#include "../model/case.h"
#include "../model/scroll.h"
#include "../view/display_map.h"
#include "../shared/val.h"
#include "action.h"

void game();

#endif // HEADER_CONTROLLER_GAME_INCLUDED
