/* ������Ϸ�����壺��ʾ�����¼��*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE	10		/* ����������Ĵ��� */

int main(void)
{
	int i;
	int stage;				/* ������Ĵ��� */
	int no;					/* ��ȡ��ֵ */
	int ans;				/* Ŀ������ */
	int num[MAX_STAGE];		/* ��ȡ��ֵ����ʷ��¼ */

	srand(time(NULL));		/* �趨����������� */
	ans = rand() % 1000;	/* ����0~999������� */

	printf("���һ��0~999��������\n\n");

	stage = 0;
	do {
		printf("��ʣ%d�λ��ᡣ�Ƕ����أ�", MAX_STAGE - stage);
		scanf("%d", &no);
		num[stage++] = no;			/* �Ѷ�ȡ��ֵ�������� */

		if (no > ans)
			printf("\a��Сһ�㡣\n");
		else if (no < ans)
			printf("\a�ٴ�һ�㡣\n");
	} while (no != ans && stage < MAX_STAGE);

	if (no != ans)
		printf("\a���ź�����ȷ����%d��\n", ans);
	else {
		printf("�ش���ȷ��\n");
		printf("������%d�β����ˡ�\n", stage);
	}

	puts("\n--- �����¼ ---");
	for (i = 0; i < stage; i++)
		printf(" %2d : %4d %+4d\n", i + 1, num[i], num[i] - ans);

	return 0;
}
