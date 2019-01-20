/* 显示日历（用命令行指定要显示的年月）*/

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*--- 各个月份的天数 ---*/
int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*--- year年month月day日是星期几 ---*/
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return (year + year/4 - year/100 + year/400 + (13*month+8)/5 + day) % 7;
}

/*--- year年是闰年吗？（0···平年/1···闰年） ---*/
int is_leap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- year年month月的天数（28～31） ---*/
int monthdays(int year, int month)
{
	if (month-- != 2)						/* 当month非2月时 */
		return mday[month];
	return mday[month] + is_leap(year);		/* 当month为2月时 */
}

/*--- 显示y年m月的日历 ---*/
void put_calendar(int y, int m)
{
	int i;
	int wd = dayofweek(y, m, 1);	/* y年m月1日对应的星期 */
	int mdays = monthdays(y, m);	/* y年m月的天数 */

	printf(" 日 一 二 三 四 五 六 \n");
	printf("----------------------\n");

	printf("%*s", 3 * wd, "");		/* 显示1日左侧的空格 */

	for (i = 1; i <= mdays; i++) {
		printf("%3d", i);
		if (++wd % 7 == 0)		/* 显示星期六后 */
			putchar('\n');		/* 换行 */
	}
	if (wd % 7 != 0)
		putchar('\n');
}

/*--- 比较字符串开头的n个字符（不区分大小写） ---*/
int strncmpx(const char *s1, const char *s2, size_t n)
{
	while (n && toupper(*s1) && toupper(*s2)) {
		if (toupper(*s1) != toupper(*s2))			/* 不相等 */
			return (unsigned char)*s1 - (unsigned char)*s2;
		s1++;
		s2++;
		n--;
	}
	if (!n)	 return 0;
	if (*s1) return 1;
	return -1;
}

/*--- 从字符串中获取月份的值 ---*/
int get_month(char *s)
{
	int i;
	int m;		/* 月 */
	char *month[] = {"", "January", "February", "March", "April",
					 "May", "June", "July", "August", "September",
					 "October", "November", "December"};

	m = atoi(s);
	if (m >= 1 && m <= 12)			/* 数字表示："1", "2", …, "12" */
		return m;

	for (i = 1; i <= 12; i++)		/* 英语表示 */
		if (strncmpx(month[i], s, 3) == 0)
			return i;

	return -1;						/* 转换失败 */
}

int main(int argc, char *argv[])
{
	int  y, m;
	time_t t = time(NULL);				/* 获取当前时间 */
	struct tm *local = localtime(&t);	/* 转换成分解时间（本地时间） */

	y = local->tm_year + 1900;			/* 今天的年份 */
	m = local->tm_mon + 1;				/* 今天的月份 */

	if (argc >= 2) {				/* argv[1]的解析 */
		m = get_month(argv[1]);
		if (m < 0 || m > 12) {
			fprintf(stderr, "月份的值不正确。\n");
			return 1;
		}
	}
	if (argc >= 3) {				/* argv[2]的解析 */
		y = atoi(argv[2]);
		if (y < 0) {
			fprintf(stderr, "年份的值不正确。\n");
			return 1;
		}
	}

	printf("%d年%d月\n\n", y, m);

	put_calendar(y, m);		/* 显示y年m月的日历 */

	return 0;
}
