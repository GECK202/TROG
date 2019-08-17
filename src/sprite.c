#include "main.h"

///макрос печати информации о текущем состоянии игрока1
#define PRINT_INFO\
	print("kOl-BO TaxlOB  ", hero_sprite.animations[s->cur_anim]->frames[s->cur_frame]->tileset->numTile, 22, 1, 2);\
	print("iHdEks TaxlA   ", s->tile_index, 22, 2, 2);\
	print("iHdEks TaxMEPA ", s->i_time, 22, 3, 3);\
	print("zadEPjka kadPa ", player->delay_frame, 22, 4, 3);\
	print("iHdEks aHiMac. ", s->i_anim, 22, 5, 2);\
	print("iHdEks kadPa   ", s->i_frame, 22, 6, 2);\
	print("KOl-BO kadPOB  ", s->anim[s->i_anim].frames_count, 22, 7, 2);\
	print("TEK. KAdP      ", s->cur_frame, 22, 9, 2);\
	print("TEK. aHiMacir  ", s->cur_anim, 22, 8, 2);\
	print("TEK. COCTOrHiE ", player->state, 22, 10, 2);\
	print("TEK. HAMEPEHiE ", player->event, 22, 11, 2);\
	print("TEK. pOz. X    ", posx, 22, 12, 3);\
	print("TEK. pOz. Y    ", posy, 22, 13, 3);\
	VDP_drawText("CTPElKi: idTi; A: CMEPTo", 1, 25);\
	VDP_drawText("zadEPjka kadPa:  B ++  C -- ", 1, 26);
/*
		for(u16 i = 0; i < g_game.player1.sprite->anim[0].frames_count; i++)\
		{\
			print("SEQ ", i, 32, i + 5, 1);\
			print("=", g_game.player1.sprite->anim[0].frame[i].frame_index, 37, i + 5, 2);\
			if (i > 6)\
				break ;\
		}
//*/

///функция отображения спрайта игрока
void	player_sprite_draw(t_player *player)
{
	t_sprite	*s = player->sprite;
	s16 		posx = player->pos.x + s->anim[s->i_anim].frame[s->i_frame].delta_pos.x;
	s16 		posy = player->pos.y + s->anim[s->i_anim].frame[s->i_frame].delta_pos.y;
	u8			size;
	s->i_time++;
	if (s->i_time >= player->delay_frame)
	{
		s->i_time = 0;
		s->i_frame++;
		if (s->i_frame == s->anim[s->i_anim].frames_count)
		{
			set_player_state(player);
			s->i_frame = 0;
		}

		s->cur_frame = s->anim[s->i_anim].frame[s->i_frame].frame_index;
		s->cur_flip = s->h_flip ^ s->anim[s->i_anim].frame[s->i_frame].h_flip;
		s->cur_anim = s->anim[s->i_anim].frame[s->i_frame].anim_index;

		VDP_loadTileSet((hero_sprite.animations[s->cur_anim]->frames[s->cur_frame]->tileset), s->tile_index, 1);
	}
	PRINT_INFO
	s->height = hero_sprite.animations[s->cur_anim]->frames[s->cur_frame]->tileset->numTile / s->width;
	VDP_setSprite(0, posx, posy - (8 * s->height), SPRITE_SIZE(s->width, s->height), TILE_ATTR_FULL(s->pal_index, 1, 0, s->cur_flip, s->tile_index));
	VDP_updateSprites(1, 0);
}



