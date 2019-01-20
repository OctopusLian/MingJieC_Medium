/* 回车符\r的使用示例：重写行 */

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
	printf("My name is BohYoh.");
	fflush(stdout);

	sleep(2000);
	printf("\rHow do you do?    ");
	fflush(stdout);

	sleep(2000);
	printf("\rThanks.           ");

	return 0;
}
