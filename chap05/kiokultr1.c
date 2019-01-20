/* 单纯记忆训练（记忆英文字母·其一：只记忆大写字母）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAGE	10				/* 关卡数 */
#define LEVEL_MIN	 3				/* 最低等级（字母个数）*/
#define LEVEL_MAX	20				/* 最高等级（字母个数）*/

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
	int i, stage;
	int level;						/* 等级（数值的位数）*/
	int success = 0;				/* 答对数量 */
	clock_t start, end;				/* 开始时间/结束时间 */
	const char ltr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";	/* 大写的英文字母 */

	srand(time(NULL));				/* 设定随机数的种子 */

	printf("英文字母记忆训练\n");

	do {
		printf("要挑战的等级(%d～%d)：", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	printf("来记忆%d个英文字母吧。\n", level);

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		char mstr[LEVEL_MAX + 1];			/* 需要记忆的一串英文字母 */
		char x[LEVEL_MAX * 2];				/* 读取到的一串英文字母 */

		for (i = 0; i < level; i++)			/* 生成作为题目的字符串 */
			mstr[i] = ltr[rand() % strlen(ltr)];
		mstr[level] = '\0';

		printf("%s", mstr);
		fflush(stdout);
		sleep(125 * level);					/* 问题提示125 × level毫秒 */

		printf("\r%*s\r请输入：", level, "");
		fflush(stdout);
		scanf("%s", x);

		if (strcmp(x, mstr) != 0)
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
