/* ���ַ���ʹ��ʾ�� */

#include <wchar.h>
#include <stdio.h>
#include <locale.h>

int main(void)
{
	int i;
	wchar_t c = L'a';
	wchar_t *h[3] = {L"ʯͷ", L"����", L"��"};

	setlocale(LC_ALL, "");
	wprintf(L"%lc\n", c);
	for (i = 0; i < 3; i++)
		wprintf(L"h[%d] = %ls\n", i, h[i]);

	return 0;
}
