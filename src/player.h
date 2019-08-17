#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

///������������ ��������� player
typedef enum
{
	pe_to_top	= 1,
	pe_to_down	= 2,
	pe_to_left	= 3,
	pe_to_right	= 4,
	pe_to_fall	= 5
}				p_event;

///������������ ��������� player
typedef enum
{
	ps_protect			= 1,
	ps_ready			= 2,
	ps_die				= 3,
	ps_go_up			= 4,
	ps_go_left			= 5,
	ps_go_right			= 6,
	ps_go_down			= 7,
	ps_fall_back		= 8,
	ps_fall_front		= 9,
	ps_fall_side		= 10,
	ps_turn_to_front	= 11,
	ps_turn_from_front	= 12,
	ps_turn_to_back		= 13,
	ps_turn_from_back	= 14
}				p_state;

///��������� �������� ��������� (��� - 3 ������� � ���������� �����)
typedef struct
{
	char		name[3];
	u32			score;
}				t_score;

///��������� player (�������, �����������, �������, ������, �������, ������ �������,
///					 ���������, ���������, �������� �����(�/50 ��� �/60 �������))
typedef struct
{
	Vect2D_s16	pos;
	Vect2D_s16	direct;
	t_score		score;
	t_sprite	*sprite;
	const u16	*palette;
	u16			num_pal;
	p_state		state;
	p_event		event;
	u8			delay_frame;
}				t_player;

#endif // PLAYER_H_INCLUDED
