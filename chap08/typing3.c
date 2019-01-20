/* ���̲������������ϰ��������Լ�˼��Ҫ������ַ���
		��ʾA?DFG�Ļ�������S
		��ʾqwe?t�Ļ�������r						*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define	NO			30			/* ��ϰ���� */
#define	KTYPE		16			/* ���� */

int main(void)
{
	char *kstr[] = {"12345",  "67890-^\\",		/* ��1��         */
					"!\"#$%", "&'() =~|",		/* ��1��[Shift]  */
					"qwert",  "yuiop@[",		/* ��2��         */
					"QWERT",  "YUIOP`{",		/* ��2��[Shift]  */
					"asdfg",  "hjkl;:]",		/* ��3��         */
					"ASDFG",  "HJKL+*}",		/* ��3��[Shift]  */
					"zxcvb",  "nm,./\\",		/* ��4��         */
					"ZXCVB",  "NM<> _",			/* ��4��[Shift]  */
					};
	int 	i, stage;
	clock_t	start, end;			/* ��ʼʱ��ͽ���ʱ�� */

	init_getputch();
	srand(time(NULL));			/* �趨����������� */

	printf("��ʼ��λ���������ϰ��\n");
	printf("�������ã������������ַ���\n");
	printf("���¿ո����ʼ��\n");
	fflush(stdout);
	while (getch() != ' ')
		;

	start = clock();			/* ��ʼʱ�� */

	for (stage = 0; stage < NO; stage++) {
		int  k, p, key;
		char temp[10];

		do {
			k = rand() % KTYPE;
			p = rand() % strlen(kstr[k]);
			key = kstr[k][p];
		} while (key == ' ');

		strcpy(temp, kstr[k]);
		temp[p] = '?';

		printf("%s", temp);
		fflush(stdout);

		while (getch() != key)
			;
		putchar('\n');
	}

	end = clock();				/* ����ʱ�� */

	printf("��ʱ%.1f�롣\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return 0;
}
