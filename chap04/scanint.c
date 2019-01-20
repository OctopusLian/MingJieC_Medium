/* 读取并显示整数值 */

#include <stdio.h>

int main(void)
{
	int x;				/* 已读取的值 */

	printf("请输入整数：");
	scanf("%d", &x);

	printf("你输入了%d。\n", x);

	return 0;
}
