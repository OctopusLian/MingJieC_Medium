/* Ϊ�������鶯̬����洢�ռ� */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *x;
	int n;						/* Ԫ�ظ��� */

	printf("Ҫ����洢�ռ�������Ԫ�ظ�����");
	scanf("%d", &n);

	x = calloc(n, sizeof(int));						/* ���� */

	if (x == NULL)
		puts("�洢�ռ����ʧ�ܡ�");
	else {
		int i;

		for (i = 0; i < n; i++)						/* ��ֵ */
			x[i] = i;

		for (i = 0; i < n; i++)						/* ��ʾֵ */
			printf("x[%d] = %d\n", i, x[i]);

		free(x);									/* �ͷ� */
	}

	return 0;
}
