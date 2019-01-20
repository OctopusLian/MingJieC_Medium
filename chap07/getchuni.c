/* getch的使用示例
   ※在提供了Curses库的UNIX/Linux/OS X环境下运行 */

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
		printf("请按键。");
		fflush(stdout);

		ch = getch();

		printf("\n\r按下的键是%c，值是%d。\n\r",
										isprint(ch) ? ch : ' ', ch);

		printf("再来一次？（Y／N）：");
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
