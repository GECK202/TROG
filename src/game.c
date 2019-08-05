#include "main.h"

void	dummy(void);

Sprite *sprite1;
Sprite *sprite2;

void    game(void)
{
	dummy();
}

void	dummy(void)
{
	u16	joy_state;
	u16 palette[64];
	s16 posx;
	s16 posy;
	s16 dx;
	s16 dy;
	s16 cur_anim;
	//JOY_reset();
	SPR_init();
	//VDP_setPaletteColors(0, (u16*) palette_black, 64);

	VDP_drawImage(PLAN_B, &pole1_img, 0, 0);

	sprite1 = SPR_addSprite(&hero_sprite, fix32ToInt(0), fix32ToInt(0), TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
	sprite2 = SPR_addSprite(&hero_sprite, fix32ToInt(0), fix32ToInt(0), TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
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
	posx = 16;
	posy = 24;
	cur_anim = 1;
	//SPR_setFrame(sprite, 0);
	sprite1->timer = 1;
	sprite2->timer = 1;
	SPR_setVisibility(sprite1, AUTO_SLOW);
	SPR_setVisibility(sprite2, AUTO_SLOW);

	SPR_setAnim(sprite2, 7);
	SPR_setFrame(sprite2, 5);
	SPR_setPosition(sprite2, 100, 100);

	SPR_update();
	while (joy_state != BUTTON_MODE)
	{

		dx = 0;
		dy = 0;
		SPR_setPosition(sprite1, posx, posy);
		//SPR_setFrame(sprite2, 5);
		print("Anim=", hero_sprite.numAnimation, 32, 1);
		print("X=", posx, 32, 3);
		print("Y=", posy, 32, 4);
		print("C_An=",hero_sprite.animations[cur_anim]->numFrame, 32, 2);

		SPR_update();
        VDP_waitVSync();



		joy_state = JOY_readJoypad(JOY_ALL);


		if (((joy_state & BUTTON_UP) == BUTTON_UP) && (posy > 24))
		{
			SPR_setHFlip(sprite1, FALSE);
			cur_anim = 0;
			dy = -1;
		}
		else if (((joy_state & BUTTON_DOWN) == BUTTON_DOWN) && (posy < 200))
		{
			SPR_setHFlip(sprite1, FALSE);
			cur_anim = 1;
			dy = 1;
		}
		if (((joy_state & BUTTON_LEFT) == BUTTON_LEFT) && (posx > 0))
		{
			SPR_setHFlip(sprite1, TRUE);
			cur_anim = 2;
			dx = -1;
		}
		else if (((joy_state & BUTTON_RIGHT) == BUTTON_RIGHT) && (posx < 240))
		{
			SPR_setHFlip(sprite1, FALSE);
			cur_anim = 2;
			dx = 1;
		}
		SPR_setAnim(sprite1, cur_anim);
		posx += dx;
		posy += dy;


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
