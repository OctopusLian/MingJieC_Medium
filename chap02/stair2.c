/* 把数字字符每次偏移1位显示（其二）*/

#include <stdio.h>

int main(void)
{
	int i;
	int x;		/* 要显示的行数 */

	printf("要显示多少行：");
	scanf("%d", &x);

	for (i = 1; i <= x; i++)
		printf("%*d\n", i, i % 10);

	return 0;
}
