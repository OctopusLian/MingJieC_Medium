/* 读取想要的数量，把最后10个存入元素个数为10的数组（其一）*/

#include <stdio.h>

#define	MAX		10			/* 数组的元素个数 */

int main(void)
{
	int i;
	int a[MAX];				/* 用于存储已读取的值的数组 */
	int cnt = 0;			/* 读取到的个数 */
	int retry;				/* 再来一次？ */

	printf("请输入整数。\n");

	do {
		if (cnt >= MAX) {		/* 在读取第MAX + 1个值及其后续值之前 */
			for (i = 0; i < MAX - 1; i++)	/* 把元素a[1] ~ a[MAX - 1] */
				a[i] = a[i + 1];			/* 往前移动一个位置 */
		}
		printf("第%d个整数：", cnt + 1);
		scanf("%d", &a[cnt < MAX ? cnt : MAX - 1]);
		cnt++;

		printf("是否继续？（Yes···1／No···0）：");
		scanf("%d", &retry);
	} while (retry == 1);

	if (cnt <= MAX)					/* 读取的值不超过MAX个 */
		for (i = 0; i < cnt; i++)
			printf("第%2d个 : %d\n", i + 1, a[i]);
	else							/* 读取的值超过MAX个 */
		for (i = 0; i < MAX; i++)
			printf("第%2d个 : %d\n", cnt - MAX + 1 + i, a[i]);

	return 0;
}
