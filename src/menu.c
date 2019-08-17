#include "main.h"

void	dummy_menu(void);///функция заглушка вместо функции меню(для продолжения нажать А или В)

///функция отображения и выбора уровня сложности
void	menu(void)
{
	dummy_menu();
}

void	dummy_menu(void)
{
	u16	joy_state;

	//JOY_reset();
	JOY_init();
	VDP_drawImage(PLAN_B, &menu_img, 0, 0);
	joy_state = 0;
	while (joy_state != (BUTTON_A || BUTTON_B))
		joy_state = JOY_readJoypad(JOY_ALL);
	VDP_clearPlan(PLAN_B, TRUE);
	waitMs(500);
}
