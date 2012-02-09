#include "simu.h"

/**
 *	fonction de raz des marqueurs des cases de la map
 
 * 	@param: - tab -> tableau de case de la map à raz
 
 * 	@return: - nombre d'habitants sur l'ile
**/
int simu_raz(t_case** tab)
{
	//ressources
	int i, j;
	int retour = 0;

	//parcourt du tableau :
	for(i=0; i<size_map; i++)
		for(j=0; j<size_map; j++)
		{
			//raz des valeurs :
			tab[i][j]->state0_m = 0;
			tab[i][j]->state1_m = 0;
			tab[i][j]->state2_m = 0;

			//compte des habitants :
			retour += tab[i][j]->habit_nbr;
		}

	return retour;
}

/**
 * 	foction de simulation générale 

 * 	@param: - tab -> tableau de case de la map à simuler pour ce tour

 * 	@return: nothing
**/
void simu_all(t_case** tab)
{
	//test des liaisons aux réseaux :
	//réseau routier :
	//TODO
	//réseau électrique :
	//TODO
	//réseau d'eau :
	//TODO

	//mouvements de population :
}


/**
 * 	fonction de gestion des flux de population

 *	@param: - tab -> tableau de case de la map où créer les flux

 * 	@return: nothing
**/
void simu_pop(t_case** tab)
{
	//ressources
	int i, j;
	int percent_n, percent_p, percent_s;
	int add;

	//parcourt du tableau :
	for(i=0; i<size_map; i++)
		for(j=0; j<size_map; j++)
		{
			percent_p = 50;
			percent_s = 20;
			
			//modification des pourcentages en fonction des connexions aux différents réseaux :
			if(!tab[i][j]->road)
			{
				percent_p = 0;
				percent_s = 50;
			}
			else
			{
				if(!tab[i][j]->water)
				{
					percent_p -= 15;
					percent_s += 10;
				}
				if(!tab[i][j]->elec)
				{
					persent_p -= 15;
					persent_s += 10;
				}
			}
			percent_n = 100 - percent_p - percent_s;
			
			//ajout des personnes dans la case :
			add = rand()%101;
		}
}
