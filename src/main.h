#ifndef MAIN_H_INCLUDED
# define MAIN_H_INCLUDED

# define TRUE 1
# define FALSE 0

# include <genesis.h>
# include "libfont.h"
# include "sprite.h"
# include "player.h"
# include "enemy.h"

///структура глобального игрового объекта (игрок1, игрок2, враги, таблица лидеров
typedef struct
{
	t_player			player1;
	t_player			player2;
	t_enemy				*enemies;
	t_score				score_table[5];
}						t_game;

extern t_game			g_game;							///description in main.c

void    show_intro(void);								///description in show_intro.c
void	menu(void);										///description in menu.c
void    game(void);										///description in game.c
void	set_score(void);								///description in show_intro.c
void	reset_score(void);								///description in show_intro.c
void	create_player1(void); 							///description in create_player.c
void	clear_player1(void);							///description in create_player.c
void	player_sprite_draw(t_player *player);			///description in sprite.c
void	print(char *txt, int n, u16 x, u16 y, u8 len);	///description in tools.c
void	set_player_state(t_player *p);					///description in player.c
u16		player1_input(void);							///description in player.c
#endif // MAIN_H_INCLUDED
