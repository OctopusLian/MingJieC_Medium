/* 为字符串数组（二维数组）动态分配空间 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int	num;			/* 字符串的个数 */
	char (*p)[15];		/* 字符数量是常量15 */

	printf("有几个字符串：");
	scanf("%d", &num);

	p = (char (*)[15])malloc(num * 15);

	if (p == NULL) 
		puts("存储空间分配失败。");
	else {
		int i;

		for (i = 0; i < num; i++) {			/* 读取字符串 */
			printf("p[%d] : ", i);
			scanf("%s", p[i]);
		}

		for (i = 0; i < num; i++)			/* 显示字符串 */
			printf("p[%d] = %s\n", i, p[i]);

		free(p);							/* 释放存储空间 */
	}

	return 0;
}
