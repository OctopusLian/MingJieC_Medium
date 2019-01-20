/* 程序名和程序形式参数的显示（其二：以字符串为单位遍历命令行参数）*/

#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;

	while (argc-- > 0)
		printf("argv[%d] = \"%s\"\n", i++, *argv++);

	return 0;
}
