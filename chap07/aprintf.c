/* �ᷢ�������ĸ�ʽ������� */

#include <stdio.h>
#include <stdarg.h>

/*--- �ᷢ�������ĸ�ʽ������� ---*/
int aprintf(const char *format, ...)
{
	int 	count;
	va_list	ap;

	putchar('\a');
	va_start(ap, format);
	count = vprintf(format, ap);	/* �ѿɱ������ȫ����vprintf���������� */
	va_end(ap);
	return count;
}

int main(void)
{
	aprintf("Hello!\n");
	aprintf("%d %ld %.2f\n", 2, 3L, 3.14);

	return 0;
}
