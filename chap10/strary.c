/* Ϊ�ַ�����̬����ռ� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char st[16];
	char *pt;

	printf("�������ַ���st��");
	scanf("%s", st);

	pt = malloc(strlen(st) + 1);	/* ��̬����洢�ռ� */

	if (pt) {
		strcpy(pt, st);				/* �����ַ��� */
		printf("�����˸��ַ����ĸ���pt��\n");
		printf("st = %s\n", st);
		printf("pt = %s\n", pt);
		free(pt);					/* �ͷŴ洢�ռ� */
	}

	return 0;
}
