/* �����һ����Ӯ�Ĳ�ȭ��Ϸ */

#include <stdio.h>

int main(void)
{
	int i;
	int human;				/* ��ҵ����� */
	int comp;				/* ����������� */
	int judge;				/* ʤ�� */
	int retry;				/* ����һ�Σ�*/
	char *hd[] = {"ʯͷ", "����", "��"};		/* ���� */

	printf("��ȭ��Ϸ��ʼ!!\n");

	do {
		do {
			printf("\n\aʯͷ������ ������");
			for (i = 0; i < 3; i++)
				printf(" (%d)%s", i, hd[i]);
			printf(":");
			scanf("%d", &human);	/* ��ȡ��ҵ����� */
		} while (human < 0 || human > 2);

		comp = (human + 2) % 3;		/* ����������*/

		printf("�ҳ�%s�����%s��\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;					/* �ж�ʤ�� */

		switch (judge) {
		 case 0: puts("ƽ�֡�");	break;
		 case 1: puts("�����ˡ�");	break;
		 case 2: puts("��Ӯ�ˡ�");	break;
		}

		printf("����һ���𡤡���(0)�� (1)�ǣ�");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
