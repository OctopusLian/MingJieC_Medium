/* ������ĺ���������ʾ����*/

#include <stdio.h>

int wa_sa(int x, int y, int wa, int sa)
{
	wa = x + y;
	sa = x - y;
}

int main(void)
{
	int a = 5, b = 3, p = 1, m = 1;

	wa_sa(a, b, p, m);

	printf("p = %d  m = %d\n", p, m);

	return 0;
}
