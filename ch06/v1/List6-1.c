/*
显示当前日期和时间 
*/

#include<time.h>
#include<stdio.h>

void put_date(const struct tm *timer)
{
	char *wday_name[] = {"日","一","二","三","四","五","六"};
	
	printf("%4d年%02d月%02d日(%s)%02d时%02d分%02d秒",
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
	
	printf("当前日期和时间是");
	put_date(timer);
	printf("。\n");
	
	return 0;
}
