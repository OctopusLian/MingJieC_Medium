/* ������ʾ���3���µ����� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/*--- ��y��m�µ����������ά����s�� ---*/
void make_calendar(int y, int m, char s[7][22])
{
	int i, k;
	int wd = dayofweek(y, m, 1);		/* y��m��1�ն�Ӧ������ */
	int mdays = monthdays(y, m);		/* y��m�µ����� */
	char tmp[4];

	sprintf(s[0], "%10d / %02d      ", y, m);	/* ���⣨��/�£� */

	for (k = 1; k < 7; k++)				/* �������������Ļ����� */
		s[k][0] = '\0';

	k = 1;
	sprintf(s[k], "%*s", 3 * wd, "");	/* ��1�յ�������Ͽհ��ַ� */

	for (i = 1; i <= mdays; i++) {
		sprintf(tmp, "%3d", i);
		strcat(s[k], tmp);				/* ׷�ӵ�i�յ����� */
		if (++wd % 7 == 0)				/* ������������ */
			k++;						/* �Ƶ���һ�� */
	}

	if (wd % 7 == 0)
		k--;
	else {
		for (wd %= 7; wd < 7; wd++)		/* �����һ�յ��Ҳ�׷�ӿհ��ַ� */
			strcat(s[k], "   ");
	}
	while (++k < 7)						/* �ÿհ��ַ�����δʹ�õ��� */
		sprintf(s[k], "%21s", "");
}

/*--- �Ѵ�����ά����sbuf�е�������������n������ʾ ---*/
void print(char sbuf[3][7][22], int n)
{
	int i, j;

	for (i = 0; i < n; i++)					/* ��ʾ���⣨��/�£� */
		printf("%s   ", sbuf[i][0]);
	putchar('\n');

	for (i = 0; i < n; i++)
		printf(" �� һ �� �� �� �� ��   ");
	putchar('\n');

	for (i = 0; i < n; i++)
		printf("----------------------  ");
	putchar('\n');

	for (i = 1; i < 7; i++) {				/* �����������岿�� */
		for (j = 0; j < n; j++)				/* ��������n�� */
			printf("%s   ", sbuf[j][i]);	/* ����ʾ */
		putchar('\n');
	}
	putchar('\n');
}

/*--- ��ʾ��y1��m1������y2��m2�µ����� ---*/
void put_calendar(int y1, int m1, int y2, int m2)
{
	int y = y1;
	int m = m1;
	int n = 0;						/* ���ڻ����������� */
	char sbuf[3][7][22];			/* �����ַ����Ļ����� */

	while (y <= y2) {
		if (y == y2 && m > m2) break;
		make_calendar(y, m, sbuf[n++]);
		if (n == 3) {				/* �ۻ���3���¼���ʾ */
			print(sbuf, n);
			n = 0;
		}
		m++;						/* ����һ���� */
		if (m == 13 && y < y2) {	/* ת����һ�� */
			y++;
			m = 1;
		}
	}
	if (n)							/* �����δ��ʾ���·� */
		print(sbuf, n);				/* ����ʾ���·� */
}

int main(void)
{
	int y1, m1, y2, m2;

	printf("��ʾ������\n");

	printf("���뿪ʼ���¡�\n");
	printf("�꣺");	  scanf("%d", &y1);
	printf("�£�");	  scanf("%d", &m1);

	printf("����������¡�\n");
	printf("�꣺");	  scanf("%d", &y2);
	printf("�£�");	  scanf("%d", &m2);

	putchar('\n');

	put_calendar(y1, m1, y2, m2);

	return 0;
}
