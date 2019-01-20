/* 求星期（其二：利用蔡勒公式）*/

#include <stdio.h>

/*--- year年month月day日是星期几 ---*/
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return (year + year/4 - year/100 + year/400 + (13*month+8)/5 + day) % 7;
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

	printf("这一天是星期%s。\n", ws[w]);

	return 0;
}
