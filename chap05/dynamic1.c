/* Ϊ��̬�����˴洢�ռ��������ֵ����ʾ */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *x;

	x = calloc(1, sizeof(int));		/* ���� */

	if (x == NULL)
		puts("�洢�ռ����ʧ�ܡ�");
	else {
		*x = 57;
		printf("*x = %d\n", *x);
		free(x);					/* �ͷ� */
	}

	return 0;
}
