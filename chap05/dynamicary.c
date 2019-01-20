/* 为整数数组动态分配存储空间 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *x;
	int n;						/* 元素个数 */

	printf("要分配存储空间的数组的元素个数：");
	scanf("%d", &n);

	x = calloc(n, sizeof(int));						/* 分配 */

	if (x == NULL)
		puts("存储空间分配失败。");
	else {
		int i;

		for (i = 0; i < n; i++)						/* 赋值 */
			x[i] = i;

		for (i = 0; i < n; i++)						/* 显示值 */
			printf("x[%d] = %d\n", i, x[i]);

		free(x);									/* 释放 */
	}

	return 0;
}
