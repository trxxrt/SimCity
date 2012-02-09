#include "click.h"

void info_click(t_case ** tab, BITMAP * buffer, t_scroll*camera)
{
	if(mouse_b&2)
	{
		char string [100];
		int x2d, y2d;
		float xx, yy;

		xx=mouse_x+camera->dx;
		yy=mouse_y+camera->dy;

		x2d=(yy / (64*camera->zoom) + xx / (128*camera->zoom));
		y2d=(yy / (64*camera->zoom) - xx / (128*camera->zoom));

		//Ecriture de la chaine de caractere
		if(tab[x2d][y2d].state0==0)
			sprintf(string, "Case : MER");
		else
		{
			if(tab[x2d][y2d].state0==GROUND)sprintf(string, "Case : VIDE  ");

			if(tab[x2d][y2d].state1!=GROUND) strcat(string,"Electricite presente   ");
			else strcat(string, "Electricite absente   ");

			if(tab[x2d][y2d].state2!=GROUND) strcat(string,"Eau courante presente");
			else strcat(string, "Eau courante absente");
		}

		textprintf_ex(buffer, font, 20, SCREEN_H-30, makecol(255,0,0), makecol(200,200,200), "%s", string);

	}
}
