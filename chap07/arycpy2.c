/* ���Ʋ���ʾ���飨����һ��Ԫ�أ�*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, x;
	int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a[8] = {0};

	srand(time(NULL));	/* �趨����������� */

	x = rand() % 9;		/* xΪ0~8������� */

	i = j = 0;
	while (i < 9) {				/* ����ʱ����dgt[x] */
		if (i != x)
			a[j++] = dgt[i];
		i++;
	}

	for (i = 0; i < 8; i++)				/* ��ʾ����Ԫ�� */
		printf("%d ", a[i]);

	putchar('\n');

	return 0;
}
