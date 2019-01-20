/* 珠玑妙算 */

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- 生成4个不同数字的组合并存入数组x ---*/
void make4digits(int x[])
{
	int i, j, val;

	for (i = 0; i < 4; i++) {
		do {
			val = rand() % 10;			/* 0~9的随机数 */
			for (j = 0; j < i; j++)		/* 是否已获得此数值 */
				if (val == x[j])
					break;
		} while (j < i);		/* 循环直至获得不重复的数值 */
		x[i] = val;
	}
}

/*--- 检查已输入的字符串s的有效性 ---*/
int check(const char s[])
{
	int i, j;

	if (strlen(s) != 4)			/* 字符串长度不为4 */
		return 1;

	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return 2;			/* 包含了除数字以外的字符 */
		for (j = 0; j < i; j++)
			if (s[i] == s[j])
				return 3;		/* 含有相同数字 */
	}
	return 0;					/* 字符串有效 */
}

/*--- hit和blow的判断 ---*/
void judge(const char s[], const int no[], int *hit, int *blow)
{
	int i, j;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j])	/* 数字一致 */
				if (i == j)
					(*hit)++;			/* hit（位置也一致）*/
				else
					(*blow)++;			/* blow（位置不一致）*/
		}
	}
}

/*--- 显示判断结果 ---*/
void print_result(int snum, int spos)
{
	if (spos == 4)
		printf("回答正确!!");
	else if (snum == 0)
		printf("    这些数字里没有答案数字。\n");
	else {
		printf("    这些数字里包括%d个答案数字。\n", snum);

		if (spos == 0)
			printf("    但是数字的位置都不一致。\n");
		else
			printf("    其中有%d个数字的位置是一致的。\n", spos);
	}
	putchar('\n');
}

int main(void)
{
	int try_no = 0;		/* 输入次数 */
	int chk;			/* 已输入的字符串的检查结果 */
	int hit;			/* 位置和数字都正确的数字个数 */
	int blow;			/* 数字正确但位置不正确的数字个数 */
	int no[4];			/* 要猜的数字串 */
	char buff[10];		/* 用于存放读取的数字串的字符串 */
	clock_t	start, end;				/* 开始时间/结束时间 */

	srand(time(NULL));				/* 设定随机数种子 */

	puts("■ 来玩珠玑妙算吧。");
	puts("■ 请猜4个数字。");
	puts("■ 其中不包含相同数字。");
	puts("■ 请像4307这样连续输入数字。");
	puts("■ 不能输入空格字符。\n");

	make4digits(no);					/* 生成4个数字各不相同的数字串 */

	start = clock();					/* 开始计算 */

	do {
		do {
			printf("请输入：");
			scanf("%s", buff);			/* 读取为字符串 */

			chk = check(buff);			/* 检查读取到的字符串 */

			switch (chk) {
			 case 1: puts("\a请确保输入4个字符。"); break;
			 case 2: puts("\a请不要输入除了数字以外的字符。"); break;
			 case 3: puts("\a请不要输入相同的数字。"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, no, &hit, &blow);	/* 判断 */
		print_result(hit + blow, hit);	/* 显示判断结果 */

	} while (hit < 4); 

	end = clock();						/* 计算结束 */

	printf("用了%d次。\n用时%.1f秒。\n",
					try_no, (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
