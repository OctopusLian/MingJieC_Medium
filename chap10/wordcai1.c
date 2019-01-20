/* 英语单词学习软件（测试版：随机显示中文单词/英语单词）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define	QNO	   12		/* 单词的数量 */

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

int main(void)
{
	int nq, pq;			/* 题目编号和上一次的题目编号 */
	int sw;				/* 0：中文/1：英语 */
	int retry;			/* 重新挑战吗？*/

	srand(time(NULL));	/* 设定随机数的种子 */

	pq = QNO;			/* 上一次的题目编号（不存在的编号） */

	do {
		do {					/* 不连续出同一个单词 */
			nq = rand() % QNO;
		} while (nq == pq);

		sw = rand() % 2;		/* 中文或者英语 */

		printf("%s\n", sw ? eptr[nq] : cptr[nq]);

		pq = nq;

		printf("再来一次？0-否/1-是：");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
