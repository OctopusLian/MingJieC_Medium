/* ��ʾ��ǰ���ں�ʱ�䣨����������ctime������*/

#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t current = time(NULL);	/* ��ȡ��ǰʱ�� */

	printf("��ǰ���ں�ʱ�䣺%s", ctime(&current));

	return 0;
}
