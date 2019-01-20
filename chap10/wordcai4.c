/* 单词学习程序（其四：从文件中读取单词）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	CNO		4		/* 选项数量 */

#define swap(type, x, y)   do { type t = x; x = y; y = t; } while (0)

int	QNO;				/* 单词数量 */
char **cptr;			/* 指向中文单词的指针数组 */
char **eptr;			/* 指向英语单词的指针数组 */

/*--- 显示选项 ---*/
void print_cand(const int c[], int sw)
{
	int i;

	for (i = 0; i < CNO; i++)
		printf("(%d) %s  ", i, sw ? cptr[c[i]] : eptr[c[i]]);
	printf("：");
}

/*--- 生成选项并返回正确的下标 ---*/
int make_cand(int c[], int n)
{
	int i, j, x;

	c[0] = n;						/* 在开头元素中存入正确答案 */

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

/*--- 读取单词 ---*/
int read_tango(void)
{
	int	i;
	FILE *fp;

	if ((fp = fopen("TANGO", "r")) == NULL) return 1;

	fscanf(fp, "%d", &QNO);			/* 读取单词数量 */

	if ((cptr = calloc(QNO, sizeof(char *))) == NULL) return 1;
	if ((eptr = calloc(QNO, sizeof(char *))) == NULL) return 1;

	for (i = 0; i < QNO; i++) {
		char etemp[1024];
		char ctemp[1024];

		fscanf(fp, "%s%s", etemp, ctemp);
		if ((eptr[i] = malloc(strlen(etemp) + 1)) == NULL) return 1;
		if ((cptr[i] = malloc(strlen(ctemp) + 1)) == NULL) return 1;
		strcpy(eptr[i], etemp);
		strcpy(cptr[i], ctemp);
	}
	fclose(fp);

	return 0;
}

int main(void)
{
	int i;
	int nq, pq;			/* 题目编号和上一次的题目编号 */
	int na;				/* 正确答案的编号 */
	int sw;				/* 题目语言（0：中文/1：英语）*/
	int retry;			/* 重新挑战吗？*/
	int cand[CNO];		/* 选项的编号 */

	if (read_tango() == 1) {
		printf("\a单词文件读取失败。\n");
		return 1;
	}
	srand(time(NULL));	/* 设定随机数的种子 */

	pq = QNO;			/* 上一次的题目编号（不存在的编号）*/

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
				puts("回答错误。");
		} while (no != na);
		puts("回答正确。");

		pq = nq;

		printf("再来一次？0-否/1-是：");
		scanf("%d", &retry);
	} while (retry == 1);

	for (i = 0; i < QNO; i++) {
		free(eptr[i]);
		free(cptr[i]);
	}
	free(cptr);
	free(eptr);

	return 0;
}
