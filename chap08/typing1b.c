/* һ���ַ����ļ��̴�����ϰ���������ȥ��������ַ���*/

#include <time.h>
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

	start = clock();					/* ��ʼʱ�� */

	for (i = 0; i < len; i++) {
		/* ��ʾstr[i]�Ժ���ַ����ѹ�귵�ص���ͷ */
		printf("%s \r", &str[i]);

		fflush(stdout);
		while (getch() != str[i])
			;
	}

	end = clock();						/* ����ʱ�� */
 
	printf("\r��ʱ%.1f�롣\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return 0;
}