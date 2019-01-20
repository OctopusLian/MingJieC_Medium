/* 寻找幸运数字训练（其三：显示上一次的日期和最高得分）*/

#include <time.h>
#include <float.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "getputch.h"

#define MAX_STAGE	10
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

char dtfile[] = "LACKNUM.DAT";				/* 文件名 */

/*--- 获取并显示上一次的训练信息，返回最高得分 ---*/
double get_data(void)
{
	FILE *fp;
	double best;		/* 最高得分 */

	if ((fp = fopen(dtfile, "r")) == NULL) {
		printf("你是第一次运行本程序吧。\n\n");
		best = DBL_MAX;
	} else {
		int year, month, day, h, m, s;

		fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);
		fscanf(fp, "%lf", &best);
		printf("上次结束程序是在%d年%d月%d日%d时%d分%d秒。\n",
											year, month, day, h, m, s);

		printf("历史最高得分（所用最短时间）为%.1f秒。\n\n", best);
		fclose(fp);
	}

	return best;
}

/*--- 写入本次训练信息 ---*/
void put_data(double best)
{
	FILE *fp;
	time_t t = time(NULL);
	struct tm *local = localtime(&t);

	if ((fp = fopen(dtfile, "w")) == NULL)
		printf("发生错误!!");
	else {
		fprintf(fp, "%d %d %d %d %d %d\n",
					local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
					local->tm_hour,		   local->tm_min,	  local->tm_sec);

		fprintf(fp, "%f\n", best);
		fclose(fp);
	}
}

/*--- 运行训练程序并返回得分（所用时间） ---*/
double go(void)
{
	int i, j, stage;
	int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a[8];
	double jikan;				/* 时间 */
	clock_t start, end;			/* 开始时间和结束时间 */

	printf("请输入缺少的数字。\n");
	printf("按下空格键开始。\n");
	while (getch() != ' ')
		;

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;		/* 生成随机数0 ~ 8 */
		int	no;					/* 已读取的值 */

		i = j = 0;
		while (i < 9) {			/* 复制时跳过dgt[x] */
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {		/* 重新排列数组a */
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (i = 0; i < 8; i++)		/* 显示所有元素 */
			printf("%d ", a[i]);
		printf("：");
		fflush(stdout);

		do {
			no = getch();
			if (isprint(no)) {				/* 如果能显示的话 */
				putch(no);					/* 显示按下的键 */
				if (no != dgt[x] + '0')		/* 如果回答错误 */
					putch('\b');			/* 把光标往前退一格 */
				else
					printf("\n");			/* 换行 */
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("用时%.1f秒。\n", jikan);

	if (jikan > 25.0)
		printf("反应太慢了。\n");
	else if (jikan > 20.0)
		printf("反应有点慢呀。\n");
	else if (jikan > 17.0)
		printf("反应还行吧。\n");
	else
		printf("反应真快啊。\n");

	return jikan;
}

int main(void)
{
	int retry;		/* 再来一次？*/
	double score;	/* 得分（所用时间）*/
	double best;	/* 最高得分（所用最短时间）*/

	best = get_data();			/* 获取历史最高得分 */

	init_getputch();
	srand(time(NULL));			/* 设定随机数的种子 */

	do {
		score = go();			/* 运行训练程序 */

		if (score < best) {
			printf("更新了最高得分（所用时间）!!\n");
			best = score;		/* 更新最高得分 */
		}

		printf("再来一次吗···(0)否(1)是：");
		scanf("%d", &retry);
	} while (retry == 1);

	put_data(best);				/* 写入本次训练的日期、时间以及得分 */

	term_getputch();

	return 0;
}
