/* 寻找幸运数字训练（其二：数字随机排列）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE	10			/* 挑战次数 */
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	int i, j, stage;
	int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a[8];
	double jikan;				/* 时间 */
	clock_t start, end;			/* 开始时间和结束时间 */

	srand(time(NULL));			/* 设定随机数的种子 */

	printf("请输入缺少的数字。\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;		/* 生成随机数0~8 */
		int no;					/* 读取的值 */

		i = j = 0;
		while (i < 9) {			/* 复制时跳过dgt[x] */
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {			/* 重新排列数组a */
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (i = 0; i < 8; i++)		/* 显示所有元素 */
			printf("%d ", a[i]);
		printf("：");

		do {
			scanf("%d", &no);
		} while (no != dgt[x]);		/* 循环到玩家输入正确答案为止 */
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

	return 0;
}
