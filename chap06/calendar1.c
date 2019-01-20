/* ��ʾ���� */

#include <stdio.h>

/*--- ���µ����� ---*/
int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*--- year��month��day�������ڼ� ---*/
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return (year + year/4 - year/100 + year/400 + (13*month+8)/5 + day) % 7;
}

/*--- year���������𣿣�0������ƽ��/1���������꣩ ---*/
int is_leap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- year��month�µ�������28��31�� ---*/
int monthdays(int year, int month)
{
	if (month-- != 2)						/* ��month��2��ʱ */
		return mday[month];
	return mday[month] + is_leap(year);		/* ��monthΪ2��ʱ */
}

/*--- ��ʾy��m�µ����� ---*/
void put_calendar(int y, int m)
{
	int i;
	int wd = dayofweek(y, m, 1);	/* y��m��1�ն�Ӧ������ */
	int mdays = monthdays(y, m);	/* y��m�µ����� */

	printf(" �� һ �� �� �� �� �� \n");
	printf("----------------------\n");

	printf("%*s", 3 * wd, "");		/* ��ʾ1�����Ŀո� */

	for (i = 1; i <= mdays; i++) {
		printf("%3d", i);
		if (++wd % 7 == 0)		/* ��ʾ�������� */
			putchar('\n');		/* ���� */
	}
	if (wd % 7 != 0)
		putchar('\n');
}

int main(void)
{
	int y, m;

	printf("��ʾ������\n");
	printf("�꣺");	  scanf("%d", &y);
	printf("�£�");   scanf("%d", &m);

	putchar('\n');

	put_calendar(y, m);		/* ��ʾy��m�µ����� */

	return 0;
}
