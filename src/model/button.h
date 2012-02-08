#ifndef BUTTON_INCL_H
#define BUTTON_INCL_H

#include <allegro.h>
#include <stdio.h>
#include "../shared/tools.h"

#define BMP_H 900
#define BMP_W 1440

typedef struct button
{
	BITMAP* img_off;
	BITMAP* img_on;
	int w, h;
	int is_on;
	int is_clicked;
}t_button;


t_button* button_create(char* img_off, char* img_on, int w, int h);
void button_maj(t_button* b);
////////////////////////////////////

////////////////////////////////////
//	FONCTION D'AFFICHAGE DU BOUTTON
//	param : - b->boutton à afficher
//		- m->bitmap où afficher le boutton
//	retour : .
void button_blit(t_button* b, BITMAP* m);
///////////////////////////////////

///////////////////////////////////
//	FONCTION DE VÉRIFICATION SI LE BOUTTON A ÉTÉ CLIQUÉ
//	param : - b->boutton à vérifier
//	retour : 1 si le boutton a été cliqué 0 si non
int button_is_clicked(t_button* b);
///////////////////////////////////

///////////////////////////////////
//	FONCTION DE DESTRUCTION D'UN BOUTTON
//	param : b->boutton à détruire
//	retour : .
void button_destroy(t_button* b);
///////////////////////////////////

#endif
