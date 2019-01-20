/* 英语单词学习软件 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define QNO  12		/* 单词的数量 */
#define CNO   4		/* 选项的数量 */

#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

/*--- 中文 ---*/
char *cptr[] = {
	"动物", "汽车",	"花",	"家",	"桌子",	"书",
	"椅子", "爸爸",	"妈妈",	"爱",	"和平",	"杂志",
};

/*--- 英语 ---*/
char *eptr[] = {
	"animal", "car",	"flower", "house", "desk",	"book",
	"chair",  "father",	"mother", "love",  "peace",	"magazine",
};

/*--- 显示选项 ---*/
void print_cand(const int c[], int sw)
{
	int i;

	for (i = 0; i < CNO; i++)
		printf("(%d) %s  ", i, sw ? cptr[c[i]] : eptr[c[i]]);
	printf("：");
}

/*--- 生成选项并返回正确答案的下标 ---*/
int make_cand(int c[], int n)
{
	int i, j, x;

	c[0] = n;						/* 把正确答案存入开头元素 */

	for (i = 1; i < CNO; i++) {
		do {						/* 生成不重复的随机数 */
			x = rand() % QNO;
			for (j = 0; j < i; j++)
				if (c[j] == x)		/* 已经生成了相同的随机数 */
					break;
		} while (i != j);
		c[i] = x;
	}

	j = rand() % CNO;
	if (j != 0)
		swap(int, c[0], c[j]);	/* 移动正确答案 */

	return j;
}

int main(void)
{
	int nq, pq;			/* 题目编号和上一次的题目编号 */
	int na;				/* 正确答案的编号 */
	int sw;				/* 题目的语言（0：中文/1：英语）*/
	int retry;			/* 重新挑战吗？*/
	int cand[CNO];		/* 选项的编号 */

	srand(time(NULL));	/* 设定随机数的种子 */

	pq = QNO;			/* 上一次的题目编号（不存在的编号） */

	do {
		int no;

		do {						/* 决定用于出题的单词的编号 */
			nq = rand() % QNO;
		} while (nq == pq);			/* 不连续出同一个单词 */

		na = make_cand(cand, nq);	/* 生成选项 */
		sw = rand() % 2;

		printf("哪一个是%s？\n", sw ? eptr[nq] : cptr[nq]);

		do {
			print_cand(cand, sw);	/* 显示选项 */
			scanf("%d", &no);
			if (no != na)
				puts("\a回答错误。");
		} while (no != na);
		puts("回答正确。");

		pq = nq;

		printf("再来一次？0-否/1-是：");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}