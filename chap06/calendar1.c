/* 显示日历 */

#include <stdio.h>

/*--- 各月的天数 ---*/
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

int main(void)
{
	int y, m;

	printf("显示日历。\n");
	printf("年：");	  scanf("%d", &y);
	printf("月：");   scanf("%d", &m);

	putchar('\n');

	put_calendar(y, m);		/* 显示y年m月的日历 */

	return 0;
}
