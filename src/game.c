#include "main.h"

void	dummy(void);

void    game(void)
{
	dummy();
}

void	dummy(void)
{
	u16	joy_state;

	//JOY_reset();
	JOY_init();
	VDP_drawImage(PLAN_B, &pole1_img, 0, 0);
	joy_state = 0;
	while (!joy_state)
		joy_state = JOY_readJoypad(JOY_ALL);
	VDP_clearPlan(PLAN_B, TRUE);
}
