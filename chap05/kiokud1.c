/* 单纯记忆训练（记忆4位数）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE	10							/* 关卡数 */

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
	int stage;
	int success = 0;						/* 答对数量 */
	clock_t start, end;						/* 开始时间/结束时间 */

	srand(time(NULL));						/* 设定随机数的种子 */

	printf("来记忆一个4位的数值吧。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x;								/* 已读取的值 */
		int no = rand() % 9000 + 1000;		/* 需要记忆的数值 */

		printf("%d", no);
		fflush(stdout);
		sleep(500);	/* 问题只提示0.5秒 */

		printf("\r请输入：");
		fflush(stdout);
		scanf("%d", &x);

		if (x != no)
			printf("\a回答错误。\n");
		else {
			printf("回答正确。\n");
			success++;
		}
	}
	end = clock();

	printf("%d次中答对了%d次。\n", MAX_STAGE, success);
	printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
