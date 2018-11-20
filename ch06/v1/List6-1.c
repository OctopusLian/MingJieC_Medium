/*
��ʾ��ǰ���ں�ʱ�� 
*/

#include<time.h>
#include<stdio.h>

void put_date(const struct tm *timer)
{
	char *wday_name[] = {"��","һ","��","��","��","��","��"};
	
	printf("%4d��%02d��%02d��(%s)%02dʱ%02d��%02d��",
		timer->tm_year + 1900,
		timer->tm_mon + 1,
		timer->tm_mday,
		wday_name[timer->tm_wday],
		timer->tm_hour,
		timer->tm_min,
		timer->tm_sec
	);
}

int main(void)
{
	time_t current;
	struct tm *timer;
	
	time(&current);
	timer = localtime(&current);
	
	printf("��ǰ���ں�ʱ����");
	put_date(timer);
	printf("��\n");
	
	return 0;
}
