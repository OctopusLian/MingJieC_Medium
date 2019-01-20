/* 猜数游戏（其五：显示输入记录）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE	10		/* 最多可以输入的次数 */

int main(void)
{
	int i;
	int stage;				/* 已输入的次数 */
	int no;					/* 读取的值 */
	int ans;				/* 目标数字 */
	int num[MAX_STAGE];		/* 读取的值的历史记录 */

	srand(time(NULL));		/* 设定随机数的种子 */
	ans = rand() % 1000;	/* 生成0~999的随机数 */

	printf("请猜一个0~999的整数。\n\n");

	stage = 0;
	do {
		printf("还剩%d次机会。是多少呢：", MAX_STAGE - stage);
		scanf("%d", &no);
		num[stage++] = no;			/* 把读取的值存入数组 */

		if (no > ans)
			printf("\a再小一点。\n");
		else if (no < ans)
			printf("\a再大一点。\n");
	} while (no != ans && stage < MAX_STAGE);

	if (no != ans)
		printf("\a很遗憾，正确答案是%d。\n", ans);
	else {
		printf("回答正确。\n");
		printf("您用了%d次猜中了。\n", stage);
	}

	puts("\n--- 输入记录 ---");
	for (i = 0; i < stage; i++)
		printf(" %2d : %4d %+4d\n", i + 1, num[i], num[i] - ans);

	return 0;
}
