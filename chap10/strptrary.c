/* 为字符串数组（指针数组）动态分配空间 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int	num;			/* 字符串的个数 */
	char **pt;

	printf("有几个字符串：");
	scanf("%d", &num);

	pt = (char **)calloc(num, sizeof(char *));

	if (pt == NULL) 
		puts("存储空间分配失败。");
	else {
		int	i;

		for (i = 0; i < num; i++)
			pt[i] = NULL;

		for (i = 0; i < num; i++) {
			char temp[128];

			printf("pt[%d] : ", i);
			scanf("%s", temp);

			pt[i] = (char *)malloc(strlen(temp) + 1);

			if (pt[i] != NULL)
				strcpy(pt[i], temp);
			else {
				puts("存储空间分配失败。");
 				goto Free;
			}
		}
		for (i = 0; i < num; i++)
			printf("pt[%d] = %s\n", i, pt[i]);
Free:
		for (i = 0; i < num; i++)
			free(pt[i]);
		free(pt);
	}

	return 0;
}
