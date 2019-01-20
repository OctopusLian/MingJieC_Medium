/* ��Э������ʱ��ʾ��ǰ���ں�ʱ�� */

#include <time.h>
#include <stdio.h>

/*--- ��ʾ���ں�ʱ�� ---*/
void put_date(const struct tm *timer)
{
	char *wday_name[] = {"��", "һ", "��", "��", "��", "��", "��"};

	printf("%4d��%02d��%02d��(%s)%02dʱ%02d��%02d��",
			timer->tm_year + 1900,		/* �� */
			timer->tm_mon + 1,			/* �� */
			timer->tm_mday, 			/* �� */
			wday_name[timer->tm_wday],	/* ���� */
			timer->tm_hour,				/* ʱ*/
			timer->tm_min,				/* ��*/
			timer->tm_sec				/* ��*/
		  );
}

int main(void)
{
	time_t current;					/* ����ʱ�䣨�����������ͣ� */
	struct tm *timer;				/* �ֽ�ʱ�䣨�ṹ�壩 */

	time(&current);					/* ��ȡ��ǰʱ�� */
	timer = gmtime(&current);		/* ת���ɷֽ�ʱ�䣨Э������ʱ�� */

	printf("��ǰ���ں�ʱ����UTC��ʾ��");
	put_date(timer);
	printf("��\n");

	return 0;
}
