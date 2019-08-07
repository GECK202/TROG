#ifndef MAIN_H_INCLUDED
# define MAIN_H_INCLUDED

# define TRUE 1
# define FALSE 0

# include <genesis.h>
# include "libfont.h"

///structure for save score
typedef struct
{
	char		name[3];
	u32			score;
}				t_score;

//enum pl_status
//{
//	protect, ready, die
//};

///structure for player
typedef struct
{
	Vect2D_s16	pos;
	Vect2D_s16	direct;
	t_score		score;
	Sprite		*sprite;
	const u16	*palette;
	u16			num_pal;
	s16			cur_anim;
//	pl_status	status;
}				t_player;

//enum en_status
//{
//	ready, freezy, stay
//};

typedef struct
{
	Vect2D_s16	pos;
	Vect2D_s16	direct;
	u8			type;
	Sprite		*sprite;
	const u16	*palette;
	u16			num_pal;
//	en_status	status;
}				t_enemy;

///global game structure
typedef struct
{
	t_player	player1;
	t_player	player2;
	t_enemy		*enemies;
	t_score		score_table[5];
}				t_game;

extern t_game	g_game;			///description in main.c

void    show_intro(void);			///description in show_intro.c
void	menu(void);					///description in menu.c
void    game(void);					///description in game.c
void	set_score(void);			///description in show_intro.c
void	reset_score(void);			///description in show_intro.c

#endif // MAIN_H_INCLUDED
