/* ��ȡ��Ҫ�������������10������Ԫ�ظ���Ϊ10�����飨��һ��*/

#include <stdio.h>

#define	MAX		10			/* �����Ԫ�ظ��� */

int main(void)
{
	int i;
	int a[MAX];				/* ���ڴ洢�Ѷ�ȡ��ֵ������ */
	int cnt = 0;			/* ��ȡ���ĸ��� */
	int retry;				/* ����һ�Σ� */

	printf("������������\n");

	do {
		if (cnt >= MAX) {		/* �ڶ�ȡ��MAX + 1��ֵ�������ֵ֮ǰ */
			for (i = 0; i < MAX - 1; i++)	/* ��Ԫ��a[1] ~ a[MAX - 1] */
				a[i] = a[i + 1];			/* ��ǰ�ƶ�һ��λ�� */
		}
		printf("��%d��������", cnt + 1);
		scanf("%d", &a[cnt < MAX ? cnt : MAX - 1]);
		cnt++;

		printf("�Ƿ��������Yes������1��No������0����");
		scanf("%d", &retry);
	} while (retry == 1);

	if (cnt <= MAX)					/* ��ȡ��ֵ������MAX�� */
		for (i = 0; i < cnt; i++)
			printf("��%2d�� : %d\n", i + 1, a[i]);
	else							/* ��ȡ��ֵ����MAX�� */
		for (i = 0; i < MAX; i++)
			printf("��%2d�� : %d\n", cnt - MAX + 1 + i, a[i]);

	return 0;
}
