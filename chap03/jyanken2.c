/* ��ȭ��Ϸ���������ʾ˫�������ƣ�*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int human;				/* ��ҵ����� */
	int comp;				/* ����������� */
	int judge;				/* ʤ�� */
	int retry;				/* ����һ�Σ�*/

	srand(time(NULL));		/* �趨��������� */

	printf("��ȭ��Ϸ��ʼ!!\n");

	do {
		comp = rand() % 3;		/* ����������ɼ���������ƣ�0~2��*/

		do {
			printf("\n\aʯͷ������������(0)ʯͷ (1)���� (2)����");
			scanf("%d", &human);	/* ��ȡ��ҵ����� */
		} while (human < 0 || human > 2);

		printf("�ҳ�");

		switch (comp) {				/* ��ʾ����������� */
		 case 0: printf("ʯͷ");	break;
		 case 1: printf("����");	break;
		 case 2: printf("��");	    break;
		}

		printf("�����");

		switch (human) {			/* ��ʾ��ҵ����� */
		 case 0: printf("ʯͷ");	break;
		 case 1: printf("����");	break;
		 case 2: printf("��");	    break;
		}

		printf("��\n");

		judge = (human - comp + 3) % 3;					/* �ж�ʤ�� */

		switch (judge) {
		 case 0: puts("ƽ�֡�");    break;
		 case 1: puts("�����ˡ�");	break;
		 case 2: puts("��Ӯ�ˡ�");	break;
		}

		printf("����һ���𡤡���(0)�� (1)�ǣ�");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
