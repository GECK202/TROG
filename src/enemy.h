#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

///������������ ��������� �����
typedef enum
{
	en_ready,
	en_freezy,
	en_stay
}						en_state;

///��������� ����� (�������, �����������, ���, ������, �������, ����� �������, ���������)
typedef struct
{
	t_object			object;
	Vect2D_s16			pos;
	Vect2D_s16			direct;
	u8					type;
	t_sprite			*sprite;
	const u16			*palette;
	u16					num_pal;
	en_state			state;
}						t_enemy;

#endif // ENEMY_H_INCLUDED
