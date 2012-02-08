#include "button.h"

/**
 * FONCTION DE CRÉATION D'UN BOUTTON
 * @param img_off->nom de l'image lorsque le boutton est relaché
 * @param img_on->nom de l'image lorsque le boutton est enfoncé
 * @return retour : boutton créé
*/
t_button* button_create(char* img_off, char* img_on, int w, int h)
{
	// 0. déclaration des ressources
	t_button* b = NULL;

	// 1. allocation dynamique du boutton ;
	b = (t_button*)malloc(sizeof(t_button));
	if(!b){
		printf("***ERREUR*** lors de l'allocation du boutton ");
		exit(EXIT_FAILURE);}

	// 2. chargement des images :
	b->img_off = load_bitmap_check(img_off);
	b->img_on = load_bitmap_check(img_on);

	// 3. mise à jour de la position du boutton :
	b->w = w;
	b->h = h;

	// 4. mise à 0 de la marque du boutton :
	b->is_clicked = 0;
	b->is_on = 0;

	// 5. retour de la structure ainsi créé:
	return b;
}

/**
 * FONCTION DE MISE À JOUR DU BOUTTON
 * @param b boutton que l'on souhaite mettre à jour
 * @return void
*/
void button_maj(t_button* b)
{
	// 1. test si la souris est sur le boutton :
	if((((mouse_pos >> 16)*BMP_W/SCREEN_W) > b->w) && (((mouse_pos >> 16)*BMP_W/SCREEN_W) < (b->w + b->img_off->w)) && (((mouse_pos & 0x0000ffff)*BMP_H/SCREEN_H) > b->h) && (((mouse_pos & 0x0000ffff)*BMP_H/SCREEN_H) < (b->w + b->img_off->h)))
	{
		// 1.1 si oui, on actualise, on met le boutton à "is_on"
		b->is_on = 1;

		// 1.3 on test si le boutton a été clické :
		if(mouse_b & 1) b->is_clicked = 1;
	}
	else
		b->is_on = 0;
}


//fonction d'affichage du boutton
void button_blit(t_button* b, BITMAP* m)
{
	//si la souris est sur le boutton :
	if(b->is_on)
		draw_sprite(m, b->img_on, b->w, b->h);
	else
		draw_sprite(m, b->img_off, b->w, b->h);

}

//fonction de vérification si le boutton a été cliqué :
int button_is_clicked(t_button* b)
{
	return b->is_clicked;
}

//fonction de destruction d'un boutton
void button_destroy(t_button* b)
{
	//destruction des images :
	destroy_bitmap(b->img_off);
	destroy_bitmap(b->img_on);

	//destruction de la structure en elle même :
	free(b);
}
