/* �������������һ��*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int retry;			/* ������һ�Σ� */

	printf("�������̻������ܹ�����0~%d���������\n", RAND_MAX);

	do {
		printf("\n�����������%d��\n", rand());

		printf("������һ�Σ������� (0)�� (1)�ǣ�");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
