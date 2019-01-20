/* 把读取到的字符串形式的整数转换为数值并显示 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char temp[20];		/* 用于读取的字符串 */

	printf("请输入整数：");
	scanf("%s", temp);

	printf("你输入了%d。\n", atoi(temp));

	return 0;
}
