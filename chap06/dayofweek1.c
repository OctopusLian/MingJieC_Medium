/* �����ڣ���һ������mktime������*/

#include <time.h>
#include <stdio.h>

/*--- ��year��month��day�������ڼ� ---*/
int dayofweek(int year, int month, int day)
{
	struct tm t;

	t.tm_year  = year - 1900;	/* ������� */
	t.tm_mon   = month - 1;		/* �����·� */
	t.tm_mday  = day;			/* �� */
	t.tm_hour  = 0;				/* ʱ */
	t.tm_min   = 0;				/* �� */
	t.tm_sec   = 0;				/* �� */
	t.tm_isdst = -1;			/* ����ʱ */

	if (mktime(&t) == (time_t)-1)	/* ת��ʧ�ܵĻ� */
		return -1;					/* ����-1 */
	return t.tm_wday;			/* ����mktime�����趨������ */
}

int main(void)
{
	int  y, m, d, w;
	char *ws[] = {"��", "һ", "��", "��", "��", "��", "��"};

	printf("�����ڡ�\n");
	printf("�꣺");   scanf("%d", &y);
	printf("�£�");   scanf("%d", &m);
	printf("�գ�");   scanf("%d", &d);

	w = dayofweek(y, m, d);			/* ������ */

	if (w != -1)
		printf("��һ��������%s��\n", ws[w]);
	else
		printf("�޷�������ڡ�\n");

	return 0;
}
