#include "game.h"

void game()
{
	// 0. déclaration des variables de jeu
	t_tiles * tiles = NULL;
	BITMAP * buffer = NULL;
	t_case **tab = NULL;
	t_scroll * camera = NULL;
	pthread_t thread_scroll;
	pthread_t thread_floor;
	pthread_t thread_action;
	pthread_t thread_zoom;

	// 1. initialisation des variables de jeu
	size_map = 15;
	camera = init_scroll();
   	buffer = create_bitmap(SCREEN_W, SCREEN_H);
	tiles = load_tiles();
	tab = init_tabCases();

	// 2 initialisation des threads d'écoute
	pthread_create(&thread_scroll, NULL, scrolling, (void*)camera);
	pthread_create(&thread_zoom, NULL, zoom, (void*)camera);
	pthread_create(&thread_floor, NULL, floor_c, (void*)camera);
	pthread_create(&thread_action, NULL, action, (void*)camera);

	// 3. boucle de jeu
	while(!key[KEY_ESC])
	{
		usleep(250);
		update_camera(camera);

		print_map(tab, buffer, camera, tiles);
	}

	pthread_cancel(thread_action);
	pthread_cancel(thread_floor);
	pthread_cancel(thread_scroll);
	pthread_cancel(thread_zoom);
}
