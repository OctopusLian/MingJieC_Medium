/* 最多读取10个值，存入元素个数为10的数组 */

#include <stdio.h>

#define	MAX		10		/* 数组的元素个数 */

int main(void)
{
	int i;
	int a[MAX];			/* 用于存储读取到的值的数组 */
	int cnt = 0;		/* 读取到的个数 */
	int retry;			/* 再来一次？ */

	printf("请输入整数。\n");
	printf("最多能输入%d个。\n", MAX);

	do {
		printf("第%d个整数：", cnt + 1);
		scanf("%d", &a[cnt++]);

		if (cnt == MAX)		/* 把cnt个整数全部输入完毕后 */
			break;			/* 结束 */

		printf("是否继续？(Yes···1／No···0)：");
		scanf("%d", &retry);
	} while (retry == 1);

	for (i = 0; i < cnt; i++)
		printf("第%2d个 : %d\n", i + 1, a[i]);

	return 0;
}
