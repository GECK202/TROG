#ifndef MAIN_H_INCLUDED
# define MAIN_H_INCLUDED

# define TRUE 1
# define FALSE 0

# include <genesis.h>
# include "libfont.h"

///structure for save score
typedef struct	s_score
{
	char		name[3];
	u32			score;
}				t_score;

///structure for player
typedef struct	s_player
{
	t_score		score;
}				t_player;

///global game structure
typedef struct	s_game
{
	t_player	player1;
	t_player	player2;
	t_score		score_table[5];
}				t_game;

extern t_game	g_game;			///description in main.c

void    show_intro(void);			///description in show_intro.c
void	menu(void);					///description in menu.c
void    game(void);					///description in game.c
void	set_score(void);			///description in show_intro.c
void	reset_score(void);			///description in show_intro.c

#endif // MAIN_H_INCLUDED
