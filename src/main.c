#include "main.h"

int main(int argc, char *argv[])
{
	int menu;

	//Allegro init
	alleg_init();

	//lancement du menu principal :
	menu = menu_main();
	if(menu == GAME) game();
	return 0;
}
END_OF_MAIN();
