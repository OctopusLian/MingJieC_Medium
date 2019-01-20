/* 显示数组的元素个数和各个元素的值 */

#include <stdio.h>

int main(void)
{
	int i;
	int a[] = {1, 2, 3, 4, 5};
	int na = sizeof(a) / sizeof(a[0]);	  /* 元素个数 */

	printf("数组a的元素个数是%d。\n", na);

	for (i = 0; i < na; i++)
		printf("a[%d] = %d\n", i, a[i]);

	return 0;
}
