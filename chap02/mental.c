/* ����ѵ��������3����λ����������*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c;				/* Ҫ���мӷ��������ֵ */
	int x;						/* �Ѷ�ȡ��ֵ */
	clock_t start, end;			/* ��ʼʱ�䡤����ʱ�� */
	double req_time;			/* ����ʱ�� */

	srand(time(NULL));			/* �趨����������� */

	a = 100 + rand() % 900;		/* ����100~999������� */
	b = 100 + rand() % 900;		/*          ��         */
	c = 100 + rand() % 900;		/*          ��         */

	printf("%d + %d + %d���ڶ��٣�", a, b, c);

	start = clock();			/* ��ʼ���� */

	while (1) {
		scanf("%d", &x);
		if (x == a + b + c)
			break;
		printf("\a�ش����!!\n���������룺");
	}

	end = clock();				/* ������� */

	req_time = (double)(end - start) / CLOCKS_PER_SEC;

	printf("��ʱ%.1f�롣\n", req_time);

	if (req_time > 30.0)
		printf("��̫��ʱ���ˡ�\n");
	else if (req_time > 17.0)
		printf("���аɡ�\n");
	else
		printf("��찡��\n");

	return 0;
}
