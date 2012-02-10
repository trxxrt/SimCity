#ifndef CONTROLLER_ACTION_H
#define CONTROLLER_ACTION_H

#include <allegro.h>
#include <stdio.h>

#include "../model/scroll.h"
#include "game.h"
#include "../model/menu.h"
#include "../shared/val.h"

void* action(void* camera);
void* check_end_of_game(void* game_r);

#endif

