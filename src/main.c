#include "main.h"

t_game	g_game;			///глобальный объект
t_map	g_map[15][11];	///глобальная карта уровня

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


