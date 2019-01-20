/* ��ȭ��Ϸ�����ģ��ָ��/��ʾ�ɼ���*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int human;		/* ��ҵ����� */
int comp;		/* ����������� */
int win_no;		/* ʤ������ */
int lose_no;	/* ʧ�ܴ��� */
int draw_no;	/* ƽ�ִ��� */

char *hd[] = {"ʯͷ", "����", "��"};		/* ���� */

/*--- ��ʼ���� ---*/
void initialize(void)
{
	win_no  = 0;		/* ʤ������ */
	lose_no = 0;		/* ʧ�ܴ��� */
	draw_no = 0;		/* ƽ�ִ��� */

	srand(time(NULL));	/* �趨��������� */

	printf("��ȭ��Ϸ��ʼ!!\n");
}

/*--- ���в�ȭ��Ϸ����ȡ/�������ƣ�---*/
void jyanken(void)
{
	int i;

	comp = rand() % 3;		/* ����������ɼ���������ƣ�0~2��*/

	do {
		printf("\n\aʯͷ������ ������");
		for (i = 0; i < 3; i++)
			printf(" (%d)%s", i, hd[i]);
		printf(":");
		scanf("%d", &human);		/* ��ȡ��ҵ����� */
	} while (human < 0 || human > 2);
}

/*--- ����ʤ��/ʧ��/ƽ�ִ��� ---*/
void count_no(int result)
{
	switch (result) {
	 case 0: draw_no++;	 break;						/* ƽ�� */
	 case 1: lose_no++;	 break;						/* ʧ�� */
	 case 2: win_no++;   break;						/* ʤ�� */
	}
}

/*--- ��ʾ�жϽ�� ---*/
void disp_result(int result)
{
	switch (result) {
	 case 0: puts("ƽ�֡�");	 break;	 /* ƽ�� */
	 case 1: puts("�����ˡ�");   break;	 /* ʧ�� */
	 case 2: puts("��Ӯ�ˡ�");   break;	 /* ʤ�� */
	}
}

/*--- ȷ���Ƿ��ٴ���ս ---*/
int confirm_retry(void)
{
	int x;

	printf("����һ���𡤡���(0)�� (1)�ǣ�");
	scanf("%d", &x);

	return x;
}

int main(void)
{
	int judge;				/* ʤ�� */
	int retry;				/* ����һ�Σ�*/

	initialize();						/* ��ʼ���� */

	do {
		jyanken();						/* ���в�ȭ��Ϸ */

		/* ��ʾ���������ҵ����� */
		printf("�ҳ�%s�����%s��\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;	/* �ж�ʤ�� */

		count_no(judge);				/* ����ʤ��/ʧ��/ƽ�ִ��� */

		disp_result(judge);				/* ��ʾ�жϽ�� */

		retry = confirm_retry();		/* ȷ���Ƿ��ٴ���ս */

	} while (retry == 1);

	printf("%dʤ%d��%dƽ��\n", win_no, lose_no, draw_no);

	return 0;
}
