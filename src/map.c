#include "main.h"

#define DRAW_TILE_8x8(col, row, pos_tile, pal){\
	VDP_setTileMapXY(PLAN_B, pos_tile + (pal << 13), col, row);}

#define DRAW_TILE_16x16(col, row, pos_tile, pal){\
	VDP_setTileMapXY(PLAN_B, pos_tile + (pal << 13), col, row);\
	VDP_setTileMapXY(PLAN_B, pos_tile + 1 + (pal << 13), col + 1, row);\
	VDP_setTileMapXY(PLAN_B, pos_tile + 2 + (pal << 13), col, row + 1);\
	VDP_setTileMapXY(PLAN_B, pos_tile + 3 + (pal << 13), col + 1, row + 1);}

#define DRAW_BORDER(pos_tile, col, row, pal, hor, step){\
	for(u8 i = 0; i < step; i++)\
		VDP_setTileMapXY(PLAN_B, pos_tile + MIN(i, 2) + (pal << 13), col + (i * hor), row + (i * (1 - hor)));}


void draw_border(void);

void	load_map(u8 stage)
{
	u8 col, row;

	VDP_loadTileSet(&fon_elem , TILE_FON_INDEX, 1);

	VDP_setPaletteColor(1, 0xE00);
	VDP_setPaletteColor(2, 0x000);
	VDP_setPaletteColor(3, 0x000);
	VDP_setPaletteColor(4, 0x000);

	VDP_setPaletteColor(5, 0xE00);
	VDP_setPaletteColor(6, 0xEEE);
	VDP_setPaletteColor(7, 0xAAA);
	VDP_setPaletteColor(8, 0x000);
	VDP_setPaletteColor(9, 0x01C);


	if (stage == 1)
	{
		VDP_setPaletteColor(14, 0x030);
		VDP_loadTileSet(&border0 , TILE_BORDER_INDEX, 1);


		for (col = 0; col < 15; col++)
			for (row = 0; row < 11; row++)
			{
				g_map[col][row].type = FON_NONE1;
				g_map[col][row].go = TRUE;
				if ((col%2 == 0) && (row%2 == 0))
				{
					g_map[col][row].type = FON_STONE;
					g_map[col][row].go = FALSE;
				}
			}
	}
	if (stage == 2)
	{
		VDP_setPaletteColor(14, 0x04A);
		VDP_loadTileSet(&border1 , TILE_BORDER_INDEX, 1);

		for (col = 0; col < 15; col++)
			for (row = 0; row < 11; row++)
			{
				g_map[col][row].type = FON_NONE2;
				g_map[col][row].go = TRUE;
				if ((col%2 == 0) && (row%2 == 0))
				{
					g_map[col][row].type = FON_STONE;
					g_map[col][row].go = FALSE;
				}
			}
	}
	else if (stage == 3)
	{
		VDP_setPaletteColor(14, 0x04A);
		VDP_loadTileSet(&border1 , TILE_BORDER_INDEX, 1);

		for (col = 0; col < 15; col++)
			for (row = 0; row < 11; row++)
			{
				g_map[col][row].type = FON_NONE2;
				g_map[col][row].go = TRUE;
				if ((col%2 == 0) && (row%2 == 0))
				{
					g_map[col][row].type = FON_STONE;
					g_map[col][row].go = FALSE;
				}
			}
		g_map[ 0][ 0].type = FON_HOUSE_1_LT;
		g_map[ 1][ 0].type = FON_HOUSE_1_CT;
		g_map[ 2][ 0].type = FON_HOUSE_1_RT;
		g_map[ 0][ 1].type = FON_HOUSE_1_LC;
		g_map[ 1][ 1].type = FON_HOUSE_1_CC;
		g_map[ 2][ 1].type = FON_HOUSE_1_RC;
		g_map[ 0][ 2].type = FON_HOUSE_1_LD;
		g_map[ 1][ 2].type = FON_HOUSE_1_CD;
		g_map[ 2][ 2].type = FON_HOUSE_1_RD;

		g_map[12][ 0].type = FON_HOUSE_1_LT;
		g_map[13][ 0].type = FON_HOUSE_1_CT;
		g_map[14][ 0].type = FON_HOUSE_1_RT;
		g_map[12][ 1].type = FON_HOUSE_1_LC;
		g_map[13][ 1].type = FON_HOUSE_1_CC;
		g_map[14][ 1].type = FON_HOUSE_1_RC;
		g_map[12][ 2].type = FON_HOUSE_1_LD;
		g_map[13][ 2].type = FON_HOUSE_1_CD;
		g_map[14][ 2].type = FON_HOUSE_1_RD;

		g_map[ 3][ 8].type = FON_BONE_HOR;
		g_map[ 5][ 2].type = FON_BONE_HOR;
		g_map[ 9][ 2].type = FON_BONE_HOR;
		g_map[11][ 8].type = FON_BONE_HOR;

		g_map[ 6][ 3].type = FON_BONE_VER;
		g_map[ 8][ 3].type = FON_BONE_VER;
		g_map[ 2][ 7].type = FON_BONE_VER;
		g_map[12][ 7].type = FON_BONE_VER;
	}
	else if (stage == 4)
	{
		VDP_loadTileSet(&border1 , TILE_BORDER_INDEX, 1);
		VDP_setPaletteColor(14, 0x006);
		VDP_setPaletteColor(1, 0x800);

		for (col = 0; col < 15; col++)
			for (row = 0; row < 11; row++)
			{
				g_map[col][row].type = FON_NONE3;
				g_map[col][row].go = TRUE;
				if ((col%2 == 0) && (row%2 == 0))
				{
					g_map[col][row].type = FON_SKULL;
					g_map[col][row].go = FALSE;
				}
			}
		g_map[2][3].type = FON_BONE_VER;
		g_map[2][7].type = FON_BONE_VER;
		g_map[4][5].type = FON_BONE_VER;
		g_map[6][3].type = FON_BONE_VER;
		g_map[6][7].type = FON_BONE_VER;
		g_map[8][5].type = FON_BONE_VER;
		g_map[10][3].type = FON_BONE_VER;
		g_map[10][7].type = FON_BONE_VER;
	}
	else if (stage == 5)
	{
		VDP_loadTileSet(&border1 , TILE_BORDER_INDEX, 1);
		VDP_setPaletteColor(14, 0x006);
		VDP_setPaletteColor(1, 0x800);

		for (col = 0; col < 15; col++)
			for (row = 0; row < 11; row++)
			{
				g_map[col][row].type = FON_NONE3;
				g_map[col][row].go = TRUE;
				if ((col%2 == 0) && (row%2 == 0))
				{
					g_map[col][row].type = FON_SKULL;
					g_map[col][row].go = FALSE;
				}
			}
		g_map[2][3].type = FON_BONE_VER;
		g_map[2][7].type = FON_BONE_VER;
		g_map[4][5].type = FON_BONE_VER;
		g_map[6][3].type = FON_BONE_VER;
		g_map[6][7].type = FON_BONE_VER;
		g_map[8][5].type = FON_BONE_VER;
		g_map[10][3].type = FON_BONE_VER;
		g_map[10][7].type = FON_BONE_VER;

		g_map[0][0].type = FON_HOUSE_2_LT;
		g_map[1][0].type = FON_HOUSE_2_CT;
		g_map[2][0].type = FON_HOUSE_2_RT;
		g_map[0][1].type = FON_HOUSE_2_LC;
		g_map[1][1].type = FON_HOUSE_2_CC;
		g_map[2][1].type = FON_HOUSE_2_RC;
		g_map[0][2].type = FON_HOUSE_2_LD;
		g_map[1][2].type = FON_HOUSE_2_CD;
		g_map[2][2].type = FON_HOUSE_2_RD;

		g_map[12][0].type = FON_HOUSE_2_LT;
		g_map[13][0].type = FON_HOUSE_2_CT;
		g_map[14][0].type = FON_HOUSE_2_RT;
		g_map[12][1].type = FON_HOUSE_2_LC;
		g_map[13][1].type = FON_HOUSE_2_CC;
		g_map[14][1].type = FON_HOUSE_2_RC;
		g_map[12][2].type = FON_HOUSE_2_LD;
		g_map[13][2].type = FON_HOUSE_2_CD;
		g_map[14][2].type = FON_HOUSE_2_RD;
	}
	else if (stage == 6)
	{
		VDP_loadTileSet(&border1 , TILE_BORDER_INDEX, 1);
		VDP_setPaletteColor(14, 0x006);
		VDP_setPaletteColor(1, 0x800);

		for (col = 0; col < 15; col++)
			for (row = 0; row < 11; row++)
			{
				g_map[col][row].type = FON_NONE3;
				g_map[col][row].go = TRUE;
				if ((col%2 == 0) && (row%2 == 0))
				{
					g_map[col][row].type = FON_SKULL;
					g_map[col][row].go = FALSE;
				}
			}
		g_map[2][3].type = FON_BONE_VER;
		g_map[2][7].type = FON_BONE_VER;
		g_map[4][5].type = FON_BONE_VER;
		g_map[6][3].type = FON_BONE_VER;
		g_map[6][7].type = FON_BONE_VER;
		g_map[8][5].type = FON_BONE_VER;
		g_map[10][3].type = FON_BONE_VER;
		g_map[10][7].type = FON_BONE_VER;

		g_map[0][0].type = FON_HOUSE_2_LT;
		g_map[1][0].type = FON_HOUSE_2_CT;
		g_map[2][0].type = FON_HOUSE_2_RT;
		g_map[0][1].type = FON_HOUSE_2_LC;
		g_map[1][1].type = FON_HOUSE_2_CC;
		g_map[2][1].type = FON_HOUSE_2_RC;
		g_map[0][2].type = FON_HOUSE_2_LD;
		g_map[1][2].type = FON_HOUSE_2_CD;
		g_map[2][2].type = FON_HOUSE_2_RD;

		g_map[12][0].type = FON_HOUSE_2_LT;
		g_map[13][0].type = FON_HOUSE_2_CT;
		g_map[14][0].type = FON_HOUSE_2_RT;
		g_map[12][1].type = FON_HOUSE_2_LC;
		g_map[13][1].type = FON_HOUSE_2_CC;
		g_map[14][1].type = FON_HOUSE_2_RC;
		g_map[12][2].type = FON_HOUSE_2_LD;
		g_map[13][2].type = FON_HOUSE_2_CD;
		g_map[14][2].type = FON_HOUSE_2_RD;

		g_map[6][8].type = FON_HOUSE_2_LT;
		g_map[7][8].type = FON_HOUSE_2_CT;
		g_map[8][8].type = FON_HOUSE_2_RT;
		g_map[6][9].type = FON_HOUSE_2_LC;
		g_map[7][9].type = FON_HOUSE_2_CC;
		g_map[8][9].type = FON_HOUSE_2_RC;
		g_map[6][10].type = FON_HOUSE_2_LD;
		g_map[7][10].type = FON_HOUSE_2_CD;
		g_map[8][10].type = FON_HOUSE_2_RD;
	}
	else if (stage == 8)
	{
		VDP_loadTileSet(&border2 , TILE_BORDER_INDEX, 1);
		VDP_setPaletteColor(14, 0x04A);
		VDP_setPaletteColor(1, 0x004);
		VDP_setPaletteColor(5, 0x004);
		VDP_setPaletteColor(6, 0xEEE);
		VDP_setPaletteColor(7, 0x28C);
		VDP_setPaletteColor(8, 0x000);
		VDP_setPaletteColor(10, 0x28C);

		for (col = 0; col < 15; col++)
			for (row = 0; row < 11; row++)
			{
				g_map[col][row].type = FON_NONE4;
				g_map[col][row].go = TRUE;
				if ((col%2 == 0) && (row%2 == 0))
				{
					g_map[col][row].type = FON_STONE;
					g_map[col][row].go = FALSE;
				}
			}
		g_map[6][1].type = FON_BONE_VER;
		g_map[6][3].type = FON_BONE_VER;
		g_map[7][4].type = FON_BONE_HOR;
		g_map[8][5].type = FON_BONE_VER;
		g_map[8][7].type = FON_BONE_VER;
		g_map[8][9].type = FON_BONE_VER;


		g_map[0][0].type = FON_HOUSE_3_LT;
		g_map[1][0].type = FON_HOUSE_3_CT;
		g_map[2][0].type = FON_HOUSE_3_RT;
		g_map[0][1].type = FON_HOUSE_3_LC;
		g_map[1][1].type = FON_HOUSE_3_CC;
		g_map[2][1].type = FON_HOUSE_3_RC;
		g_map[0][2].type = FON_HOUSE_3_LD;
		g_map[1][2].type = FON_HOUSE_3_CD;
		g_map[2][2].type = FON_HOUSE_3_RD;

		g_map[12][0].type = FON_HOUSE_3_LT;
		g_map[13][0].type = FON_HOUSE_3_CT;
		g_map[14][0].type = FON_HOUSE_3_RT;
		g_map[12][1].type = FON_HOUSE_3_LC;
		g_map[13][1].type = FON_HOUSE_3_CC;
		g_map[14][1].type = FON_HOUSE_3_RC;
		g_map[12][2].type = FON_HOUSE_3_LD;
		g_map[13][2].type = FON_HOUSE_3_CD;
		g_map[14][2].type = FON_HOUSE_3_RD;
	}
	else if (stage == 9)
	{
		VDP_loadTileSet(&border2 , TILE_BORDER_INDEX, 1);
		VDP_setPaletteColor(14, 0x04A);
		VDP_setPaletteColor(1, 0x004);
		VDP_setPaletteColor(5, 0x004);
		VDP_setPaletteColor(6, 0xEEE);
		VDP_setPaletteColor(7, 0x28C);
		VDP_setPaletteColor(8, 0x000);
		VDP_setPaletteColor(10, 0x28C);

		for (col = 0; col < 15; col++)
			for (row = 0; row < 11; row++)
			{
				g_map[col][row].type = FON_NONE4;
				g_map[col][row].go = TRUE;
				if ((col%2 == 0) && (row%2 == 0))
				{
					g_map[col][row].type = FON_STONE;
					g_map[col][row].go = FALSE;
				}
			}
		g_map[4][9].type = FON_BONE_VER;
		g_map[4][7].type = FON_BONE_VER;
		g_map[5][6].type = FON_BONE_HOR;
		g_map[6][5].type = FON_BONE_VER;
		g_map[6][3].type = FON_BONE_VER;

		g_map[10][3].type = FON_BONE_VER;
		g_map[10][5].type = FON_BONE_VER;
		g_map[11][6].type = FON_BONE_HOR;
		g_map[12][7].type = FON_BONE_VER;
		g_map[12][9].type = FON_BONE_VER;

		g_map[4][9].go = FALSE;
		g_map[4][7].go = FALSE;
		g_map[5][6].go = FALSE;
		g_map[6][5].go = FALSE;
		g_map[6][3].go = FALSE;

		g_map[10][3].go = FALSE;
		g_map[10][5].go = FALSE;
		g_map[11][6].go = FALSE;
		g_map[12][7].go = FALSE;
		g_map[12][9].go = FALSE;


		g_map[0][0].type = FON_HOUSE_3_LT;
		g_map[1][0].type = FON_HOUSE_3_CT;
		g_map[2][0].type = FON_HOUSE_3_RT;
		g_map[0][1].type = FON_HOUSE_3_LC;
		g_map[1][1].type = FON_HOUSE_3_CC;
		g_map[2][1].type = FON_HOUSE_3_RC;
		g_map[0][2].type = FON_HOUSE_3_LD;
		g_map[1][2].type = FON_HOUSE_3_CD;
		g_map[2][2].type = FON_HOUSE_3_RD;

		g_map[12][0].type = FON_HOUSE_3_LT;
		g_map[13][0].type = FON_HOUSE_3_CT;
		g_map[14][0].type = FON_HOUSE_3_RT;
		g_map[12][1].type = FON_HOUSE_3_LC;
		g_map[13][1].type = FON_HOUSE_3_CC;
		g_map[14][1].type = FON_HOUSE_3_RC;
		g_map[12][2].type = FON_HOUSE_3_LD;
		g_map[13][2].type = FON_HOUSE_3_CD;
		g_map[14][2].type = FON_HOUSE_3_RD;

		g_map[4][0].type = FON_HOUSE_3_LT;
		g_map[5][0].type = FON_HOUSE_3_CTT;
		g_map[6][0].type = FON_HOUSE_3_RT;
		g_map[4][1].type = FON_HOUSE_3_LC;
		g_map[5][1].type = FON_HOUSE_3_CC;
		g_map[6][1].type = FON_HOUSE_3_RC;
		g_map[4][2].type = FON_HOUSE_3_LD;
		g_map[5][2].type = FON_HOUSE_3_CD;
		g_map[6][2].type = FON_HOUSE_3_RD;

		g_map[8][0].type = FON_HOUSE_3_LT;
		g_map[9][0].type = FON_HOUSE_3_CTT;
		g_map[10][0].type = FON_HOUSE_3_RT;
		g_map[8][1].type = FON_HOUSE_3_LC;
		g_map[9][1].type = FON_HOUSE_3_CC;
		g_map[10][1].type = FON_HOUSE_3_RC;
		g_map[8][2].type = FON_HOUSE_3_LD;
		g_map[9][2].type = FON_HOUSE_3_CD;
		g_map[10][2].type = FON_HOUSE_3_RD;
	}
}

void	draw_map()
{
	u8 col, row, i, j;
	draw_border();
	i = 0;
	while (i < 15)
	{
		col = i * 2 + MAP_COL_START;
		j = 0;
		while(j < 11)
		{
			row = j * 2 + MAP_ROW_START;
			DRAW_TILE_16x16(col, row, g_map[i][j].type, PAL0)
			j++;
		}
		i++;
	}
}

void draw_border()
{
	u8 pat, pos;

	for (pat=0; pat < 7; pat++)
	{
		pos = pat * 4 + 1 ;
		DRAW_BORDER(TILE_BORDER_TOP,  pos + BORDER_COL_START, BORDER_ROW_START, PAL0, TRUE, PATERN4)
		DRAW_BORDER(TILE_BORDER_DOWN, pos + BORDER_COL_START, BORDER_ROW_END,   PAL0, TRUE, PATERN4)
		if (pat < 5)
		{
			pos += BORDER_ROW_START;
			DRAW_BORDER(TILE_BORDER_LEFT,  BORDER_COL_START, pos, PAL0, FALSE, PATERN4)
			DRAW_BORDER(TILE_BORDER_RIGHT, BORDER_COL_END,   pos, PAL0, FALSE, PATERN4)
		}
	}
	DRAW_TILE_8x8(BORDER_COL_START, BORDER_ROW_START, TILE_BORDER_NONE, PAL0)
	DRAW_TILE_8x8(BORDER_COL_START, BORDER_ROW_END,   TILE_BORDER_NONE, PAL0)
	DRAW_TILE_8x8(BORDER_COL_END,   BORDER_ROW_START, TILE_BORDER_NONE, PAL0)
	DRAW_TILE_8x8(BORDER_COL_END,   BORDER_ROW_END,   TILE_BORDER_NONE, PAL0)

	DRAW_BORDER(TILE_BORDER_TOP_END,   BORDER_COL_END - 2, BORDER_ROW_START,   PAL0, TRUE,  PATERN2)
	DRAW_BORDER(TILE_BORDER_DOWN_END,  BORDER_COL_END - 2, BORDER_ROW_END,     PAL0, TRUE,  PATERN2)
	DRAW_BORDER(TILE_BORDER_LEFT_END,  BORDER_COL_START,   BORDER_ROW_END - 2, PAL0, FALSE, PATERN2)
	DRAW_BORDER(TILE_BORDER_RIGHT_END, BORDER_COL_END,     BORDER_ROW_END - 2, PAL0, FALSE, PATERN2)
}
