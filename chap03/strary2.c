/* 字符串数组（指针数组）*/

#include <stdio.h>

int main(void)
{
	int i;
	char *p[] = {
		"Super", "X", "TRY"
	};

	for (i = 0; i < 3; i++)
		printf("%s\n", p[i]);

	return 0;
}
