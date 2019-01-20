/* 逐个显示字符，待字符串显示完毕后，再从后往前逐个消去字符，反复执行此操作 */

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
	char name[] = "BohYoh Shibata";			/* 要显示的字符串 */
	int  name_len = strlen(name);			/* 字符串name的字符数 */

	while (1) {		/* 无限循环 */
		for (i = 0; i < name_len; i++) {	/* 从开头开始逐个显示字符 */
			putchar(name[i]);
			fflush(stdout);
			sleep(500);
		}
		for (i = 0; i < name_len; i++) {	/* 从末尾开始逐个消去字符 */
			printf("\b \b");
			fflush(stdout);
			sleep(500);
		}
	}
	return 0;
}
