/* ������Ϸ��������Ŀ��������0~999���������*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int no;		/* ��ȡ��ֵ */
	int ans;	/* Ŀ������ */

	srand(time(NULL));		/* �趨����������� */
	ans = rand() % 1000;	/* ����0~999������� */

	printf("���һ��0~999��������\n\n");

	do {
		printf("�Ƕ����أ�");
		scanf("%d", &no);

		if (no > ans)
			printf("\a��Сһ�㡣\n");
		else if (no < ans)
			printf("\a�ٴ�һ�㡣\n");
	} while (no != ans);					/* �ظ����¶�Ϊֹ */

	printf("�ش���ȷ��\n");

	return 0;
}
