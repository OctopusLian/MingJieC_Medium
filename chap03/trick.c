/* 计算机一定会赢的猜拳游戏 */

#include <stdio.h>

int main(void)
{
	int i;
	int human;				/* 玩家的手势 */
	int comp;				/* 计算机的手势 */
	int judge;				/* 胜负 */
	int retry;				/* 再来一次？*/
	char *hd[] = {"石头", "剪刀", "布"};		/* 手势 */

	printf("猜拳游戏开始!!\n");

	do {
		do {
			printf("\n\a石头剪刀布 ···");
			for (i = 0; i < 3; i++)
				printf(" (%d)%s", i, hd[i]);
			printf(":");
			scanf("%d", &human);	/* 读取玩家的手势 */
		} while (human < 0 || human > 2);

		comp = (human + 2) % 3;		/* 计算机后出！*/

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
