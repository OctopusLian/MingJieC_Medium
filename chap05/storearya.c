/* ����ȡ10��ֵ������Ԫ�ظ���Ϊ10������ */

#include <stdio.h>

#define	MAX		10		/* �����Ԫ�ظ��� */

int main(void)
{
	int i;
	int a[MAX];			/* ���ڴ洢��ȡ����ֵ������ */
	int cnt = 0;		/* ��ȡ���ĸ��� */
	int retry;			/* ����һ�Σ� */

	printf("������������\n");
	printf("���������%d����\n", MAX);

	do {
		printf("��%d��������", cnt + 1);
		scanf("%d", &a[cnt++]);

		if (cnt == MAX)		/* ��cnt������ȫ��������Ϻ� */
			break;			/* ���� */

		printf("�Ƿ������(Yes������1��No������0)��");
		scanf("%d", &retry);
	} while (retry == 1);

	for (i = 0; i < cnt; i++)
		printf("��%2d�� : %d\n", i + 1, a[i]);

	return 0;
}
