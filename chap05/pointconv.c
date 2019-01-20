/* 指针和类型转换 */

#include  <stdio.h>

int main(void)
{
	double x;
	double *pd;
	char   *pc = &x;

	pc++;

	pd = (double *)pc;

	printf("pc = %p\n", pc);
	printf("pd = %p\n", pd);

	return 0;
}
