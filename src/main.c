#include "main.h"

t_game	g_game;			///���������� ������

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


