#include "main.h"

void	dummy(void);

Sprite *sprite;

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
	//JOY_reset();
	SPR_init();
	//VDP_setPaletteColors(0, (u16*) palette_black, 64);

	VDP_drawImage(PLAN_B, &pole1_img, 0, 0);

	sprite = SPR_addSprite(&hero_sprite, fix32ToInt(0), fix32ToInt(0), TILE_ATTR(PAL1, TRUE, FALSE, FALSE));
	SPR_update();

	VDP_setPalette(PAL1, hero_sprite.palette->data);
	//memcpy(&palette[0], pole1_img.palette->data, 16 * 2);
    //memcpy(&palette[0], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[16], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[32], hero_sprite.palette->data, 16 * 2);
    //memcpy(&palette[48], hero_sprite.palette->data, 16 * 2);
    //VDP_setPaletteColors(0, palette, 64);
    //VDP_fadeIn(0, (4 * 16) - 1, palette, 20, FALSE);

	JOY_init();

	joy_state = 0;
	posx = 10;
	posy = 10;

	while (joy_state != BUTTON_MODE)
	{
		dx = 0;
		dy = 0;
		SPR_setPosition(sprite, posx, posy);

		if (dx > 0) SPR_setHFlip(sprite, FALSE);
		else if (dx < 0) SPR_setHFlip(sprite, TRUE);

		SPR_update();
        VDP_waitVSync();



		joy_state = JOY_readJoypad(JOY_ALL);


		if (((joy_state & BUTTON_UP) == BUTTON_UP) && (posy > 10))
			dy = -1;
		else if (((joy_state & BUTTON_DOWN) == BUTTON_DOWN) && (posy < 200))
			dy = 1;

		if (((joy_state & BUTTON_LEFT) == BUTTON_LEFT) && (posx > 10))
			dx = -1;
		else if (((joy_state & BUTTON_RIGHT) == BUTTON_RIGHT) && (posx < 200))
			dx = 1;

		posx += dx;
		posy += dy;
	}
	VDP_clearPlan(PLAN_B, TRUE);
}
