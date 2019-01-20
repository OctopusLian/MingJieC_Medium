/* 猜拳游戏（其三：导入表示手势的字符串）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int human;				/* 玩家的手势 */
	int comp;				/* 计算机的手势 */
	int judge;				/* 胜负 */
	int retry;				/* 再来一次吗？*/
	char *hd[] = {"石头", "剪刀", "布"};		/* 手势 */

	srand(time(NULL));		/* 设定随机数种子 */

	printf("猜拳游戏开始!!\n");

	do {
		comp = rand() % 3;		/* 用随机数生成计算机的手势（0~2）*/

		do {
			printf("\n\a石头剪刀布 ···");
			for (i = 0; i < 3; i++)
				printf(" (%d)%s", i, hd[i]);
			printf(":");
			scanf("%d", &human);		/* 读取玩家的手势 */
		} while (human < 0 || human > 2);

		printf("我出%s，你出%s。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;					/* 判断胜负 */

		switch (judge) {
		 case 0: puts("平局。");	break;
		 case 1: puts("你输了。");	break;
		 case 2: puts("你赢了。");	break;
		}

		printf("再来一次吗···(0)否 (1)是：");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
