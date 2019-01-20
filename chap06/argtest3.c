/* 程序名和程序形式参数的显示（其三：以字符为单位遍历命令行参数）*/

#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;
	char c;

	while (argc-- > 0) {
		printf("argv[%d] = \"", i++);
		while (c = *(*argv)++)
			putchar(c);
		argv++;
		printf("\"\n");
	}

	return 0;
}
