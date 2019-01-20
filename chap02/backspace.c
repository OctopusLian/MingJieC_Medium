/* �˸��\b��ʹ��ʾ����ÿ��1����ȥ1���ַ� */

#include <time.h>
#include <stdio.h>

/*--- �ȴ�x���� ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	/* ���� */
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int i;

	printf("ABCDEFG");

	for (i = 0; i < 7; i++) {
		sleep(1000);		/* ÿ��1�� */
		printf("\b \b");	/* �Ӻ�����������ַ� */
		fflush(stdout);		/* ��ջ����� */
	}

	return 0;
}
