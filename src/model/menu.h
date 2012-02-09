#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define MENU_NULL 0
#define MENU_ROAD 1
#define MENU_B_AREA 2
#define MENU_WATER 3
#define MENU_POWER_PLANT 4
#define MENU_CONDUCT 5
#define MENU_ELECTRIC 6

#include <stdlib.h>
#include <stdio.h>
#include <allegro.h>
#include "../shared/tools.h"


//Structure gérant le menu
typedef struct _menu
{
	//Dernier choix effectué
	int last_choice;
	//Image du menu
	BITMAP * img;
}t_menu;

//Initialisation de la structure menu
t_menu * initi_menu();

//Gestion du menu
int is_active_menu(t_menu * menu);

//Gestion du click de la souris dans le menu
void click_menu(t_menu * menu);

//Affichage du menu
//A utiliser en dernier pour que le menu soit au dessus
void display_menu(BITMAP * buffer, t_menu * menu);

#endif // MENU_H_INCLUDED
