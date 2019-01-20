/* һ���ַ����ļ��̴�����ϰ����һ��*/

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"

int main(void)
{
	int 	i;
	char	*str = "How do you do?";	/* Ҫ������ַ��� */
	int 	len = strlen(str);			/* �ַ���str���ַ����� */
	clock_t start, end;					/* ��ʼʱ��ͽ���ʱ�� */

	init_getputch();

	printf("���������롣\n");
	printf("%s\n", str);				/* ��ʾҪ������ַ��� */
	fflush(stdout);

	start = clock();					/* ��ʼʱ�� */

	for (i = 0; i < len; i++) {
		int ch;

		do {
			ch = getch();			/* �Ӽ��̶�ȡ��Ϣ */
			if (isprint(ch)) {
				putch(ch);			/* ��ʾ���µļ� */
				if (ch != str[i])	/* ��������˼� */
					putch('\b');	/* �ѹ����ǰ��һ��   */
			}
		} while (ch != str[i]);
	}

	end = clock();						/* ����ʱ�� */

	printf("\n��ʱ%.1f�롣\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return 0;
}
