#include "game.h"

void start_game()
{
	// 0. déclaration des variables de jeu
	t_game game;
	int end = 0;
	void* temp;
	time_t temps = 0;
	t_tiles * tiles = NULL;
	BITMAP * buffer = NULL;
	t_case **tab = NULL;
	t_scroll * camera = NULL;
	t_menu * menu = NULL;
	pthread_t thread_scroll;
	pthread_t thread_floor;
	pthread_t thread_action;
	pthread_t thread_zoom;
	pthread_t thread_map;
	pthread_t thread_update_camera;

	// 1. initialisation des variables de jeu
	size_map = 15;
	menu = initi_menu();
	game.menu = menu;
	camera = init_scroll();
	game.camera = camera;
	buffer = create_bitmap(SCREEN_W, SCREEN_H);
	game.buffer = buffer;
	tiles = load_tiles();
	game.tiles = tiles;
	tab = init_tabCases();
	game.tab = tab;

	// 2 initialisation des threads d'écoute
	pthread_create(&thread_scroll, NULL, scrolling, (void*)camera);
	pthread_create(&thread_zoom, NULL, zoom, (void*)camera);
	pthread_create(&thread_floor, NULL, floor_c, (void*)camera);
	pthread_create(&thread_action, NULL, action, (void*)&game);
	pthread_create(&thread_map, NULL, print_map, (void*)&game);
	pthread_create(&thread_update_camera, NULL, update_camera, (void*)camera);

	// 3. initialisation du temps
	temps = time(NULL);

	// 4. attente de la fin de jeu
	end = pthread_join(thread_map, &temp);

	// 5. suppression des threads résiduels éventuels
	pthread_cancel(thread_action);
	pthread_cancel(thread_update_camera);
	pthread_cancel(thread_floor);
	pthread_cancel(thread_scroll);
	pthread_cancel(thread_zoom);
	pthread_cancel(thread_map);
}
