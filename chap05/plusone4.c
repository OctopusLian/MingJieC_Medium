/* 加一训练（其四）
     － 显示最后的MAX_RECORD关卡的答对数量 －				*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define LEVEL_MIN	 2				/* 最低等级（数值的个数）*/
#define LEVEL_MAX	 5				/* 最高等级（数值的个数）*/
#define	MAX_RECORD	10				/* 记录得分的关卡数 */

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
	int i, j, stage, stage2;
	int level;						/* 等级 */
	int success;					/* 答对数量 */
	int point[MAX_RECORD];			/* 得分 */
	int retry;						/* 再来一次？*/
	clock_t	start, end;				/* 开始时间/结束时间 */

	srand(time(NULL));				/* 设定随机数的种子 */

	printf("记忆数值并输入这些数值加1后的值。\n");

	do {
		printf("要挑战的等级(%d～%d)：", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	success = stage = 0;
	start = clock();
	do {
		int no[LEVEL_MAX];		/* 要记忆的数值 */
		int x[LEVEL_MAX];		/* 已读取的值 */
		int seikai = 0;			/* 本关卡的答对数量 */

		printf("\n第%d关卡开始!!\n", stage + 1);

		for (i = 0; i < level; i++) {		/* 仅level个 */
			no[i] = rand() % 90 + 10;		/* 生成10 ~ 99的随机数 */
			printf("%d ", no[i]);			/* 显示 */
		}
		fflush(stdout);
		sleep(300 * level);					/* 等待0.30 × level秒 */
		printf("\r%*s\r", 3 * level, "");	/* 消除题目 */
		fflush(stdout);

		for (i = 0; i < level; i++) {		/* 读取答案 */
			printf("第%d个数：", i + 1);
			scanf("%d", &x[i]);
		}

		for (i = 0; i < level; i++) {		/* 判断对错并显示 */
			if (x[i] != no[i] + 1)
				printf("× ");
			else {
				printf("○ ");
				seikai++;
			}
		}
		putchar('\n');

		for (i = 0; i < level; i++)			/* 显示正确答案 */
			printf("%2d ", no[i]);

		printf(" ··· 答对了%d个。\n", seikai);

		point[stage++ % MAX_RECORD] = seikai;	/* 记录关卡的答对数量 */
		success += seikai;						/* 更新整体的答对数量 */

		printf("是否继续？（Yes···1／No···0）：");
		scanf("%d", &retry);
	} while (retry == 1);
	end = clock();

	printf("\n■□ 成绩 □■\n");

	stage2 = stage - MAX_RECORD;
	if (stage2 < 0) stage2 = 0;

	for (i = level; i >= 1; i--) {
		for (j = stage2; j < stage; j++)
			if (point[j % MAX_RECORD] >= i)
				printf(" ★ ");
			else
				printf("    ");
		putchar('\n');
	}
	printf("-----------------------------------------\n");

	for (j = stage2; j < stage; j++)
		printf(" %02d ", j + 1);
	putchar('\n');

	printf("%d个中答对了%d个。\n", level * stage, success);
	printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
