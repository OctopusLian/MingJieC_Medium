/* ����ĸ������ѵ�������3�����������֡�Ӣ����ĸ��*/

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getputch.h"

#define	MAX_STAGE	20					/* ��ս���� */
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	char *qstr[] = {"0123456789",					/* ���� */
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ",	/* ��дӢ����ĸ */
					"abcdefghijklmnopqrstuvwxyz",	/* СдӢ����ĸ */
				   };
	int 	chmax[] = {10, 26, 26};					/* ���Ե��ַ����� */
	int 	i, stage;
	int 	key;							/* �Ѷ�ȡ�ļ���ֵ */
	double	jikan;							/* ʱ�� */
	clock_t	start, end;						/* ��ʼʱ��ͽ���ʱ�� */

	init_getputch();

	srand(time(NULL));						/* �趨����������� */

	printf("��������������3�����ֻ�Ӣ����ĸ��\n");
	printf("������ȥ���ַ���\n");
	printf("��������ʾA?C:��������B\n");
	printf("��������ʾ45?:��������6\n");
	printf("����\n");
	printf("�ﰴ�¿ո����ʼ��\n");
	while (getch() != ' ')
		;

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int qtype = rand() % 3;		/* 0������/1����дӢ����ĸ/2��СдӢ����ĸ */
		int nhead = rand() % (chmax[qtype] - 2);	/* ��ͷ�ַ����±� */
		int x     = rand() % 3;		/* Ҫ��3���ַ��е���һ����Ϊ'?'�� */

		putchar('\r');
		for (i = 0; i < 3; i++) {	/* ��ʾ��Ŀ */
			if (i != x)
				printf(" %c", qstr[qtype][nhead + i]);
			else
				printf(" ?");
		}
		printf(" : ");
		fflush(stdout);

		do {
			key = getch();
			if (isprint(key)) {						/* �������ʾ�Ļ� */
				putch(key);							/* ��ʾ���µļ� */
				if (key != qstr[qtype][nhead + x])	/* ����ش���� */
					putch('\b');					/* �ѹ����ǰ��һ�� */
			}
		} while (key != qstr[qtype][nhead + x]);
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("\n��ʱ%.1f�롣\n", jikan);

	if (jikan > 50.0)
		printf("��Ӧ̫���ˡ�\n");
	else if (jikan > 40.0)
		printf("��Ӧ�е���ѽ��\n");
	else if (jikan > 34.0)
		printf("��Ӧ���аɡ�\n");
	else
		printf("��Ӧ��찡��\n");

	term_getputch();

	return (0);
}
