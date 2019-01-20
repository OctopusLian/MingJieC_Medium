/* 复制并显示数组（跳过一个元素）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, x;
	int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a[8] = {0};

	srand(time(NULL));	/* 设定随机数的种子 */

	x = rand() % 9;		/* x为0~8的随机数 */

	i = j = 0;
	while (i < 9) {				/* 复制时跳过dgt[x] */
		if (i != x)
			a[j++] = dgt[i];
		i++;
	}

	for (i = 0; i < 8; i++)				/* 显示所有元素 */
		printf("%d ", a[i]);

	putchar('\n');

	return 0;
}
