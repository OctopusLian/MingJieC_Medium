/* 键盘布局联想打字练习（让玩家自己思考要输入的字符）
		显示A?DFG的话就输入S
		显示qwe?t的话就输入r						*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define	NO			30			/* 练习次数 */
#define	KTYPE		16			/* 块数 */

int main(void)
{
	char *kstr[] = {"12345",  "67890-^\\",		/* 第1层         */
					"!\"#$%", "&'() =~|",		/* 第1层[Shift]  */
					"qwert",  "yuiop@[",		/* 第2层         */
					"QWERT",  "YUIOP`{",		/* 第2层[Shift]  */
					"asdfg",  "hjkl;:]",		/* 第3层         */
					"ASDFG",  "HJKL+*}",		/* 第3层[Shift]  */
					"zxcvb",  "nm,./\\",		/* 第4层         */
					"ZXCVB",  "NM<> _",			/* 第4层[Shift]  */
					};
	int 	i, stage;
	clock_t	start, end;			/* 开始时间和结束时间 */

	init_getputch();
	srand(time(NULL));			/* 设定随机数的种子 */

	printf("开始键位联想打字练习。\n");
	printf("请输入用？隐藏起来的字符。\n");
	printf("按下空格键开始。\n");
	fflush(stdout);
	while (getch() != ' ')
		;

	start = clock();			/* 开始时间 */

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

	end = clock();				/* 结束时间 */

	printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

	term_getputch();

	return 0;
}
