/* 同时训练扩大水平方向视野的心算训练 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int stage;
	int a, b, c;			/* 要进行加法运算的数值 */
	int x;					/* 已读取的值 */
	int n;					/* 空白的宽度 */
	clock_t	start, end;		/* 开始时间·结束时间 */

	srand(time(NULL));		/* 设定随机数的种子 */

	printf("扩大视野心算训练开始!!\n");
	start = clock();				/* 开始计算 */

	for (stage = 0; stage < 10; stage++) {
		a = 10 + rand() % 90;		/* 生成10～99的随机数 */
		b = 10 + rand() % 90;		/* 　　　　〃　　　　 */
		c = 10 + rand() % 90;		/* 　　　　〃　　　　 */
		n = rand() % 17;			/* 生成0～16的随机数  */

		printf("%d%*s+%*s%d%*s+%*s%d：", a, n, "", n, "", b, n, "", n, "", c);

		do {
			scanf("%d", &x);
			if (x == a + b + c)
				break;
			printf("\a回答错误。请重新输入：");
		} while (1);
	}

	end = clock();					/* 计算结束 */

	printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
