#ifndef NETWORK_H
#define NETWORK_H

#include "../model/case.h"
#include "../shared/val.h"

#define ROAD 0
#define WATER 1
#define ELEC 2

//fonction de mise à jour d'un réseau
void net_maj(t_case** tab, int t);

//fonction de parcourt d'un réseau :
void net_run(t_case** tab, int t);

#endif
