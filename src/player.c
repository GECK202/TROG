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

#define FALL_FROM_DOWN			{p->sprite->h_flip = 0; p->sprite->i_anim = 8; p->sprite->i_frame = 0; p->state = ps_fall_back; p->intent = pi_to_down;}
#define FALL_FROM_UP			{p->sprite->h_flip = 0; p->sprite->i_anim = 7; p->sprite->i_frame = 0; p->state = ps_fall_front; p->intent = pi_to_top;}
#define FALL_FROM_LEFT			{p->sprite->h_flip = 1; p->sprite->i_anim = 9; p->sprite->i_frame = 0; p->state = ps_fall_side; p->intent = pi_to_left;}
#define FALL_FROM_RIGHT			{p->sprite->h_flip = 0; p->sprite->i_anim = 9; p->sprite->i_frame = 0; p->state = ps_fall_side; p->intent = pi_to_right;}

///функция установки состояний игрока (ссылка на игрока)
void set_player_state(t_player *p)
{
	if (p->state == ps_go_down){
		if ((p->intent == pi_to_left) || (p->intent == pi_to_top))
			TURN_FROM_DOWN_TO_LEFT
		else if (p->intent == pi_to_right)
			TURN_FROM_DOWN_TO_RIGHT
		else if (p->intent == pi_to_fall)
			FALL_FROM_DOWN
	}
	else if (p->state == ps_go_up){
		if (p->intent == pi_to_left)
			TURN_FROM_UP_TO_LEFT
		else if ((p->intent == pi_to_right) || (p->intent == pi_to_down))
			TURN_FROM_UP_TO_RIGHT
		else if (p->intent == pi_to_fall)
			FALL_FROM_UP
	}
	else if (p->state == ps_go_left){
		if ((p->intent == pi_to_top) || (p->intent == pi_to_right))
			TURN_FROM_LEFT_TO_UP
		else if (p->intent == pi_to_down)
			TURN_FROM_LEFT_TO_DOWN
		else if (p->intent == pi_to_fall)
			FALL_FROM_LEFT
	}
	else if (p->state == ps_go_right){
		if (p->intent == pi_to_top)
			TURN_FROM_RIGHT_TO_UP
		else if ((p->intent == pi_to_down) || (p->intent == pi_to_left))
			TURN_FROM_RIGHT_TO_DOWN
		else if (p->intent == pi_to_fall)
			FALL_FROM_RIGHT
	}
	else if (p->state == ps_turn_to_back){
		if (p->intent == pi_to_top)
			GO_UP_AFTER_TURN
		else if (p->intent == pi_to_right)
			TURN_FROM_UP_TO_RIGHT
	}
	else if (p->state == ps_turn_to_front){
		if (p->intent == pi_to_down)
			GO_DOWN_AFTER_TURN
		else if (p->intent == pi_to_left)
			TURN_FROM_DOWN_TO_LEFT
	}
	else if (p->state == ps_turn_from_front){
		if (p->intent == pi_to_top)
			TURN_FROM_LEFT_TO_UP
		else if (p->intent == pi_to_right)
			GO_RIGHT_AFTER_TURN
		else //if (p->intent == pi_to_left)
			GO_LEFT_AFTER_TURN
	}
	else if (p->state == ps_turn_from_back){
		if (p->intent == pi_to_right)
			GO_RIGHT_AFTER_TURN
		else if (p->intent == pi_to_left)
			GO_LEFT_AFTER_TURN
		else if (p->intent == pi_to_down)
		TURN_FROM_RIGHT_TO_DOWN
	}
	else if ((p->state == ps_fall_back) || (p->state == ps_fall_front) || (p->state == ps_fall_side))
	{
		if (p->intent = pi_to_left)
			GO_LEFT_AFTER_TURN
		else if(p->intent = pi_to_right)
			GO_RIGHT_AFTER_TURN
		else if(p->intent = pi_to_top)
			GO_UP_AFTER_TURN
		else
			GO_DOWN_AFTER_TURN

	}
}

///функция опроса джойстика1 и установки намерений игрока1 и определение нового направления и позиции
/// возвращает код нажатой кнопки для проверки на выход из функции dummy() (game.c)
u16 player_input(t_player *player, u16 joy_index)
{
	u16 joy_state = JOY_readJoypad(joy_index);
	s16 map_x;
	s16 map_y;
	s16 map_w;
	s16 map_h;
	Vect2D_s16 pos;
	Vect2D_s16 size;

	player->object.direct.x = 0;
	player->object.direct.y = 0;

	if (((joy_state & BUTTON_UP) == BUTTON_UP) && (player->object.pos.y > 40))
	{
		pos.x = player->object.pos.x;
		pos.y = player->object.pos.y - 17;
		map_x = (pos.x - 4) / 16;
		map_y = (pos.y - 44) / 16;
		map_w = (pos.x + 4) / 16;
		if ((g_map[map_x][map_y].go == 1) && (g_map[map_w][map_y].go == 1))
		{
			player->intent = pi_to_top;
			player->object.direct.y = -1;
		}
	}
	else if (((joy_state & BUTTON_DOWN) == BUTTON_DOWN) && (player->object.pos.y < 200))
	{
		pos.x = player->object.pos.x;
		pos.y = player->object.pos.y + 1;
		map_x = (pos.x - 4) / 16;
		map_y = (pos.y - 44) / 16;
		map_w = (pos.x + 4) / 16;
		if ((g_map[map_x][map_y].go == 1) && (g_map[map_w][map_y].go == 1))
		{
			player->intent = pi_to_down;
			player->object.direct.y = 1;
		}
	}

	else if (((joy_state & BUTTON_LEFT) == BUTTON_LEFT) && (player->object.pos.x > 0))
	{
		pos.x = player->object.pos.x - 1;
		pos.y = player->object.pos.y;
		map_x = (pos.x - 4) / 16;
		map_y = (pos.y - 44) / 16;
		map_h = (pos.y - 50) / 16;
		if ((g_map[map_x][map_y].go == 1) && (g_map[map_x][map_h].go == 1))
		{
			player->intent = pi_to_left;
			player->object.direct.x = -1;
		}
	}
	else if (((joy_state & BUTTON_RIGHT) == BUTTON_RIGHT) && (player->object.pos.x < 240))
	{
		pos.x = player->object.pos.x + 17;
		pos.y = player->object.pos.y;
		map_x = (pos.x - 4) / 16;
		map_y = (pos.y - 44) / 16;
		map_h = (pos.y - 50) / 16;
		if ((g_map[map_x][map_y].go == 1) && (g_map[map_x][map_h].go == 1))
		{
			player->intent = pi_to_right;
			player->object.direct.x = 1;
		}
	}
	else if ((joy_state & BUTTON_A) == BUTTON_A)
	{
		player->intent = pi_to_fall;
	}
	else if ((joy_state & BUTTON_B) == BUTTON_B)
	{
		player->delay_frame++;
		if (player->delay_frame > 100) player->delay_frame = 100;
	}
	else if ((joy_state & BUTTON_C) == BUTTON_C)
	{
		player->delay_frame--;
		if (player->delay_frame < 5) player->delay_frame = 5;
	}
	if ((player->state != ps_fall_back) && (player->state != ps_fall_front)&& (player->state != ps_fall_side))
	{
		player->object.pos.x += player->object.direct.x;
		player->object.pos.y += player->object.direct.y;
		player->object.map_pos.x = (player->object.pos.x - 4) / 16;
		player->object.map_pos.y = (player->object.pos.y - 50) / 16;

	}
	return (joy_state);
}
