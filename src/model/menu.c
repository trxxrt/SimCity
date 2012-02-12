#include "menu.h"

t_menu * initi_menu()
{
	t_menu * menu = (t_menu *) malloc(sizeof(t_menu));
	menu->last_choice=MENU_NULL;
	menu->img=load_bitmap_check("res/game/menu.bmp");
	return menu;
}

int is_active_menu(t_menu * menu)
{
	//test en fonction de la position de la souris
	if(mouse_y<40) return 1;
	else return 0;
}

void click_menu(t_menu * menu)
{
	int x = mouse_x;
	 //test en fonction du clic
	if(is_active_menu(menu))
	{
		//Constructions
		if (x<40) menu->last_choice=MENU_ROAD;
		else if(x<80) menu->last_choice=MENU_B_AREA;
		else if(x<120) menu->last_choice=MENU_WATER;
		else if (x<160) menu->last_choice=MENU_POWER_PLANT;
		else if (x<200) menu->last_choice=MENU_CONDUCT;
		else if (x<240) menu->last_choice=MENU_ELECTRIC;

		//Pause/Play
		else if (x<720 && x>640)
		{
			menu->last_choice=MENU_NULL;
			///fonction de changement de mode de jeu
		}
		//Pause/Resume
		else if (x>760)
		{
			menu->last_choice=MENU_NULL;
			///fonction de pause/resume
		}
	}
	printf("clicked MENU : button %d\n",menu->last_choice);
}

void display_menu(BITMAP * buffer, t_menu * menu)
{
	if (is_active_menu(menu))
		draw_sprite(buffer, menu->img,0,0);
}
