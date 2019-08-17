#include "main.h"

void		dummy(void);///временная функция заглушка для экспериментов

///функция менеджер игрового процесса
void    game(void)
{
	dummy();
}

void	dummy(void)
{
	u16	joy_state;
	u16 palette[64];

	VDP_setPalette(PAL1, hero_sprite.palette->data);

	VDP_loadFont(&font_rus, 1);

	VDP_setTextPlan(PLAN_A);
	VDP_setTextPalette(PAL2);
	VDP_setPaletteColor(33, 0xEEE);
	VDP_setPaletteColor(47, 0xEEE);
	VDP_setPaletteColor(46, 0x666);

	//memcpy(&palette[0], pole1_img.palette->data, 16 * 2);
    //memcpy(&palette[0], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[16], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[32], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[48], hero_sprite.palette->data, 16 * 2);
    //VDP_setPaletteColors(0, palette, 64);
    //VDP_fadeIn(0, (4 * 16) - 1, palette, 20, FALSE);

	VDP_setBackgroundColor(46);

	JOY_init();
	u16 j_state;

	create_player1();

	while (TRUE)
	{
		if(player1_input() == BUTTON_MODE)
			return ;
		SYS_disableInts ();
			player_sprite_draw(&g_game.player1);
		SYS_enableInts ();
        VDP_waitVSync();
	}
	VDP_resetSprites();
	clear_player1();
    VDP_clearPlan(PLAN_A, TRUE);
	VDP_clearPlan(PLAN_B, TRUE);
}
