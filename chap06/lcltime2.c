/* ��ʾ��ǰ���ں�ʱ�䣨���������asctime������*/

#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t current = time(NULL);	/* ��ȡ��ǰʱ�� */

	printf("��ǰ���ں�ʱ�䣺%s", asctime(localtime(&current)));

	return 0;
}
