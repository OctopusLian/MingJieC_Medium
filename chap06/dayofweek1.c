/* 求星期（其一：利用mktime函数）*/

#include <time.h>
#include <stdio.h>

/*--- 求year年month月day日是星期几 ---*/
int dayofweek(int year, int month, int day)
{
	struct tm t;

	t.tm_year  = year - 1900;	/* 调整年份 */
	t.tm_mon   = month - 1;		/* 调整月份 */
	t.tm_mday  = day;			/* 日 */
	t.tm_hour  = 0;				/* 时 */
	t.tm_min   = 0;				/* 分 */
	t.tm_sec   = 0;				/* 秒 */
	t.tm_isdst = -1;			/* 夏令时 */

	if (mktime(&t) == (time_t)-1)	/* 转换失败的话 */
		return -1;					/* 返回-1 */
	return t.tm_wday;			/* 返回mktime函数设定的星期 */
}

int main(void)
{
	int  y, m, d, w;
	char *ws[] = {"日", "一", "二", "三", "四", "五", "六"};

	printf("求星期。\n");
	printf("年：");   scanf("%d", &y);
	printf("月：");   scanf("%d", &m);
	printf("日：");   scanf("%d", &d);

	w = dayofweek(y, m, d);			/* 求星期 */

	if (w != -1)
		printf("这一天是星期%s。\n", ws[w]);
	else
		printf("无法求出星期。\n");

	return 0;
}
