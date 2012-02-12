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
	MIDI * music = NULL;
	pthread_t thread_scroll;
	pthread_t thread_floor;
	pthread_t thread_action;
	pthread_t thread_check_end_of_game;
	pthread_t thread_zoom;
	pthread_t thread_map;
	pthread_t thread_update_camera;
	pthread_t thread_music;
	pthread_t thread_simu;

	// 1. initialisation des variables de jeu
	end_of_game = 0;
	size_map = SIZE_OF_MAP;
	menu = initi_menu();
	end_of_game = 0;
	game.nb_habitant = 0;
	game.temps = 0;
	game.menu = menu;
	camera = init_scroll();
	game.camera = camera;
	buffer = create_bitmap(SCREEN_W, SCREEN_H);
	game.buffer = buffer;
	tiles = load_tiles();
	game.tiles = tiles;
	tab = init_tabCases();
	game.tab = tab;
	music = load_midi("res/music/1.mid");
	play_looped_midi(music, 0, -1);

	// 2 initialisation des threads d'écoute
	pthread_create(&thread_scroll, NULL, scrolling, (void*)camera);
	pthread_create(&thread_zoom, NULL, zoom, (void*)camera);
	pthread_create(&thread_floor, NULL, floor_c, (void*)camera);
	pthread_create(&thread_action, NULL, action, (void*)&game);
	pthread_create(&thread_map, NULL, print_map, (void*)&game);
	pthread_create(&thread_update_camera, NULL, update_camera, (void*)camera);
	pthread_create(&thread_music, NULL, gest_music, (void*)music);
	pthread_create(&thread_check_end_of_game, NULL, check_end_of_game, (void*)&game);
	pthread_create(&thread_simu, NULL, simu_all, (void*)&game);

	// 3. initialisation du temps
	temps = time(NULL);

	// 4. attente de la fin de jeu
	end = pthread_join(thread_map, &temp);

	// 5. suppression des threads résiduels éventuels
	pthread_cancel(thread_action);
	pthread_cancel(thread_music);
	pthread_cancel(thread_update_camera);
	pthread_cancel(thread_floor);
	pthread_cancel(thread_scroll);
	pthread_cancel(thread_zoom);
	pthread_cancel(thread_map);
	pthread_cancel(thread_simu);
}
