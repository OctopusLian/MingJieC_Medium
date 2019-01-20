/* 猜数游戏（其三：目标数字是0~999的随机数）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int no;		/* 读取的值 */
	int ans;	/* 目标数字 */

	srand(time(NULL));		/* 设定随机数的种子 */
	ans = rand() % 1000;	/* 生成0~999的随机数 */

	printf("请猜一个0~999的整数。\n\n");

	do {
		printf("是多少呢：");
		scanf("%d", &no);

		if (no > ans)
			printf("\a再小一点。\n");
		else if (no < ans)
			printf("\a再大一点。\n");
	} while (no != ans);					/* 重复到猜对为止 */

	printf("回答正确。\n");

	return 0;
}
