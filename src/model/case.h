#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

#include <stdlib.h>

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

//Level -1
#define ELECTRIC 7

//LEVEL -2
#define CONDUCT 8

typedef struct _case
{
    //Sol : habitation, routes
    int state0;

    //Sous-sol -1 : electricite
    int state1;

    //Sous sol -2 : eau
    int state2;

    int habit_nbr;
} t_case;

t_case **init_tabCases();

#endif // CASE_H_INCLUDED
