#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>

#include "../model/case.h"
#include "../shared/val.h"
#include "../shared/file.h"

#define NET_ROAD 0
#define NET_WATER 1
#define NET_ELEC 2

typedef struct net_pos
{
	int x;
	int y;
}t_net_pos;

//fonction de mise à jour d'un réseau
void net_maj(t_case** tab, int t);

//fonction de parcourt d'un réseau :
void net_run(t_case** tab, int t, int x, int y);

//fonction de marquage des cases adjascentes 
void net_adj_run(t_case** tab, int t, int x, int y, int* c);

//fonction de marquage de passage de la case demandé
void net_marq(t_case* p, int t);

//fonction retournant si la case contient un type demandé non marqué
int net_is_marq(t_case* p, int t);

//fonction d'allocation d'un t_net_pos:
t_net_pos* net_pos_alloc(int x, int y);

#endif
