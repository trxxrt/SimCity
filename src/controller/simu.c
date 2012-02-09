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
			tab[i][j].state0_m = 0;
			tab[i][j].state1_m = 0;
			tab[i][j].state2_m = 0;

			//compte des habitants :
			retour += tab[i][j].habit_nbr;
		}

	return retour;
}

/**
 * 	foction de simulation générale 

 * 	@param: - tab -> tableau de case de la map à simuler pour ce tour

 * 	@return: nombre d'habitants sur la carte
**/
int simu_all(t_case** tab)
{
	//ressources 
	int i, j;
	int ret;

	//remise à zéro du tableau de case :
	ret = simu_raz(tab);

	//test des liaisons aux réseaux :
	//réseau routier :
	//TODO
	//réseau électrique :
	//TODO
	//réseau d'eau :
	//TODO

	//mouvements de population et mise à jour des bitmaps :
	for(i=0; i<size_map; i++)
		for(j=0; j<size_map; j++)
		{
			simu_pop(&tab[i][j]);
			simu_bmp_maj(&tab[i][j]);
		}

	return ret;
}


/**
 * 	fonction de gestion des flux de population

 *	@param: - p -> pointeur sur la case à maj

 * 	@return: nothing
**/
void simu_pop(t_case* p)
{
	//ressources
	int percent_pos, percent_sub, percent_ne;
	int add;

	//on commence par vérifier si c'est bien une case d'habitation :
	if(p->state0 == CONSTRUCT)
	{
		//si non connecté à une route
		if(!p->road)
		{
			percent_pos = 0;
			percent_sub = 50;
		}
		else
		{
			percent_pos = 25;
			percent_sub = 25;
		}

		//si non connecté au réseau d'eau :
		if(!p->water)
		{
			percent_pos -= 10;
			percent_sub += 20;
		}
		else
		{
			percent_pos += 5;
			percent_sub -= 5;
		}

		//si non connecté au réseau électrique :
		if(!p->elec)
		{
			percent_pos -= 10;
			percent_sub += 20;
		}
		else
		{
			percent_pos += 5;
			percent_sub -= 5;
		}

		//si le bâtiment n'est pas en sur population
		if(p->habit_nbr > p->build_size)
		{
			percent_pos -= 25;
			percent_sub += 20;
		}

		//on remet les possibilité à 0 minimum:
		percent_pos = (percent_pos < 0) ? 0 : percent_pos;
		percent_sub = (percent_sub < 0) ? 0 : percent_sub;

		//on met à jour le pourcentage neutre :
		percent_ne = 100 - percent_pos - percent_sub;

		//aléatoir pour l'ajout ou la soustraction d'habitants
		add = rand()%101;

		//calcul du nombre de personne à ajouter
		if(add < percent_ne)
			add = 0;
		else
		{
			if(add < percent_ne + percent_pos)
				add = 1;
			else
			{
				if(add < 100)
					add = -1;
				else
					add = 0; //WTF ?
			}
		}
		p->habit_nbr += add * ((rand()%5) + 1);

	}
}

/**
 *	fonction de mise à jour des bitmaps de la case

 *	@param: - p -> pointeur sur la case à actualiser

 *	@return: nothing
**/
void simu_bmp_maj(t_case* p)
{
	//si on a des habitants :
	if(p->habit_nbr)
	{
		//si on a pas de bâtiments
		if(p->build_img < 0)
		{
			//TODO switch des chantiers (au hasard)
			p->y_build = p->habit_nbr+1;
		}
		else
		{
			//si on a un batiment en construction
			if(p->y_build)
			{
				p->y_build--;
				//si on a fini de construire :
				if(!p->y_build)
				{
					//TODO choix de la bitmap à afficher pour le nombre d'habitats
				}
			}
			else
			{
				//si le bâtiment est trop petit
				if(p->habit_nbr > p->build_size)
				{
					//on vérifi si on agrandi le batiment (une chance sur 3
					if(rand()%3 == 0)
					{
						//TODO switch des chantiers
						p->y_build = p->habit_nbr+1;
					}
				}
			}
		}
	}
}
