/* ����������⣨��������4��0~99����������Ҫ��ʱ�䣩*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c, d;			/* Ҫ�ӵ���ֵ */
	int x;					/* ��ȡ����ֵ */
	time_t start, end;		/* ��ʼʱ��ͽ���ʱ�� */

	srand(time(NULL));		/* �趨����������� */

	a = rand() % 100;		/* ����0~99������� */
	b = rand() % 100;		/*       ��         */
	c = rand() % 100;		/*       ��         */
	d = rand() % 100;		/*       ��         */

	printf("%d + %d + %d + %d���ڶ��٣�", a, b, c, d);

	start = time(NULL);						/* ��ʼ���� */

	while (1) {
		scanf("%d", &x);
		if (x == a + b + c + d)
			break;
		printf("\a�ش����!!\n���������룺");
	}

	end = time(NULL);						/* ������� */

	printf("��ʱ%.0f�롣\n", difftime(end, start));

	return 0;
}
