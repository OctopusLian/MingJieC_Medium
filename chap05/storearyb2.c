/* ��ȡ��Ҫ�������������10������Ԫ�ظ���Ϊ10�����飨�����*/

#include <stdio.h>

#define MAX		10			/* �����Ԫ�ظ��� */

int main(void)
{
	int i;
	int a[MAX];				/* ���ڴ洢�Ѷ�ȡ��ֵ������ */
	int cnt = 0;			/* ��ȡ���ĸ��� */
	int retry;				/* ����һ�Σ�*/

	printf("������������\n");

	do {
		printf("��%d��������", cnt + 1);
		scanf("%d", &a[cnt++ % MAX]);

		printf("�Ƿ��������Yes������1��No������0����");
		scanf("%d", &retry);
	} while (retry == 1);

	i = cnt - MAX;
	if (i < 0) i = 0;

	for ( ; i < cnt; i++)
		printf("��%2d�� : %d\n", i + 1, a[i % MAX]);

	return 0;
}
