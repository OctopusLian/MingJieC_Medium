/* ����ַ����ļ��̴�����ϰ����������ҳ���˳�򡰷���������*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define QNO		12		/* ��Ŀ���� */

#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	char *str[QNO] = {"book",   "computer", "default",  "comfort",
					  "monday", "power",    "light",    "music", 
					  "programming", "dog", "video",    "include"};
	int i, stage;
	clock_t	start, end;				/* ��ʼʱ��ͽ���ʱ�� */

	init_getputch();
	srand(time(NULL));				/* �趨����������� */

	for (i = QNO - 1; i > 0; i--) {	/* ������������str */
		int j = rand() % (i + 1);
		if (i != j)
			swap(char *, str[i], str[j]);
	}

	printf("��ʼ������ϰ��\n");
	printf("���¿ո����ʼ��\n");
	while (getch() != ' ')			/* һֱ�ȴ��� */
		;							/* ��Ұ��¿ո�� */

	start = clock();				/* ��ʼʱ�� */

	for (stage = 0; stage < QNO; stage++) {
		int len = strlen(str[stage]);	/* �ַ���str[stage]���ַ����� */
		for (i = 0; i < len; i++) {
			/* ��ʾstr[stage][i]֮����ַ����ѹ�귵�ص���ͷ */
			printf("%s \r", &str[stage][i]);

			fflush(stdout);
			while (getch() != str[stage][i])
				;
		}
	}

	end = clock();					/* ����ʱ�� */

	printf("\r��ʱ%.1f�롣\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return 0;
}
