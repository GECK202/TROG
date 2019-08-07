#include "main.h"

void	dummy(void);

void    game(void)
{
	dummy();
}

void	dummy(void)
{
	u16	joy_state;
	u16 palette[64];
	//s16 posx;
	//s16 posy;
	//s16 dx;
	//s16 dy;
	//s16 cur_anim;
	//JOY_reset();
	SPR_init();
	//VDP_setPaletteColors(0, (u16*) palette_black, 64);

	VDP_drawImage(PLAN_B, &pole1_img, 0, 0);

	g_game.player1.sprite = SPR_addSprite(&hero_sprite, fix32ToInt(0), fix32ToInt(0), TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
	g_game.player2.sprite = SPR_addSprite(&hero_sprite, fix32ToInt(0), fix32ToInt(0), TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
	SPR_update();

	VDP_setPalette(PAL1, hero_sprite.palette->data);


	VDP_setTextPlan(PLAN_A);
	VDP_setTextPalette(PAL2);
	VDP_setPaletteColor(47, 0xEEE);

	//memcpy(&palette[0], pole1_img.palette->data, 16 * 2);
    //memcpy(&palette[0], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[16], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[32], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[48], hero_sprite.palette->data, 16 * 2);
    //VDP_setPaletteColors(0, palette, 64);
    //VDP_fadeIn(0, (4 * 16) - 1, palette, 20, FALSE);

	JOY_init();

	joy_state = 0;
	g_game.player1.pos.x = 16;
	g_game.player1.pos.y = 24;
	g_game.player1.cur_anim = 1;
	//SPR_setFrame(sprite, 0);
	g_game.player1.sprite->timer = 1;
	g_game.player2.sprite->timer = 1;
	SPR_setVisibility(g_game.player1.sprite, AUTO_SLOW);
	SPR_setVisibility(g_game.player2.sprite, AUTO_SLOW);

	SPR_setAnim(g_game.player2.sprite, 14);
	//SPR_setFrame(g_game.player2.sprite, 5);
	SPR_setPosition(g_game.player2.sprite, 100, 100);

	SPR_update();
	while (joy_state != BUTTON_MODE)
	{

		g_game.player1.direct.x = 0;
		g_game.player1.direct.y = 0;
		SPR_setPosition(g_game.player1.sprite, g_game.player1.pos.x, g_game.player1.pos.y);
		//SPR_setFrame(sprite2, 5);
		print("Anim=", hero_sprite.numAnimation, 32, 1);
		print("X=", g_game.player1.pos.x, 32, 3);
		print("Y=", g_game.player1.pos.y, 32, 4);
		print("C_An=",hero_sprite.animations[g_game.player1.cur_anim]->numFrame, 32, 2);

		SPR_update();
        VDP_waitVSync();



		joy_state = JOY_readJoypad(JOY_ALL);


		if (((joy_state & BUTTON_UP) == BUTTON_UP) && (g_game.player1.pos.y > 24))
		{
			SPR_setHFlip(g_game.player1.sprite, FALSE);
			g_game.player1.cur_anim = 0;
			g_game.player1.direct.y = -1;
		}
		else if (((joy_state & BUTTON_DOWN) == BUTTON_DOWN) && (g_game.player1.pos.y < 200))
		{
			SPR_setHFlip(g_game.player1.sprite, FALSE);
			g_game.player1.cur_anim = 1;
			g_game.player1.direct.y = 1;
		}
		if (((joy_state & BUTTON_LEFT) == BUTTON_LEFT) && (g_game.player1.pos.x > 0))
		{
			SPR_setHFlip(g_game.player1.sprite, TRUE);
			g_game.player1.cur_anim = 2;
			g_game.player1.direct.x = -1;
		}
		else if (((joy_state & BUTTON_RIGHT) == BUTTON_RIGHT) && (g_game.player1.pos.x < 240))
		{
			SPR_setHFlip(g_game.player1.sprite, FALSE);
			g_game.player1.cur_anim = 2;
			g_game.player1.direct.x = 1;
		}
		SPR_setAnim(g_game.player1.sprite, g_game.player1.cur_anim);
		g_game.player1.pos.x += g_game.player1.direct.x;
		g_game.player1.pos.y += g_game.player1.direct.y;


	}
	SPR_reset();
    SPR_clear();
    VDP_clearPlan(PLAN_A, TRUE);
	VDP_clearPlan(PLAN_B, TRUE);
}

void	print(char *txt, int n, u16 x, u16 y)
{
	char a[13];
    char b[255];
    intToStr(n, a, 1);
    strcpy(b, txt);
    strcat(b, a);
    VDP_drawText(b, x, y);
}
