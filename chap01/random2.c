/* �������������������ݵ�ǰʱ���趨����������ӣ�*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int retry;				/* ������һ�Σ� */

	srand(time(NULL));		/* ���ݵ�ǰʱ���趨����������� */

	printf("�������̻������ܹ�����0~%d���������\n", RAND_MAX);

	do {
		printf("\n�����������%d��\n", rand());

		printf("������һ�Σ������� (0)�� (1)�ǣ�");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}