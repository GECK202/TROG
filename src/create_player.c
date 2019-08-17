#include "main.h"

void	player_sprite_create(t_player *player, SpriteDefinition *sprite_def, u16 tile_index, u8 pal_index);///создание игрока ( ссылка на игрока, ссылка на описание спрайта, позиция начала спрайта в видеопамяти, индекс палитры)
void	player_sprite_free(t_sprite *sprite);///удаление спрайта

///создание игрока1
void	create_player1(void)
{
	g_game.player1.pos.x = 1;
	g_game.player1.pos.y = 48;
	g_game.player1.state = ps_go_down;
	g_game.player1.event = pe_to_down;
	g_game.player1.delay_frame = 20;
	player_sprite_create(&g_game.player1, &hero_sprite, TILE_USERINDEX, PAL1);
}

///очистка игрока1
void	clear_player1(void)
{
	player_sprite_free(g_game.player1.sprite);
}

void	player_sprite_create(t_player *player, SpriteDefinition *sprite_def, u16 tile_index, u8 pal_index)
{
	t_sprite *sprite;
	player->sprite = MEM_alloc(sizeof(t_sprite));
	sprite = player->sprite;

	sprite->sprite_def = sprite_def;
	//print("F NUM=", sprite->sprite_def->animations[0]->frames[0]->, 32, 1, 2);
	sprite->anims_count = 5;
	sprite->tile_index = tile_index;
	sprite->pal_index = pal_index;
	sprite->h_flip = 0;
	sprite->cur_flip = 0;
	sprite->width = 2;
	sprite->height = 3;
	sprite->i_time = 0;
	sprite->delay = 100;
	sprite->i_anim = 1;
	sprite->cur_anim = 1;
	sprite->i_frame = 0;
	sprite->cur_frame = 0;
	sprite->anim = MEM_alloc(10 * sizeof(t_anim));

	///walk to up
	sprite->anim[0].frames_count = 4;
	sprite->anim[0].frame = MEM_alloc(4 * sizeof(t_frame));
		sprite->anim[0].frame[0].anim_index = 0;
		sprite->anim[0].frame[0].frame_index = 0;
		sprite->anim[0].frame[0].delta_pos.x = 0;
		sprite->anim[0].frame[0].delta_pos.y = 0;
		sprite->anim[0].frame[0].delay = 0;
		sprite->anim[0].frame[0].h_flip = 0;

		sprite->anim[0].frame[1].anim_index = 0;
		sprite->anim[0].frame[1].frame_index = 1;
		sprite->anim[0].frame[1].delta_pos.x = 0;
		sprite->anim[0].frame[1].delta_pos.y = 0;
		sprite->anim[0].frame[1].delay = 0;
		sprite->anim[0].frame[1].h_flip = 0;

		sprite->anim[0].frame[2].anim_index = 0;
		sprite->anim[0].frame[2].frame_index = 0;
		sprite->anim[0].frame[2].delta_pos.x = 0;
		sprite->anim[0].frame[2].delta_pos.y = 0;
		sprite->anim[0].frame[2].delay = 0;
		sprite->anim[0].frame[2].h_flip = 0;

		sprite->anim[0].frame[3].anim_index = 0;
		sprite->anim[0].frame[3].frame_index = 1;
		sprite->anim[0].frame[3].delta_pos.x = 0;
		sprite->anim[0].frame[3].delta_pos.y = 0;
		sprite->anim[0].frame[3].delay = 0;
		sprite->anim[0].frame[3].h_flip = 1;

	///walk to down
	sprite->anim[1].frames_count = 4;
	sprite->anim[1].frame = MEM_alloc(4 * sizeof(t_frame));
		sprite->anim[1].frame[0].anim_index = 1;
		sprite->anim[1].frame[0].frame_index = 0;
		sprite->anim[1].frame[0].delta_pos.x = 0;
		sprite->anim[1].frame[0].delta_pos.y = 0;
		sprite->anim[1].frame[0].delay = 0;
		sprite->anim[1].frame[0].h_flip = 0;

		sprite->anim[1].frame[1].anim_index = 1;
		sprite->anim[1].frame[1].frame_index = 1;
		sprite->anim[1].frame[1].delta_pos.x = 0;
		sprite->anim[1].frame[1].delta_pos.y = 0;
		sprite->anim[1].frame[1].delay = 0;
		sprite->anim[1].frame[1].h_flip = 0;

		sprite->anim[1].frame[2].anim_index = 1;
		sprite->anim[1].frame[2].frame_index = 0;
		sprite->anim[1].frame[2].delta_pos.x = 0;
		sprite->anim[1].frame[2].delta_pos.y = 0;
		sprite->anim[1].frame[2].delay = 0;
		sprite->anim[1].frame[2].h_flip = 0;

		sprite->anim[1].frame[3].anim_index = 1;
		sprite->anim[1].frame[3].frame_index = 1;
		sprite->anim[1].frame[3].delta_pos.x = 0;
		sprite->anim[1].frame[3].delta_pos.y = 0;
		sprite->anim[1].frame[3].delay = 0;
		sprite->anim[1].frame[3].h_flip = 1;

	///walk to right
	sprite->anim[2].frames_count = 4;
	sprite->anim[2].frame = MEM_alloc(4 * sizeof(t_frame));
		sprite->anim[2].frame[0].anim_index = 2;
		sprite->anim[2].frame[0].frame_index = 0;
		sprite->anim[2].frame[0].delta_pos.x = 0;
		sprite->anim[2].frame[0].delta_pos.y = 0;
		sprite->anim[2].frame[0].delay = 0;
		sprite->anim[2].frame[0].h_flip = 0;

		sprite->anim[2].frame[1].anim_index = 2;
		sprite->anim[2].frame[1].frame_index = 1;
		sprite->anim[2].frame[1].delta_pos.x = 0;
		sprite->anim[2].frame[1].delta_pos.y = 0;
		sprite->anim[2].frame[1].delay = 0;
		sprite->anim[2].frame[1].h_flip = 0;

		sprite->anim[2].frame[2].anim_index = 2;
		sprite->anim[2].frame[2].frame_index = 0;
		sprite->anim[2].frame[2].delta_pos.x = 0;
		sprite->anim[2].frame[2].delta_pos.y = 0;
		sprite->anim[2].frame[2].delay = 0;
		sprite->anim[2].frame[2].h_flip = 0;

		sprite->anim[2].frame[3].anim_index = 2;
		sprite->anim[2].frame[3].frame_index = 2;
		sprite->anim[2].frame[3].delta_pos.x = 0;
		sprite->anim[2].frame[3].delta_pos.y = 0;
		sprite->anim[2].frame[3].delay = 0;
		sprite->anim[2].frame[3].h_flip = 0;

	///turn from back
	sprite->anim[3].frames_count = 2;
	sprite->anim[3].frame = MEM_alloc(2 * sizeof(t_frame));
		sprite->anim[3].frame[0].anim_index = 3;
		sprite->anim[3].frame[0].frame_index = 0;
		sprite->anim[3].frame[0].delta_pos.x = 0;
		sprite->anim[3].frame[0].delta_pos.y = 0;
		sprite->anim[3].frame[0].delay = 0;
		sprite->anim[3].frame[0].h_flip = 0;

		sprite->anim[3].frame[1].anim_index = 3;
		sprite->anim[3].frame[1].frame_index = 1;
		sprite->anim[3].frame[1].delta_pos.x = 0;
		sprite->anim[3].frame[1].delta_pos.y = 0;
		sprite->anim[3].frame[1].delay = 0;
		sprite->anim[3].frame[1].h_flip = 0;

	///turn to back
	sprite->anim[4].frames_count = 2;
	sprite->anim[4].frame = MEM_alloc(2 * sizeof(t_frame));

		sprite->anim[4].frame[0].anim_index = 3;
		sprite->anim[4].frame[0].frame_index = 1;
		sprite->anim[4].frame[0].delta_pos.x = 0;
		sprite->anim[4].frame[0].delta_pos.y = 0;
		sprite->anim[4].frame[0].delay = 0;
		sprite->anim[4].frame[0].h_flip = 0;

		sprite->anim[4].frame[1].anim_index = 3;
		sprite->anim[4].frame[1].frame_index = 0;
		sprite->anim[4].frame[1].delta_pos.x = 0;
		sprite->anim[4].frame[1].delta_pos.y = 0;
		sprite->anim[4].frame[1].delay = 0;
		sprite->anim[4].frame[1].h_flip = 0;

	///turn from front
	sprite->anim[5].frames_count = 2;
	sprite->anim[5].frame = MEM_alloc(2 * sizeof(t_frame));
		sprite->anim[5].frame[0].anim_index = 4;
		sprite->anim[5].frame[0].frame_index = 0;
		sprite->anim[5].frame[0].delta_pos.x = 0;
		sprite->anim[5].frame[0].delta_pos.y = 0;
		sprite->anim[5].frame[0].delay = 0;
		sprite->anim[5].frame[0].h_flip = 0;

		sprite->anim[5].frame[1].anim_index = 4;
		sprite->anim[5].frame[1].frame_index = 1;
		sprite->anim[5].frame[1].delta_pos.x = 0;
		sprite->anim[5].frame[1].delta_pos.y = 0;
		sprite->anim[5].frame[1].delay = 0;
		sprite->anim[5].frame[1].h_flip = 0;

	///turn to front
	sprite->anim[6].frames_count = 2;
	sprite->anim[6].frame = MEM_alloc(2 * sizeof(t_frame));
		sprite->anim[6].frame[0].anim_index = 4;
		sprite->anim[6].frame[0].frame_index = 1;
		sprite->anim[6].frame[0].delta_pos.x = 0;
		sprite->anim[6].frame[0].delta_pos.y = 0;
		sprite->anim[6].frame[0].delay = 0;
		sprite->anim[6].frame[0].h_flip = 0;

		sprite->anim[6].frame[1].anim_index = 4;
		sprite->anim[6].frame[1].frame_index = 0;
		sprite->anim[6].frame[1].delta_pos.x = 0;
		sprite->anim[6].frame[1].delta_pos.y = 0;
		sprite->anim[6].frame[1].delay = 0;
		sprite->anim[6].frame[1].h_flip = 0;

	///fall from back
	sprite->anim[7].frames_count = 12;
	sprite->anim[7].frame = MEM_alloc(12 * sizeof(t_frame));
		sprite->anim[7].frame[0].anim_index = 5;
		sprite->anim[7].frame[0].frame_index = 0;
		sprite->anim[7].frame[0].delta_pos.x = 0;
		sprite->anim[7].frame[0].delta_pos.y = 0;
		sprite->anim[7].frame[0].delay = 0;
		sprite->anim[7].frame[0].h_flip = 0;

		sprite->anim[7].frame[1].anim_index = 5;
		sprite->anim[7].frame[1].frame_index = 1;
		sprite->anim[7].frame[1].delta_pos.x = 0;
		sprite->anim[7].frame[1].delta_pos.y = 0;
		sprite->anim[7].frame[1].delay = 0;
		sprite->anim[7].frame[1].h_flip = 0;

		sprite->anim[7].frame[2].anim_index = 5;
		sprite->anim[7].frame[2].frame_index = 2;
		sprite->anim[7].frame[2].delta_pos.x = 0;
		sprite->anim[7].frame[2].delta_pos.y = 0;
		sprite->anim[7].frame[2].delay = 0;
		sprite->anim[7].frame[2].h_flip = 0;

		sprite->anim[7].frame[3].anim_index = 5;
		sprite->anim[7].frame[3].frame_index = 3;
		sprite->anim[7].frame[3].delta_pos.x = 0;
		sprite->anim[7].frame[3].delta_pos.y = 0;
		sprite->anim[7].frame[3].delay = 0;
		sprite->anim[7].frame[3].h_flip = 0;

		sprite->anim[7].frame[4].anim_index = 5;
		sprite->anim[7].frame[4].frame_index = 2;
		sprite->anim[7].frame[4].delta_pos.x = 0;
		sprite->anim[7].frame[4].delta_pos.y = 0;
		sprite->anim[7].frame[4].delay = 0;
		sprite->anim[7].frame[4].h_flip = 0;

		sprite->anim[7].frame[5].anim_index = 5;
		sprite->anim[7].frame[5].frame_index = 3;
		sprite->anim[7].frame[5].delta_pos.x = 0;
		sprite->anim[7].frame[5].delta_pos.y = 0;
		sprite->anim[7].frame[5].delay = 0;
		sprite->anim[7].frame[5].h_flip = 1;

		sprite->anim[7].frame[6].anim_index = 8;
		sprite->anim[7].frame[6].frame_index = 0;
		sprite->anim[7].frame[6].delta_pos.x = 0;
		sprite->anim[7].frame[6].delta_pos.y = 0;
		sprite->anim[7].frame[6].delay = 0;
		sprite->anim[7].frame[6].h_flip = 0;

		sprite->anim[7].frame[7].anim_index = 8;
		sprite->anim[7].frame[7].frame_index = 1;
		sprite->anim[7].frame[7].delta_pos.x = 0;
		sprite->anim[7].frame[7].delta_pos.y = 0;
		sprite->anim[7].frame[7].delay = 0;
		sprite->anim[7].frame[7].h_flip = 0;

		sprite->anim[7].frame[8].anim_index = 8;
		sprite->anim[7].frame[8].frame_index = 2;
		sprite->anim[7].frame[8].delta_pos.x = 0;
		sprite->anim[7].frame[8].delta_pos.y = 0;
		sprite->anim[7].frame[8].delay = 0;
		sprite->anim[7].frame[8].h_flip = 0;

		sprite->anim[7].frame[9].anim_index = 11;
		sprite->anim[7].frame[9].frame_index = 0;
		sprite->anim[7].frame[9].delta_pos.x = 0;
		sprite->anim[7].frame[9].delta_pos.y = 0;
		sprite->anim[7].frame[9].delay = 0;
		sprite->anim[7].frame[9].h_flip = 0;

		sprite->anim[7].frame[10].anim_index = 11;
		sprite->anim[7].frame[10].frame_index = 1;
		sprite->anim[7].frame[10].delta_pos.x = 0;
		sprite->anim[7].frame[10].delta_pos.y = 0;
		sprite->anim[7].frame[10].delay = 0;
		sprite->anim[7].frame[10].h_flip = 0;

		sprite->anim[7].frame[11].anim_index = 12;
		sprite->anim[7].frame[11].frame_index = 2;
		sprite->anim[7].frame[11].delta_pos.x = 0;
		sprite->anim[7].frame[11].delta_pos.y = 0;
		sprite->anim[7].frame[11].delay = 0;
		sprite->anim[7].frame[11].h_flip = 0;
	//*
	///fall from front
	sprite->anim[8].frames_count = 12;
	sprite->anim[8].frame = MEM_alloc(12 * sizeof(t_frame));
		sprite->anim[8].frame[0].anim_index = 6;
		sprite->anim[8].frame[0].frame_index = 0;
		sprite->anim[8].frame[0].delta_pos.x = 0;
		sprite->anim[8].frame[0].delta_pos.y = 0;
		sprite->anim[8].frame[0].delay = 0;
		sprite->anim[8].frame[0].h_flip = 0;

		sprite->anim[8].frame[1].anim_index = 6;
		sprite->anim[8].frame[1].frame_index = 0;
		sprite->anim[8].frame[1].delta_pos.x = 0;
		sprite->anim[8].frame[1].delta_pos.y = 0;
		sprite->anim[8].frame[1].delay = 0;
		sprite->anim[8].frame[1].h_flip = 1;

		sprite->anim[8].frame[2].anim_index = 6;
		sprite->anim[8].frame[2].frame_index = 1;
		sprite->anim[8].frame[2].delta_pos.x = 0;
		sprite->anim[8].frame[2].delta_pos.y = 0;
		sprite->anim[8].frame[2].delay = 0;
		sprite->anim[8].frame[2].h_flip = 0;

		sprite->anim[8].frame[3].anim_index = 6;
		sprite->anim[8].frame[3].frame_index = 2;
		sprite->anim[8].frame[3].delta_pos.x = 0;
		sprite->anim[8].frame[3].delta_pos.y = 0;
		sprite->anim[8].frame[3].delay = 0;
		sprite->anim[8].frame[3].h_flip = 0;

		sprite->anim[8].frame[4].anim_index = 6;
		sprite->anim[8].frame[4].frame_index = 1;
		sprite->anim[8].frame[4].delta_pos.x = 0;
		sprite->anim[8].frame[4].delta_pos.y = 0;
		sprite->anim[8].frame[4].delay = 0;
		sprite->anim[8].frame[4].h_flip = 0;

		sprite->anim[8].frame[5].anim_index = 6;
		sprite->anim[8].frame[5].frame_index = 2;
		sprite->anim[8].frame[5].delta_pos.x = 0;
		sprite->anim[8].frame[5].delta_pos.y = 0;
		sprite->anim[8].frame[5].delay = 0;
		sprite->anim[8].frame[5].h_flip = 1;

		sprite->anim[8].frame[6].anim_index = 9;
		sprite->anim[8].frame[6].frame_index = 0;
		sprite->anim[8].frame[6].delta_pos.x = 0;
		sprite->anim[8].frame[6].delta_pos.y = 0;
		sprite->anim[8].frame[6].delay = 0;
		sprite->anim[8].frame[6].h_flip = 0;

		sprite->anim[8].frame[7].anim_index = 9;
		sprite->anim[8].frame[7].frame_index = 1;
		sprite->anim[8].frame[7].delta_pos.x = 0;
		sprite->anim[8].frame[7].delta_pos.y = 0;
		sprite->anim[8].frame[7].delay = 0;
		sprite->anim[8].frame[7].h_flip = 0;

		sprite->anim[8].frame[8].anim_index = 9;
		sprite->anim[8].frame[8].frame_index = 2;
		sprite->anim[8].frame[8].delta_pos.x = 0;
		sprite->anim[8].frame[8].delta_pos.y = 0;
		sprite->anim[8].frame[8].delay = 0;
		sprite->anim[8].frame[8].h_flip = 0;

		sprite->anim[8].frame[9].anim_index = 11;
		sprite->anim[8].frame[9].frame_index = 0;
		sprite->anim[8].frame[9].delta_pos.x = 0;
		sprite->anim[8].frame[9].delta_pos.y = 0;
		sprite->anim[8].frame[9].delay = 0;
		sprite->anim[8].frame[9].h_flip = 0;

		sprite->anim[8].frame[10].anim_index = 11;
		sprite->anim[8].frame[10].frame_index = 1;
		sprite->anim[8].frame[10].delta_pos.x = 0;
		sprite->anim[8].frame[10].delta_pos.y = 0;
		sprite->anim[8].frame[10].delay = 0;
		sprite->anim[8].frame[10].h_flip = 0;

		sprite->anim[8].frame[11].anim_index = 12;
		sprite->anim[8].frame[11].frame_index = 2;
		sprite->anim[8].frame[11].delta_pos.x = 0;
		sprite->anim[8].frame[11].delta_pos.y = 0;
		sprite->anim[8].frame[11].delay = 0;
		sprite->anim[8].frame[11].h_flip = 0;

	///fall from right
	sprite->anim[9].frames_count = 12;
	sprite->anim[9].frame = MEM_alloc(12 * sizeof(t_frame));
		sprite->anim[9].frame[0].anim_index = 7;
		sprite->anim[9].frame[0].frame_index = 0;
		sprite->anim[9].frame[0].delta_pos.x = 0;
		sprite->anim[9].frame[0].delta_pos.y = 0;
		sprite->anim[9].frame[0].delay = 0;
		sprite->anim[9].frame[0].h_flip = 0;

		sprite->anim[9].frame[1].anim_index = 7;
		sprite->anim[9].frame[1].frame_index = 1;
		sprite->anim[9].frame[1].delta_pos.x = 0;
		sprite->anim[9].frame[1].delta_pos.y = 0;
		sprite->anim[9].frame[1].delay = 0;
		sprite->anim[9].frame[1].h_flip = 0;

		sprite->anim[9].frame[2].anim_index = 7;
		sprite->anim[9].frame[2].frame_index = 2;
		sprite->anim[9].frame[2].delta_pos.x = 0;
		sprite->anim[9].frame[2].delta_pos.y = 0;
		sprite->anim[9].frame[2].delay = 0;
		sprite->anim[9].frame[2].h_flip = 0;

		sprite->anim[9].frame[3].anim_index = 7;
		sprite->anim[9].frame[3].frame_index = 3;
		sprite->anim[9].frame[3].delta_pos.x = 0;
		sprite->anim[9].frame[3].delta_pos.y = 0;
		sprite->anim[9].frame[3].delay = 0;
		sprite->anim[9].frame[3].h_flip = 0;

		sprite->anim[9].frame[4].anim_index = 7;
		sprite->anim[9].frame[4].frame_index = 4;
		sprite->anim[9].frame[4].delta_pos.x = 0;
		sprite->anim[9].frame[4].delta_pos.y = 0;
		sprite->anim[9].frame[4].delay = 0;
		sprite->anim[9].frame[4].h_flip = 0;

		sprite->anim[9].frame[5].anim_index = 7;
		sprite->anim[9].frame[5].frame_index = 5;
		sprite->anim[9].frame[5].delta_pos.x = 0;
		sprite->anim[9].frame[5].delta_pos.y = 0;
		sprite->anim[9].frame[5].delay = 0;
		sprite->anim[9].frame[5].h_flip = 0;

		sprite->anim[9].frame[6].anim_index = 10;
		sprite->anim[9].frame[6].frame_index = 0;
		sprite->anim[9].frame[6].delta_pos.x = 0;
		sprite->anim[9].frame[6].delta_pos.y = 0;
		sprite->anim[9].frame[6].delay = 0;
		sprite->anim[9].frame[6].h_flip = 0;

		sprite->anim[9].frame[7].anim_index = 10;
		sprite->anim[9].frame[7].frame_index = 1;
		sprite->anim[9].frame[7].delta_pos.x = 0;
		sprite->anim[9].frame[7].delta_pos.y = 0;
		sprite->anim[9].frame[7].delay = 0;
		sprite->anim[9].frame[7].h_flip = 0;

		sprite->anim[9].frame[8].anim_index = 10;
		sprite->anim[9].frame[8].frame_index = 2;
		sprite->anim[9].frame[8].delta_pos.x = 0;
		sprite->anim[9].frame[8].delta_pos.y = 0;
		sprite->anim[9].frame[8].delay = 0;
		sprite->anim[9].frame[8].h_flip = 0;

		sprite->anim[9].frame[9].anim_index = 12;
		sprite->anim[9].frame[9].frame_index = 0;
		sprite->anim[9].frame[9].delta_pos.x = 0;
		sprite->anim[9].frame[9].delta_pos.y = 0;
		sprite->anim[9].frame[9].delay = 0;
		sprite->anim[9].frame[9].h_flip = 0;

		sprite->anim[9].frame[10].anim_index = 12;
		sprite->anim[9].frame[10].frame_index = 1;
		sprite->anim[9].frame[10].delta_pos.x = 0;
		sprite->anim[9].frame[10].delta_pos.y = 0;
		sprite->anim[9].frame[10].delay = 0;
		sprite->anim[9].frame[10].h_flip = 0;

		sprite->anim[9].frame[11].anim_index = 12;
		sprite->anim[9].frame[11].frame_index = 2;
		sprite->anim[9].frame[11].delta_pos.x = 0;
		sprite->anim[9].frame[11].delta_pos.y = 0
		;
		sprite->anim[9].frame[11].delay = 0;
		sprite->anim[9].frame[11].h_flip = 0;
}

void	player_sprite_free(t_sprite *sprite)
{
	for (u8 i = 0; i < 10; i++)
	{
		MEM_free(sprite->anim[i].frame);
	}
	MEM_free(sprite->anim);
}
