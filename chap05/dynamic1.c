/* 为动态分配了存储空间的整数赋值并显示 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *x;

	x = calloc(1, sizeof(int));		/* 分配 */

	if (x == NULL)
		puts("存储空间分配失败。");
	else {
		*x = 57;
		printf("*x = %d\n", *x);
		free(x);					/* 释放 */
	}

	return 0;
}
