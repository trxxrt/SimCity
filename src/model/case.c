#include "case.h"

t_case **init_tabCases()
{
	t_case ** tab;
	int i, j;
	tab=malloc(size_map*sizeof(t_case *));
	for (i=0; i<size_map; i++)
		tab[i]=malloc(size_map*sizeof(t_case));

	for(i=0; i<size_map; i++)
	{
		for(j=0; j<size_map; j++)
		{
			if(i==0 || j==0 || i== size_map-1 || j == size_map-1)
			{
				tab[i][j].state0=SEA;
				tab[i][j].state1=SEA;
				tab[i][j].state2=SEA;
			}
			else
			{
				tab[i][j].state0=GROUND;
				tab[i][j].state1=ELECTRIC;
				tab[i][j].state2=GROUND;
			}

			//mise à 0 de toutes la variables :
			tab[i][j].state0_m = 0;
			tab[i][j].state1_m = 0;
			tab[i][j].state2_m = 0;
			tab[i][j].habit_nbr = 0;
			tab[i][j].y_build = 0;
			tab[i][j].water = 0;
			tab[i][j].elec = 0;
			tab[i][j].road = 0;
			tab[i][j].build_size = 0;
			tab[i][j].build_img = 0;
		}
	}

	return tab;
}
