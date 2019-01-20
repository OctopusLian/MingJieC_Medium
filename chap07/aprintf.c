/* 会发出警报的格式输出函数 */

#include <stdio.h>
#include <stdarg.h>

/*--- 会发出警报的格式输出函数 ---*/
int aprintf(const char *format, ...)
{
	int 	count;
	va_list	ap;

	putchar('\a');
	va_start(ap, format);
	count = vprintf(format, ap);	/* 把可变参数完全交由vprintf函数来处理 */
	va_end(ap);
	return count;
}

int main(void)
{
	aprintf("Hello!\n");
	aprintf("%d %ld %.2f\n", 2, 3L, 3.14);

	return 0;
}
