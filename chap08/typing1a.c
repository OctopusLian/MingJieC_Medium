/* 一个字符串的键盘打字练习（其一）*/

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"

int main(void)
{
	int 	i;
	char	*str = "How do you do?";	/* 要输入的字符串 */
	int 	len = strlen(str);			/* 字符串str的字符数量 */
	clock_t start, end;					/* 开始时间和结束时间 */

	init_getputch();

	printf("请照着输入。\n");
	printf("%s\n", str);				/* 显示要输入的字符串 */
	fflush(stdout);

	start = clock();					/* 开始时间 */

	for (i = 0; i < len; i++) {
		int ch;

		do {
			ch = getch();			/* 从键盘读取信息 */
			if (isprint(ch)) {
				putch(ch);			/* 显示按下的键 */
				if (ch != str[i])	/* 如果按错了键 */
					putch('\b');	/* 把光标往前退一格   */
			}
		} while (ch != str[i]);
	}

	end = clock();						/* 结束时间 */

	printf("\n用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return 0;
}
