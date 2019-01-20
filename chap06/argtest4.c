/* 不用argc来显示程序名和程序形式参数 */

#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;

	while (*argv)
		printf("argv[%d] = \"%s\"\n", i++, *argv++);

	return 0;
}
