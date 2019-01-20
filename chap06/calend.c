/* ��ʾ��������������ָ��Ҫ��ʾ�����£�*/

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*--- �����·ݵ����� ---*/
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

/*--- �Ƚ��ַ�����ͷ��n���ַ��������ִ�Сд�� ---*/
int strncmpx(const char *s1, const char *s2, size_t n)
{
	while (n && toupper(*s1) && toupper(*s2)) {
		if (toupper(*s1) != toupper(*s2))			/* ����� */
			return (unsigned char)*s1 - (unsigned char)*s2;
		s1++;
		s2++;
		n--;
	}
	if (!n)	 return 0;
	if (*s1) return 1;
	return -1;
}

/*--- ���ַ����л�ȡ�·ݵ�ֵ ---*/
int get_month(char *s)
{
	int i;
	int m;		/* �� */
	char *month[] = {"", "January", "February", "March", "April",
					 "May", "June", "July", "August", "September",
					 "October", "November", "December"};

	m = atoi(s);
	if (m >= 1 && m <= 12)			/* ���ֱ�ʾ��"1", "2", ��, "12" */
		return m;

	for (i = 1; i <= 12; i++)		/* Ӣ���ʾ */
		if (strncmpx(month[i], s, 3) == 0)
			return i;

	return -1;						/* ת��ʧ�� */
}

int main(int argc, char *argv[])
{
	int  y, m;
	time_t t = time(NULL);				/* ��ȡ��ǰʱ�� */
	struct tm *local = localtime(&t);	/* ת���ɷֽ�ʱ�䣨����ʱ�䣩 */

	y = local->tm_year + 1900;			/* �������� */
	m = local->tm_mon + 1;				/* ������·� */

	if (argc >= 2) {				/* argv[1]�Ľ��� */
		m = get_month(argv[1]);
		if (m < 0 || m > 12) {
			fprintf(stderr, "�·ݵ�ֵ����ȷ��\n");
			return 1;
		}
	}
	if (argc >= 3) {				/* argv[2]�Ľ��� */
		y = atoi(argv[2]);
		if (y < 0) {
			fprintf(stderr, "��ݵ�ֵ����ȷ��\n");
			return 1;
		}
	}

	printf("%d��%d��\n\n", y, m);

	put_calendar(y, m);		/* ��ʾy��m�µ����� */

	return 0;
}
