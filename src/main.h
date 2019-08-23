#ifndef MAIN_H_INCLUDED
# define MAIN_H_INCLUDED

# define TRUE 1
# define FALSE 0

# include <genesis.h>
# include "libfont.h"
# include "sprite.h"
# include "player.h"
# include "enemy.h"
# include "map.h"



///структура глобального игрового объекта (игрок1, игрок2, враги, таблица лидеров, список объектов, количество объектов
typedef struct
{
	t_player			player1;
	t_player			player2;
	t_enemy				**enemies;
	u16					enem_count;
	t_score				score_table[5];
	t_object			**objects;
	u16					objects_count;
}						t_game;

extern t_game			g_game;							///description in main.c
extern t_map			g_map[15][11];					///description in main.c

void    show_intro(void);								///description in show_intro.c
void	menu(void);										///description in menu.c
void    game(void);										///description in game.c
void	set_score(void);								///description in show_intro.c
void	reset_score(void);								///description in show_intro.c
void	create_player1(void); 							///description in create_player.c
void	clear_player1(void);							///description in create_player.c
void	create_player2(void); 							///description in create_player.c
void	player_sprite_draw(t_player *player);			///description in sprite.c
void	print(char *txt, int n, u16 x, u16 y, u8 len);	///description in tools.c
void	set_player_state(t_player *p);					///description in player.c
u16		player1_input(void);							///description in player.c
void	load_map(u8 stage);								///description in map.c
void	object_list_init();								///description in sprite.c
void	add_object_to_list(t_object *object);			///description in sprite.c
void	sort_object_priority();							///description in sprite.c
#endif // MAIN_H_INCLUDED
