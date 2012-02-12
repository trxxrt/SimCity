#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

#include <stdlib.h>
#include <allegro.h>

#include "../shared/val.h"

//Generique
#define SEA 0
#define GROUND 1

//Level 0
#define ROAD 2
#define CONSTRUCT 3
#define HOUSE 4
#define POWER_PLANT 5
#define WATER 6
#define IN_CONSTRUCTION 9

//Level -1
#define ELECTRIC 7

//LEVEL -2
#define CONDUCT 8

typedef struct _case
{
	//Sol : habitation, routes
	int state0;
	int state0_m;

	//Sous-sol -1 : electricite
	int state1;
	int state1_m;

	//Sous sol -2 : eau
	int state2;
	int state2_m;

	//nombre d'habitants
	int habit_nbr;

	//nombre d'années à construire
	int y_build;

	//variables de connexion aux réseaux :
	int water;
	int elec;
	int road;

	//nombre de places dans le bâtiment actuel:
	int build_size;
	int build_img;
	int build_age;
} t_case;

t_case **init_tabCases();

#endif // CASE_H_INCLUDED
