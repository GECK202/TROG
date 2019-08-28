#include "main.h"

void		dummy(void);///временная функция заглушка для экспериментов

///тайл для калибровочного фона
const u32 fon_tile[8] =
{
	0x11010101,
	0x10001000,
	0x00000000,
	0x10000000,
	0x11000001,
	0x00000000,
	0x10000000,
	0x10001000,

};

#define DRAW_FON\
	for(u16 row=0; row<25; row++)\
	for(u16 col=0; col<22; col++)\
		VDP_setTileMapXY( PLAN_B, TILE_USERINDEX+8, col,   row);

///функция менеджер игрового процесса
void    game(void)
{
	dummy();
}

void	dummy(void)
{
	u16	joy_state;
	u16 palette[64];

	load_map(9);
	VDP_setBackgroundColor(14);
	VDP_setPalette(PAL3, hero_sprite.palette->data);

	VDP_loadTileData(fon_tile, TILE_USERINDEX+8, 1, 1);
	//VDP_drawImage(PLAN_B, &pole1_img, 0, 0);
	draw_map();
	VDP_loadFont(&font_rus, 1);

	VDP_setTextPlan(PLAN_A);
	VDP_setTextPalette(PAL0);


	//VDP_setPaletteColor(33, 0xE00);
	//VDP_setPaletteColor(34, 0x000);
	//VDP_setPaletteColor(15, 0xEEE);


	//memcpy(&palette[0], pole1_img.palette->data, 16 * 2);
    //memcpy(&palette[0], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[16], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[32], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[48], hero_sprite.palette->data, 16 * 2);
    //VDP_setPaletteColors(0, palette, 64);
    //VDP_fadeIn(0, (4 * 16) - 1, palette, 20, FALSE);


	//DRAW_FON

	JOY_init();
	u16 j_state;
	VDP_setPalette(PAL3, hero_sprite.palette->data);
	object_list_init();
	create_player1();
	create_player2();
	while (TRUE)
	{
		if((player_input(&g_game.player1, JOY_1) == BUTTON_MODE)
			|| (player_input(&g_game.player2, JOY_2) == BUTTON_MODE))
			return ;
		//SYS_disableInts ();
			VDP_resetSprites();

			player_sprite_draw(&g_game.player1);
			//VDP_updateSprites(2, 0);
			player_sprite_draw(&g_game.player2);
			VDP_updateSprites(2, 0);
		//SYS_enableInts ();
        VDP_waitVSync();

	}
	VDP_resetSprites();
	clear_player1();
	MEM_free(g_game.objects);
    VDP_clearPlan(PLAN_A, TRUE);
	VDP_clearPlan(PLAN_B, TRUE);
}


