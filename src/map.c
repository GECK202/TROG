#include "main.h"

void load_map(u8 stage)
{
	u8 col, row;
	if (stage == 1)
	{
		for (col = 0; col < 15; col++)
			for (row = 0; row < 11; row++)
			{
				g_map[col][row].type = mt_none;
				g_map[col][row].go = 1;
				if ((col%2 == 0) && (row%2 == 0))
				{
					g_map[col][row].type = mt_stone;
					g_map[col][row].go = 0;
				}
			}

	}
}
