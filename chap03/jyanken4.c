/* 猜拳游戏（其四：分割函数/显示成绩）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int human;		/* 玩家的手势 */
int comp;		/* 计算机的手势 */
int win_no;		/* 胜利次数 */
int lose_no;	/* 失败次数 */
int draw_no;	/* 平局次数 */

char *hd[] = {"石头", "剪刀", "布"};		/* 手势 */

/*--- 初始处理 ---*/
void initialize(void)
{
	win_no  = 0;		/* 胜利次数 */
	lose_no = 0;		/* 失败次数 */
	draw_no = 0;		/* 平局次数 */

	srand(time(NULL));	/* 设定随机数种子 */

	printf("猜拳游戏开始!!\n");
}

/*--- 运行猜拳游戏（读取/生成手势）---*/
void jyanken(void)
{
	int i;

	comp = rand() % 3;		/* 用随机数生成计算机的手势（0~2）*/

	do {
		printf("\n\a石头剪刀布 ···");
		for (i = 0; i < 3; i++)
			printf(" (%d)%s", i, hd[i]);
		printf(":");
		scanf("%d", &human);		/* 读取玩家的手势 */
	} while (human < 0 || human > 2);
}

/*--- 更新胜利/失败/平局次数 ---*/
void count_no(int result)
{
	switch (result) {
	 case 0: draw_no++;	 break;						/* 平局 */
	 case 1: lose_no++;	 break;						/* 失败 */
	 case 2: win_no++;   break;						/* 胜利 */
	}
}

/*--- 显示判断结果 ---*/
void disp_result(int result)
{
	switch (result) {
	 case 0: puts("平局。");	 break;	 /* 平局 */
	 case 1: puts("你输了。");   break;	 /* 失败 */
	 case 2: puts("你赢了。");   break;	 /* 胜利 */
	}
}

/*--- 确认是否再次挑战 ---*/
int confirm_retry(void)
{
	int x;

	printf("再来一次吗···(0)否 (1)是：");
	scanf("%d", &x);

	return x;
}

int main(void)
{
	int judge;				/* 胜负 */
	int retry;				/* 再来一次？*/

	initialize();						/* 初始处理 */

	do {
		jyanken();						/* 运行猜拳游戏 */

		/* 显示计算机和玩家的手势 */
		printf("我出%s，你出%s。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;	/* 判断胜负 */

		count_no(judge);				/* 更新胜利/失败/平局次数 */

		disp_result(judge);				/* 显示判断结果 */

		retry = confirm_retry();		/* 确认是否再次挑战 */

	} while (retry == 1);

	printf("%d胜%d负%d平。\n", win_no, lose_no, draw_no);

	return 0;
}
