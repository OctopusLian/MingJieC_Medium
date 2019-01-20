/* 退格符\b的使用示例：每隔1秒消去1个字符 */

#include <time.h>
#include <stdio.h>

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
	int i;

	printf("ABCDEFG");

	for (i = 0; i < 7; i++) {
		sleep(1000);		/* 每隔1秒 */
		printf("\b \b");	/* 从后面逐个消除字符 */
		fflush(stdout);		/* 清空缓冲区 */
	}

	return 0;
}
