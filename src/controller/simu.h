#ifndef SIMU_H
#define SIMU_H

#include <allegro.h>
#include <stdio.h>

#include "../model/case.h"
#include "../shared/val.h"

/*fonction de raz des différents marqueurs et comptage de la population*/
int simu_raz(t_case** tab);

/*fonction de simulation*/
int simu_all(t_case** tab);

/*fonction de gesion des flux de population*/
void simu_pop(t_case* p);

/*fonction de mise à jour des bitmaps*/
void simu_bmp_maj(t_case* p);

#endif
