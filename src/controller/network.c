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

	//parcourt tu tableau de cases :
	for(i=0; i<size_map; i++)
		for(j=0; j<size_map; j++)
		{
			if((t==NET_ROAD)&&(tab[i][j].state0==ROAD)&&(tab[i][j].state0_m==0))
				net_run(tab, t, i, j);
			else if((t==NET_WATER)&&(tab[i][j].state0==WATER)&&(tab[i][j].state2_m==0))
				net_run(tab, t, i, j);
			else if((t==NET_ELEC)&&(tab[i][j].state0==POWER_PLANT)&&(tab[i][j].state1_m==0))
				net_run(tab, t, i, j);
		}
	
}


/**
 *	fonction de parcourt d'un réseau :

 *	@param: - tab -> tableau de cases de la map à parcourir
 *		- t -> type du réseau à parcourir
 *		- x,y -> coordonnées du point de départ

 *	@return: nothing
**/
void net_run(t_case** tab, int t, int x, int y)
{
	//ressources
	int inf = 50000;
	int *c;
	File* f1;

	//initialisation :
	net_marq(&tab[x][y], t);

	if(t==NET_ROAD)
		c = &inf;
	else if((t==NET_WATER) || (t==NET_ELEC))
		c = &tab[x][y].build_size;

	if(t==NET_ROAD)
		net_adj_run(tab, t, x, y, &inf);

	//allocation de la file :
	f1 = creerFile(500);
	
	//push des voisins non marqué dans la liste :
	if(net_is_marq(&tab[x+1][y], t))
		enfiler(f1, net_pos_alloc(x+1, y));
	if(net_is_marq(&tab[x][y+1], t))
		enfiler(f1, net_pos_alloc(x, y+1));
	if(net_is_marq(&tab[x-1][y], t))
		enfiler(f1, net_pos_alloc(x-1, y));
	if(net_is_marq(&tab[x][y-1], t))
		enfiler(f1, net_pos_alloc(x, y-1));

	//parcourt du tableau 
	while(!fileVide(f1))
	{
		t_net_pos* temp = NULL;
		File* f2 = creerFile(500);

		while(defiler(f1, (void**)&temp))
		{
			//marquer la case et les cases adjascentes :
			net_marq(&tab[temp->x][temp->y], t);
			net_adj_run(tab, t, temp->x, temp->y, c);

			if(net_is_marq(&tab[temp->x+1][temp->y], t))
				enfiler(f2, net_pos_alloc(temp->x+1, temp->y));
			if(net_is_marq(&tab[temp->x][temp->y+1], t))
				enfiler(f2, net_pos_alloc(temp->x, temp->y+1));
			if(net_is_marq(&tab[temp->x-1][temp->y], t))
				enfiler(f2, net_pos_alloc(temp->x-1, temp->y));
			if(net_is_marq(&tab[temp->x][temp->y-1], t))
				enfiler(f2, net_pos_alloc(temp->x, temp->y-1));
		}

		detruireFile(f1);
		f1 = f2;
	}

		
}


/**
 * 	fonction de marquage des cases adjascentes

 * 	@param: - tab -> tableau de cases à parcourir
 *		- t -> type de réseau à parcourir
 *		- x -> position en x dans le tableau de la case de laquelle partir
 *		- y -> position en y dans le tableau de la case de laquelle partir
 *		- c -> pointeur sur le compteur de la centrale que l'on teste (pointeur vers une variable inutile avec un nombre infinit pour le réseau routier)

 *	@return: nothing
**/
void net_adj_run(t_case** tab, int t, int x, int y, int* c)
{
	//ressources
	int i, j, k, compteur;
	int right = 1;

	//maj du compteur
	if(t==NET_ROAD)
		compteur = 2;
	else if(t==NET_WATER)
		compteur = 4;
	else
		compteur = 3;

	//marquage de la case :
	if(tab[x][y].state0 == CONSTRUCT)
	{
		*c -= tab[x][y].habit_nbr;
		if(*c < 0)
			*c = 0;
		else
		{
			if(t==NET_WATER)
				tab[x][y].water = 1;
			else if(t==NET_ELEC)
				tab[x][y].elec = 1;
		}
	}

	//parcourt des cases adjascentes
	for(i = 1; i < compteur; i++)
	{
		k = 1;
		for(j=0; j<2; j++)
		{
			//si on a le droit d'y aller :
			if((x+k*i > 0) && (x+k*i < size_map))
			{
				right = 1;
				if(t==NET_ROAD && tab[x+i*k][y].road==1)
					right = 0;
				else if(t==NET_WATER && tab[x+i*k][y].water==1)
					right = 0;
				else if(t==NET_ELEC && tab[x+i*k][y].elec==1)
					right = 0;

				//on test le marquage de la case :
				if((tab[x+k*i][y].state0 == CONSTRUCT)&&right)
				{
					*c -= tab[x+k*i][y].habit_nbr;
					if(*c < 0)
						*c = 0;
					else
					{
						if(t==NET_ROAD)
							tab[x+k*i][y].road = 1;
						else if(t==NET_WATER)
							tab[x+k*i][y].water = 1;
						else
							tab[x+k*i][y].elec = 1;
					}
				}
			}
			//comme ci-dessus avec les y :
			if((y+k*i > 0) && (y+k*i < size_map))
			{
				right = 1;
				if(t==NET_ROAD && tab[x][y+i*k].road==1)
					right = 0;
				else if(t==NET_WATER && tab[x][y+i*k].water==1)
					right = 0;
				else if(t==NET_ELEC && tab[x][y+i*k].elec==1)
					right = 0;

				if((tab[x][y+i*k].state0 == CONSTRUCT)&&right)
				{
					*c -= tab[x][y+i*k].habit_nbr;
					if(*c < 0)
						*c = 0;
					else
					{
						if(t==NET_ROAD)
							tab[x][y+i*k].road = 1;
						else if(t==NET_WATER)
							tab[x][y+i*k].water = 1;
						else if(t==NET_ELEC)
							tab[x][y+i*k].elec = 1;
					}
				}
			}
			k = k * -1;
		}
	}
	
}


/**
 * 	fonction de marquage de passage sur la case demandée

 *	@param: - p -> pointeur sur la case à marquer
 *		- t -> type à marquer

 *	@return: nothing
**/
void net_marq(t_case* p, int t)
{
	if(t==NET_ROAD)
		p->state0_m = 1;
	else if(t==NET_WATER)
		p->state2_m = 1;
	else if(t==NET_ELEC)
		p->state1_m = 1;
}


/**
 *	fonction retournant si la case contient un type demandé non marqué

 * 	@param: - p -> case à vérifier
 *		- t -> type à vérifier

 *	@return: 1 si il y a le type demandé non marqué, 0 si non
**/
int net_is_marq(t_case* p, int t)
{
	//ressources
	int ret = 0;

	//tests :
	if((t==NET_ROAD) && (p->state0==ROAD))
	{
		if(p->state0_m == 0)
			ret = 1;
	}
	else if((t==NET_WATER) && (p->state2==CONDUCT))
	{
		if(p->state2_m == 0)
			ret = 1;
	}
	else if((t==NET_ELEC) && (p->state1==ELECTRIC))
	{
		if(p->state1_m == 0)
			ret = 1;
	}

	return ret;
}
		

/**
 *	fonction d'allocation d'un t_net_pos

 * 	@param: - x et y -> coordonnées à ajouter

 *	@return: adresse d'un truc alloué
**/
t_net_pos* net_pos_alloc(int x, int y)
{
	//ressources
	t_net_pos* p = NULL;

	//allocation et remplissage :
	p = (t_net_pos*)malloc(sizeof(t_net_pos));
	if(!p){
		perror("***ERREUR*** lors de l'allocation d'un t_net_pos ");
		exit(EXIT_FAILURE);}

	p->x = x;
	p->y = y;

	return p;
}
