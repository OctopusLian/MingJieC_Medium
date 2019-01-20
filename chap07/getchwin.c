/* getch的使用示例
   ※在提供了Visual C++的MS-Windows/MS-DOS环境下运行 */

#include <conio.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int ch;
	int retry;

	do {
		printf("请按键。");
		ch = getch();

		printf("\n按下的键是%c，值是%d。\n",
									  isprint(ch) ? ch : ' ', ch);

		printf("再来一次？（Y／N）：");
		retry = getch();
		if (isprint(retry))
			putch(retry);

		putchar('\n');

	} while (retry == 'Y' || retry == 'y');

	return 0;
}
