/* ������Ϸ�����ģ��������������*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int no;						/* ��ȡ��ֵ */
	int ans;					/* Ŀ������ */
	const int max_stage = 10;	/* ����������Ĵ��� */
	int remain = max_stage;		/* ���������뼸�Σ� */

	srand(time(NULL));			/* �趨����������� */
	ans = rand() % 1000;		/* ����0~999������� */

	printf("���һ��0~999��������\n\n");

	do {
		printf("��ʣ%d�λ��ᡣ�Ƕ����أ�", remain);
		scanf("%d", &no);
		remain--;			/* ����ʣ�������м��� */

		if (no > ans)
			printf("\a��Сһ�㡣\n");
		else if (no < ans)
			printf("\a�ٴ�һ�㡣\n");
	} while (no != ans && remain > 0);

	if (no != ans)
		printf("\a���ź�����ȷ����%d��\n", ans);
	else {
		printf("�ش���ȷ��\n");
		printf("������%d�β����ˡ�\n", max_stage - remain);
	}

	return 0;
}
