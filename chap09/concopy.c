/* 直接输出玩家输入的字符 */

#include <stdio.h>

int main(void)
{
	int	ch;

	while ((ch = getchar()) != EOF)
		putchar(ch);

	return 0;
}
