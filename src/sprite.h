#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

///structure of sprite frames
typedef struct
{
	u8					anim_index;		///animation index in SpriteDefinition
	u8					frame_index;	///frame index in SpriteDefinition
	s8					delay;			///delay in frames
	Vect2D_s16			delta_pos;		///offset sprite
	u8					h_flip;			///flip sprite on horizontal
}						t_frame;

///structure of sprite animations
typedef struct
{
	t_frame				*frame;
	u8					frames_count;
}						t_anim;

///структура объектов-спрайтов игры для добавления в список объектов
///(объекты формируют очередь объектов для правильного порядка отображения
///спрайтов в зависимости от их положения по оси Y)
///(позиция, направление движения, квадрат карты, следующий номер спрайта (0 для последнего),
/// приоритет отображения(от 0 до 80 чем меньше тем ближе к наблюдателю))
typedef struct
{
	Vect2D_s16	pos;
	Vect2D_s16	direct;
	Vect2D_u16	map_pos;
	u8			link;
	u16			priority;
}	t_object;

///structure for sprites
typedef struct
{
	SpriteDefinition	*sprite_def;
	u16					tile_index;
	u8					pal_index;
	u8					h_flip;
	u8					cur_flip;
	u8					width;
	u8					height;
	u16					i_time;
	u8					delay;
	t_anim				*anim;
	u8					anims_count;
	u8					i_anim;
	u8					cur_anim;
	u8					i_frame;
	u8					cur_frame;
	u16					index;

}						t_sprite;

#endif // SPRITE_H_INCLUDED
