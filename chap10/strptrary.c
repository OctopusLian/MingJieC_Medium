/* Ϊ�ַ������飨ָ�����飩��̬����ռ� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int	num;			/* �ַ����ĸ��� */
	char **pt;

	printf("�м����ַ�����");
	scanf("%d", &num);

	pt = (char **)calloc(num, sizeof(char *));

	if (pt == NULL) 
		puts("�洢�ռ����ʧ�ܡ�");
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
				puts("�洢�ռ����ʧ�ܡ�");
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
