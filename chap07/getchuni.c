/* getch��ʹ��ʾ��
   �����ṩ��Curses���UNIX/Linux/OS X���������� */

#include <curses.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int ch;
	int retry;

	initscr();
	cbreak();
	noecho();
	refresh();

	do {
		printf("�밴����");
		fflush(stdout);

		ch = getch();

		printf("\n\r���µļ���%c��ֵ��%d��\n\r",
										isprint(ch) ? ch : ' ', ch);

		printf("����һ�Σ���Y��N����");
		fflush(stdout);
		retry = getch();
		if (isprint(retry))
			putchar(retry);

		putchar('\n');
		fflush(stdout);
	} while (retry == 'Y' || retry == 'y');

	endwin();

	return 0;
}
