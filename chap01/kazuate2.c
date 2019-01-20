/*猜数游戏（其二：重复到猜对为止——利用do语句）*/

#include <stdio.h>

int main(void)
{
	int no;			/* 读取的值 */
	int ans = 7;	/* 目标数字 */

	printf("请猜一个0~9的整数。\n\n");

	do {
		printf("是多少呢：");
		scanf("%d", &no);

		if (no > ans)
			printf("\a再小一点。\n");
		else if (no < ans)
			printf("\a再大一点。\n");
	} while (no != ans);						/* 重复到猜对为止 */

	printf("回答正确。\n");

	return 0;
}
