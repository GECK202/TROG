#include "main.h"



char	show_logo(void);		///показывает логотип, возвращает TRUE если нажата кнопка СТАРТ
char	show_about(void);		///показывает анимационную заставку и инфо об издателе, возвращает TRUE если нажата кнопка СТАРТ
char	show_score(void);		///показывает анимированную таблицу лидеров, возвращает TRUE если нажата кнопка СТАРТ
void	set_score(void);		///функция установки нового значения в таблицу лидеров
void	reset_score(void);		///функция установки начальных значений таблицы лидеров

///функция сменяет и показывает заставки перед началом игры
void    show_intro(void)
{
	///u16	joy_state;

	JOY_init();
	while (TRUE)
	{
		if (show_logo() || show_about() || show_score())
			break ;
	}
	VDP_clearPlan(PLAN_A, TRUE);
	VDP_clearPlan(PLAN_B, TRUE);
	VDP_clearPlan(PLAN_WINDOW, TRUE);
}

///*
char	show_logo(void)
{
	///need to make
	u16	joy_state;

	VDP_drawImage(PLAN_B, &logo_img, 0, 0);
	joy_state = 0;
	joy_state = JOY_waitPressTime(JOY_1, BUTTON_START, 5000);
	if (joy_state)
		return (TRUE);
	return (FALSE);
}
///*/

char	show_about(void)
{
	u16	joy_state;

	VDP_drawImage(PLAN_B, &autor_img, 0, 0);
	joy_state = 0;
	joy_state = JOY_waitPressTime(JOY_1, BUTTON_START, 5000);
	if (joy_state)
		return (TRUE);
	return (FALSE);
}

char	show_score(void)
{
	///need to make
	u16	joy_state;

	VDP_drawImage(PLAN_B, &score_img, 0, 0);
	joy_state = 0;
	joy_state = JOY_waitPressTime(JOY_1, BUTTON_START, 5000);
	if (joy_state)
		return (TRUE);
	return (FALSE);
}

void	set_score(void)
{
	///need to make
}

void	reset_score(void)
{
	strcpy(g_game.player1.score.name, "");
	strcpy(g_game.player2.score.name, "");
	g_game.player1.score.score = 0;
	g_game.player2.score.score = 0;
	strcpy(g_game.score_table[0].name, "ABC");
	strcpy(g_game.score_table[1].name, "DEF");
	strcpy(g_game.score_table[2].name, "GHI");
	strcpy(g_game.score_table[3].name, "JKL");
	strcpy(g_game.score_table[4].name, "MNO");
	g_game.score_table[0].score = 500000;
	g_game.score_table[1].score = 400000;
	g_game.score_table[2].score = 300000;
	g_game.score_table[3].score = 200000;
	g_game.score_table[4].score = 100000;
}
