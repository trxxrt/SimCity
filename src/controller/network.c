#include "network.h"

/**
 *	fonction de mise à jour d'un réseau 

 *	@param: - tab -> tableau de case de la map à mettre à jour
 *		- t -> type du réseau à mettre à jour

 *	@return: nothing
**/
void net_maj(t_case** tab, int t)
{
	//ressources
	int i, j;

	//si c'est le réseau routier :
	if(t==ROAD)
	{
		//on cherche les routes non marqué pour lancer l'algo :
		for(i=0; i<size_map; i++)
			for(j=0; j<size_map; j++)
			{
				if((tab[i][j]->state == ROAD) && (tab[i][j]->state_m != 1))//TODO
					//appel de la fonction du réseau TODO
			}

	else
	{
		//on cherche les centrales :
		for(i=0; i<size_map; i++)
			for(j=0; j<size_map; j++)
			{
				if(t==WATER)
					if(tab[i][j]->state)//TODO
						//appel de la fonction du réseau TODO
				else if(t==ELEC)
					if(tab[i][j]->state)//TODO
						//appel de la fonction du réseau TODO
			}
	}
}

/**
 *	fonction de parcourt d'un réseau :

 *	@param: - tab -> tableau de cases de la map à parcourir
 *		- t -> type du réseau à parcourir

 *	@return: nothing
**/
void net_run(t_case** tab, int t)
{
	//ressources
	
