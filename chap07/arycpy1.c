/* 复制并显示数组 */

#include <stdio.h>

int main(void)
{
	int i;
	int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a[9] = {0};

	for (i = 0; i < 9; i++)		/* 复制所有元素 */
		a[i] = dgt[i];

	for (i = 0; i < 9; i++)		/* 显示所有元素 */
		printf("%d ", a[i]);

	putchar('\n');

	return 0;
}
