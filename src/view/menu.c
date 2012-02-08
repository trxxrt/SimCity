#include "menu.h"

//fonction d'affichage du menu
int menu_main()
{
	// 0. déclaration des ressources
	BITMAP* back = NULL;
	BITMAP* buffer = NULL;
	t_button* game = NULL;
	t_button* quit = NULL;
	//t_button* options = NULL;
	int ret;

	// 1. chargement du fond :
	back = load_bitmap_check("res/menu/menu_fond.bmp");

	// 2. création de la bitmap générale :
	buffer = create_bitmap(back->w, back->h);

	// 3. création des bouttons :
	game = button_create("res/menu/b_main_jouer_off.bmp", "res/menu/b_main_jouer_on.bmp", 100, 100);
	quit = button_create("res/menu/b_main_quitter_off.bmp", "res/menu/b_main_quitter_on.bmp", 800, 600);
	//option = button_create_m("res/menu/b_main_options_off.bmp", "res/menu/b_main_options_on.bmp", 300, 500);

	// 4. lancement de la routine d'affichage :
	do {
		// 4.1 on met à jouer les bouttons 
		button_maj(game);
		button_maj(quit);
		//button_maj(options);

		// 4.2 on blit les images sur le buffer :
		blit(back, buffer, 0, 0, 0, 0, back->w, back->h);
		button_blit(game, buffer);
		button_blit(quit, buffer);

		// 4.3 on test si un des bouttons a été cliqué :
		ret = 0;
		if(button_is_clicked(game)) ret = GAME;
		if(button_is_clicked(quit)) ret = QUIT;
		//if(button_is_clicked(option)) option();

		// 4.4 on affiche le menu à l'écran :
		stretch_blit(buffer, screen, 0, 0, buffer->w, buffer->h, 0, 0, SCREEN_W, SCREEN_H);

	}while(ret == 0);

	// 5. on détruit les images :
	destroy_bitmap(back);
	destroy_bitmap(buffer);
	button_destroy(quit);
	button_destroy(game);

	// 6. on retourne la valeur de l'utilisateur
	return ret;
}
