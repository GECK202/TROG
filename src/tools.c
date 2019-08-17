#include "main.h"

///печать текста с числом (текст, число, позиция x и y, длина отображаемого числа)
void	print(char *txt, int n, u16 x, u16 y, u8 len)
{
	char a[13];
    char b[255];
    intToStr(n, a, len);
    strcpy(b, txt);
    strcat(b, a);
    VDP_drawText(b, x, y);
}
