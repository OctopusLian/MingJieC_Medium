/* getch��ʹ��ʾ��
   �����ṩ��Visual C++��MS-Windows/MS-DOS���������� */

#include <conio.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int ch;
	int retry;

	do {
		printf("�밴����");
		ch = getch();

		printf("\n���µļ���%c��ֵ��%d��\n",
									  isprint(ch) ? ch : ' ', ch);

		printf("����һ�Σ���Y��N����");
		retry = getch();
		if (isprint(retry))
			putch(retry);

		putchar('\n');

	} while (retry == 'Y' || retry == 'y');

	return 0;
}
