/* �ѴӼ��������ֵ���붯̬�����˴洢�ռ�������У�����*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *x;

	x = calloc(1, sizeof(int));		/* ���� */

	if (x == NULL)
		puts("�洢�ռ����ʧ�ܡ�");
	else {
		printf("Ҫ����*x��ֵ��");
		scanf("%d", &x);
		printf("*x = %d\n", *x);
		free(x);					/* �ͷ� */
	}

	return 0;
}
