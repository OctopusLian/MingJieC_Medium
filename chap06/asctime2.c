/* 显示当前日期和时间（其二[修改]：利用asctime2函数）*/

#include <time.h>
#include <stdio.h>

/*--- 根据asctime函数把分解时间转换成字符串（不添加换行符）---*/
char *asctime2(const struct tm *timeptr)
{
	const char wday_name[7][3] = {					/* 星期 */
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
	};
	const char mon_name[12][3] = {					/* 月份名称 */
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	};
	static char result[25];				/* 用于存储字符串的空间是静态空间 */

	sprintf(result, "%.3s %.3s %02d %02d:%02d:%02d %4d",
					wday_name[timeptr->tm_wday], mon_name[timeptr->tm_mon],
					timeptr->tm_mday, timeptr->tm_hour, timeptr->tm_min,
					timeptr->tm_sec,  timeptr->tm_year + 1900);
	return result;
}

int main(void)
{
	time_t current = time(NULL);	/* 获取当前时间 */

	printf("当前日期和时间是%s。\n", asctime2(localtime(&current)));

	return 0;
}
