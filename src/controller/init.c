#include "init.h"

void alleg_init(void)
{
	FILE* config = NULL;
	int full, w, h, i;

	config = fopen("configuration.cfg", "r");
	if(config)
	{
		i = fscanf(config, "%d %d %d", &full, &w, &h);
		if(i != 3){
			perror("***ERREUR*** : lors de la lecture des configs dans le fichier\nAbandon...");
			exit(EXIT_FAILURE);}
		if(!full) full = GFX_AUTODETECT_WINDOWED;
		else full = GFX_AUTODETECT_FULLSCREEN;
		screen_width = w;
		screen_height = h;
	}
	else
	{
		printf("***ERREUR*** : lors de l'ouverture du fichier de config\nChargement de valeurs par défaut");
		full = GFX_AUTODETECT_WINDOWED;
		screen_width = 800;
		screen_height = 600;
	}

	printf("INITIALISATION ALLEGRO\n");
	printf("----------------------------------\n");

	printf("  allegro global init........");
	if(!allegro_init()) printf(" OK\n");
	else { printf("FAIL\n"); allegro_exit(); exit(EXIT_FAILURE); }

	printf("  keyboard init..............");
	if(install_keyboard() == 0) printf(" OK\n");
	else { printf("FAIL\n"); allegro_exit(); exit(EXIT_FAILURE); }

	printf("  mouse init.................");
	if(install_mouse() != -1) printf(" OK\n");
	else { printf("FAIL\n"); allegro_exit(); exit(EXIT_FAILURE); }

	printf("  encoding...................");
	set_uformat(U_UTF8); printf(" OK\n");

	printf("  sound init.................");
	if(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) == 0) printf(" OK\n");
	else { printf("FAIL\n"); allegro_exit(); exit(EXIT_FAILURE); }

	printf("  color depth................");
	set_color_depth(desktop_color_depth());
	printf(" OK\n");

	printf("  gfx mode windowed..........");
	if (set_gfx_mode(full, w, h, 0, 0) == 0) printf(" OK\n");
	else { printf("FAIL\n"); allegro_exit(); exit(EXIT_FAILURE); }

	printf("  window title...............");
	set_window_title("SimCity");
	printf(" OK\n");

	printf("  mouse on screen............");
	show_mouse(screen);
	enable_hardware_cursor();
	printf(" OK\n");

	printf("----------------------------------\n");

	printf("\nAUTRES INITIALISATIONS\n");
	printf("----------------------------------\n");

	printf("  random.....................");
	srand(time(NULL));
	printf(" OK\n");

	printf("----------------------------------\n");

	printf("\n\n");
}
