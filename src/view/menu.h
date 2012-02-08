#ifndef MENU_H
#define MENU_H

#include <allegro.h>

#include "../model/button.h"
#include "../shared/tools.h"

#define GAME 1
#define QUIT 2
#define OPTION 3

///////////////////////////////////////
//	FONCTION D'AFFICHAGE DU MENU
//	param : .
//	return : entier pour savoir où aller : QUITTER, JEU, OPTIONS
int menu_main();
///////////////////////////////////////

#endif
