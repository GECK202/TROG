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
	print("TEK. HAMEPEHiE ", player->intent, 22, 11, 2);\
	print("TEK. pOz. X    ", player->object.pos.x, 22, 12, 3);\
	print("TEK. pOz. Y    ", player->object.pos.y, 22, 13, 3);\
	print("pOz.Ha kaPtE X ", player->object.map_pos.x, 22, 14, 2);\
	print("pOz.Ha kaPtE Y ", player->object.map_pos.y, 22, 15, 2);\
	print("pPOXOd kaPtn   ", g_map[player->object.map_pos.x][player->object.map_pos.y].go, 22, 16, 2);\
	print("iHdEks CpPAxTA ", s->index, 22, 18, 2);\
	print("       LINK    ", player->object.link, 22, 19, 2);\
	print("   pPiOPiTET   ", player->object.priority, 22, 20, 2);\
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
	s16 		posx; //= player->pos.x + s->anim[s->i_anim].frame[s->i_frame].delta_pos.x;
	s16 		posy; //= player->pos.y + s->anim[s->i_anim].frame[s->i_frame].delta_pos.y;
	u8			size;
	s->i_time++;
	if (s->i_time >= (player->delay_frame * s->anim[s->i_anim].frame[s->i_frame].delay))
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
		s->height = hero_sprite.animations[s->cur_anim]->frames[s->cur_frame]->tileset->numTile / s->width;



		VDP_loadTileSet((hero_sprite.animations[s->cur_anim]->frames[s->cur_frame]->tileset), s->tile_index, 1);
		//VDP_setSpriteFull(player->index, posx, posy , SPRITE_SIZE(s->width, s->height), TILE_ATTR_FULL(s->pal_index, player->index, 0, s->cur_flip, s->tile_index), player->link);

		//VDP_updateSprites(1, 0);

	}

	posx = player->object.pos.x + ((s->anim[s->i_anim].frame[s->i_frame].delta_pos.x) * (2 * s->h_flip - 1));
	posy = player->object.pos.y + s->anim[s->i_anim].frame[s->i_frame].delta_pos.y - (8 * s->height);
	//VDP_setSpritePosition(0, posx, posy);

	//s->height = hero_sprite.animations[s->cur_anim]->frames[s->cur_frame]->tileset->numTile / s->width;
	//VDP_setSprite(player->index, posx, posy - (8 * s->height), SPRITE_SIZE(s->width, s->height), TILE_ATTR_FULL(s->pal_index, player->index, 0, s->cur_flip, s->tile_index));
	sort_object_priority();
	VDP_setSpriteFull(player->object.priority, posx, posy, SPRITE_SIZE(s->width, s->height), TILE_ATTR_FULL(s->pal_index, 1, 0, s->cur_flip, s->tile_index), player->object.link);
	//VDP_setSpritePosition(player->index*2, posx, posy - (8 * s->height));
	//VDP_updateSprites(1, 0);player->object.prioritys->index
	if (s->index == 0)
		{PRINT_INFO}
}

///инициализация списка объектов - спрайтов
void	object_list_init()
{
	g_game.objects = MEM_alloc(80 * sizeof(t_object*));
	g_game.objects_count = 0;
}

void	add_object_to_list(t_object *object)
{
	if (g_game.objects_count != 0)
	{
		g_game.objects[g_game.objects_count - 1]->link = g_game.objects_count;
	}
	g_game.objects[g_game.objects_count] = object;
	g_game.objects[g_game.objects_count]->link = 0;
	g_game.objects_count++;
}

void	sort_object_priority()
{
	t_object	*tmp;
	u8			flag = 1;
	while (flag == 1)
	{
		flag = 0;
		for(u16 i = 1; i < g_game.objects_count; i++)
		{
			g_game.objects[i]->priority = i;
			g_game.objects[i-1]->link = i;
			if(g_game.objects[i]->pos.y > g_game.objects[i - 1]->pos.y)
			{
				flag = 1;
				tmp = g_game.objects[i];
				g_game.objects[i] = g_game.objects[i - 1];
				g_game.objects[i - 1] = tmp;
				break ;
			}
		}

	}
	g_game.objects[0]->priority = 0;
	g_game.objects[g_game.objects_count - 1]->link = 0;
}

