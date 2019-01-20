/* Ѱ���ظ�����ѵ���������ʵʱ�������룩*/

#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "getputch.h"

#define MAX_STAGE	10					/* ��ս���� */
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	int i, j, x, stage;
	int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a[10];
	double jikan;						/* ʱ�� */
	clock_t start, end;					/* ��ʼʱ��ͽ���ʱ�� */

	init_getputch();
	srand(time(NULL));					/* �趨����������� */

	printf("�������ظ������֡�\n");
	printf("���¿ո����ʼ��\n");
	fflush(stdout);
	while (getch() != ' ')
		;

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;		/* ���������0��8 */
		int no;					/* �Ѷ�ȡ��ֵ */

		i = j = 0;
		while (i < 9) {			/* ����ʱ�ظ�dgt[x] */
			a[j++] = dgt[i];
			if (i == x)
				a[j++] = dgt[i];
			i++;
		}

		for (i = 9; i > 0; i--) {	/* ������������a */
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (i = 0; i < 10; i++)	/* ��ʾ����Ԫ�� */
			printf("%d ", a[i]);
		printf("��");
		fflush(stdout);

		do {
			no = getch();
			if (isprint(no)) {			/* �������ʾ�Ļ� */
				putch(no);				/* ��ʾ���µļ� */
				if (no != dgt[x] + '0')	/* ����ش���� */
					putch('\b');		/* �ѹ����ǰ��һ�� */
				else
					printf("\n");		/* ���� */
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("��ʱ%.1f�롣\n", jikan);

	if (jikan > 25.0)
		printf("��Ӧ̫���ˡ�\n");
	else if (jikan > 20.0)
		printf("��Ӧ�е���ѽ��\n");
	else if (jikan > 17.0)
		printf("��Ӧ���аɡ�\n");
	else
		printf("��Ӧ��찡��\n");

	term_getputch();

	return 0;
}
