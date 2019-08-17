#include "main.h"

t_game	g_game;			///глобальный объект

int		main()
{
	reset_score();
	while (TRUE)
	{
		//show_intro();
		//menu();
		game();
		set_score();
	}
    return (0);
}


