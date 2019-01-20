/* 用字幕显示名字（其一：从右往左滚动字符）*/

#include <time.h>
#include <stdio.h>
#include <string.h>

/*--- 等待x毫秒 ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	/* 错误 */
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int  i;
	int  cnt = 0;					/* 第几个字符在最前面 */
	char name[] = "BohYoh ";		/* 要显示的字符串 */
	int  name_len = strlen(name);	/* 字符串name的字符数 */

	while (1) {
		putchar('\r');				/* 把光标移到本行开头 */

		for (i = 0; i < name_len; i++) {
			if (cnt + i < name_len)
				putchar(name[cnt + i]);
			else
				putchar(name[cnt + i - name_len]);
		}

		fflush(stdout);
		sleep(500);

		if (cnt < name_len - 1)
			cnt++;					/* 下次从后一个字符开始显示 */
		else
			cnt = 0;				/* 下次从最前面的字符开始显示 */
	}

	return 0;
}
