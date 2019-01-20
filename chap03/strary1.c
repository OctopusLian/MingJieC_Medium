/* 字符串数组（二维数组）*/

#include <stdio.h>

int main(void)
{
	int i;
	char a[][6] = {
		"Super", "X", "TRY"
	};

	for (i = 0; i < 3; i++)
		printf("%s\n", a[i]);

	return 0;
}
