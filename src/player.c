#include "main.h"
#include "player.h"

///макросы установки состояний игрока

#define TURN_FROM_DOWN_TO_LEFT	{p->sprite->h_flip = 1; p->sprite->i_anim = 5; p->sprite->i_frame = 0; p->state = ps_turn_from_front;}
#define TURN_FROM_DOWN_TO_RIGHT	{p->sprite->h_flip = 0; p->sprite->i_anim = 5; p->sprite->i_frame = 0; p->state = ps_turn_from_front;}
#define TURN_FROM_UP_TO_LEFT	{p->sprite->h_flip = 1; p->sprite->i_anim = 3; p->sprite->i_frame = 0; p->state = ps_turn_from_back;}
#define TURN_FROM_UP_TO_RIGHT	{p->sprite->h_flip = 0; p->sprite->i_anim = 3; p->sprite->i_frame = 0; p->state = ps_turn_from_back;}

#define TURN_FROM_LEFT_TO_UP	{p->sprite->h_flip = 1; p->sprite->i_anim = 4; p->sprite->i_frame = 0; p->state = ps_turn_to_back;}
#define TURN_FROM_LEFT_TO_DOWN	{p->sprite->h_flip = 1; p->sprite->i_anim = 6; p->sprite->i_frame = 0; p->state = ps_turn_to_front;}
#define TURN_FROM_RIGHT_TO_UP	{p->sprite->h_flip = 0; p->sprite->i_anim = 4; p->sprite->i_frame = 0; p->state = ps_turn_to_back;}
#define TURN_FROM_RIGHT_TO_DOWN	{p->sprite->h_flip = 0; p->sprite->i_anim = 6; p->sprite->i_frame = 0; p->state = ps_turn_to_front;}

#define GO_UP_AFTER_TURN		{p->sprite->h_flip = 0; p->sprite->i_anim = 0; p->sprite->i_frame = 0; p->state = ps_go_up;}
#define GO_DOWN_AFTER_TURN		{p->sprite->h_flip = 0; p->sprite->i_anim = 1; p->sprite->i_frame = 0; p->state = ps_go_down;}
#define GO_RIGHT_AFTER_TURN		{p->sprite->h_flip = 0; p->sprite->i_anim = 2; p->sprite->i_frame = 0; p->state = ps_go_right;}
#define GO_LEFT_AFTER_TURN		{p->sprite->h_flip = 1; p->sprite->i_anim = 2; p->sprite->i_frame = 0; p->state = ps_go_left;}

#define FALL_FROM_DOWN			{p->sprite->h_flip = 0; p->sprite->i_anim = 8; p->sprite->i_frame = 0; p->state = ps_fall_back;}
#define FALL_FROM_UP			{p->sprite->h_flip = 0; p->sprite->i_anim = 7; p->sprite->i_frame = 0; p->state = ps_fall_front;}
#define FALL_FROM_LEFT			{p->sprite->h_flip = 1; p->sprite->i_anim = 9; p->sprite->i_frame = 0; p->state = ps_fall_side;}
#define FALL_FROM_RIGHT			{p->sprite->h_flip = 0; p->sprite->i_anim = 9; p->sprite->i_frame = 0; p->state = ps_fall_side;}

///функция установки состояний игрока (ссылка на игрока)
void set_player_state(t_player *p)
{
	if (p->state == ps_go_down){
		if ((p->event == pe_to_left) || (p->event == pe_to_top))
			TURN_FROM_DOWN_TO_LEFT
		else if (p->event == pe_to_right)
			TURN_FROM_DOWN_TO_RIGHT
		else if (p->event == pe_to_fall)
			FALL_FROM_DOWN
	}
	else if (p->state == ps_go_up){
		if (p->event == pe_to_left)
			TURN_FROM_UP_TO_LEFT
		else if ((p->event == pe_to_right) || (p->event == pe_to_down))
			TURN_FROM_UP_TO_RIGHT
		else if (p->event == pe_to_fall)
			FALL_FROM_UP
	}
	else if (p->state == ps_go_left){
		if ((p->event == pe_to_top) || (p->event == pe_to_right))
			TURN_FROM_LEFT_TO_UP
		else if (p->event == pe_to_down)
			TURN_FROM_LEFT_TO_DOWN
		else if (p->event == pe_to_fall)
			FALL_FROM_LEFT
	}
	else if (p->state == ps_go_right){
		if (p->event == pe_to_top)
			TURN_FROM_RIGHT_TO_UP
		else if ((p->event == pe_to_down) || (p->event == pe_to_left))
			TURN_FROM_RIGHT_TO_DOWN
		else if (p->event == pe_to_fall)
			FALL_FROM_RIGHT
	}
	else if (p->state == ps_turn_to_back){
		if (p->event == pe_to_top)
			GO_UP_AFTER_TURN
		else if (p->event == pe_to_right)
			TURN_FROM_UP_TO_RIGHT
	}
	else if (p->state == ps_turn_to_front){
		if (p->event == pe_to_down)
			GO_DOWN_AFTER_TURN
		else if (p->event == pe_to_left)
			TURN_FROM_DOWN_TO_LEFT
	}
	else if (p->state == ps_turn_from_front){
		if (p->event == pe_to_right)
			GO_RIGHT_AFTER_TURN
		else if (p->event == pe_to_left)
			GO_LEFT_AFTER_TURN
		else if (p->event == pe_to_top)
			TURN_FROM_LEFT_TO_UP
	}
	else if (p->state == ps_turn_from_back){
		if (p->event == pe_to_right)
			GO_RIGHT_AFTER_TURN
		else if (p->event == pe_to_left)
			GO_LEFT_AFTER_TURN
		else if (p->event == pe_to_down)
		TURN_FROM_RIGHT_TO_DOWN
	}
	else if ((p->state == ps_fall_back) || (p->state == ps_fall_front) || (p->state == ps_fall_side))
	{
		p->event = pe_to_down;
		GO_DOWN_AFTER_TURN
	}
}

///функция опроса джойстика1 и установки намерений игрока1 и определение нового направления и позиции
/// возвращает код нажатой кнопки для проверки на выход из функции dummy() (game.c)
u16 player1_input()
{
	u16 joy_state = JOY_readJoypad(JOY_1);

	g_game.player1.direct.x = 0;
	g_game.player1.direct.y = 0;

	if (((joy_state & BUTTON_UP) == BUTTON_UP) && (g_game.player1.pos.y > 24))
	{
		g_game.player1.event = pe_to_top;
		g_game.player1.direct.y = -1;
	}
	else if (((joy_state & BUTTON_DOWN) == BUTTON_DOWN) && (g_game.player1.pos.y < 200))
	{
		g_game.player1.event = pe_to_down;
		g_game.player1.direct.y = 1;
	}

	if (((joy_state & BUTTON_LEFT) == BUTTON_LEFT) && (g_game.player1.pos.x > 0))
	{
		g_game.player1.event = pe_to_left;
		g_game.player1.direct.x = -1;
	}
	else if (((joy_state & BUTTON_RIGHT) == BUTTON_RIGHT) && (g_game.player1.pos.x < 240))
	{
		g_game.player1.event = pe_to_right;
		g_game.player1.direct.x = 1;
	}
	else if ((joy_state & BUTTON_A) == BUTTON_A)
	{
		g_game.player1.event = pe_to_fall;
	}
	else if ((joy_state & BUTTON_B) == BUTTON_B)
	{
		g_game.player1.delay_frame++;
		if (g_game.player1.delay_frame > 100) g_game.player1.delay_frame = 100;
	}
	else if ((joy_state & BUTTON_C) == BUTTON_C)
	{
		g_game.player1.delay_frame--;
		if (g_game.player1.delay_frame < 5) g_game.player1.delay_frame = 5;
	}
	if ((g_game.player1.state != ps_fall_back) && (g_game.player1.state != ps_fall_front)&& (g_game.player1.state != ps_fall_side))
	{
		g_game.player1.pos.x += g_game.player1.direct.x;
		g_game.player1.pos.y += g_game.player1.direct.y;
	}
	return (joy_state);
}
