/* 为字符串动态分配空间 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char st[16];
	char *pt;

	printf("请输入字符串st：");
	scanf("%s", st);

	pt = malloc(strlen(st) + 1);	/* 动态分配存储空间 */

	if (pt) {
		strcpy(pt, st);				/* 复制字符串 */
		printf("生成了该字符串的副本pt。\n");
		printf("st = %s\n", st);
		printf("pt = %s\n", pt);
		free(pt);					/* 释放存储空间 */
	}

	return 0;
}
