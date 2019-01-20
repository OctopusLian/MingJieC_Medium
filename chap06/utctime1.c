/* 用协调世界时显示当前日期和时间 */

#include <time.h>
#include <stdio.h>

/*--- 显示日期和时间 ---*/
void put_date(const struct tm *timer)
{
	char *wday_name[] = {"日", "一", "二", "三", "四", "五", "六"};

	printf("%4d年%02d月%02d日(%s)%02d时%02d分%02d秒",
			timer->tm_year + 1900,		/* 年 */
			timer->tm_mon + 1,			/* 月 */
			timer->tm_mday, 			/* 日 */
			wday_name[timer->tm_wday],	/* 星期 */
			timer->tm_hour,				/* 时*/
			timer->tm_min,				/* 分*/
			timer->tm_sec				/* 秒*/
		  );
}

int main(void)
{
	time_t current;					/* 日历时间（单独的算数型） */
	struct tm *timer;				/* 分解时间（结构体） */

	time(&current);					/* 获取当前时间 */
	timer = gmtime(&current);		/* 转换成分解时间（协调世界时） */

	printf("当前日期和时间用UTC表示是");
	put_date(timer);
	printf("。\n");

	return 0;
}
