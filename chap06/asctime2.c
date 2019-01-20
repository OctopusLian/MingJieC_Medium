/* ��ʾ��ǰ���ں�ʱ�䣨���[�޸�]������asctime2������*/

#include <time.h>
#include <stdio.h>

/*--- ����asctime�����ѷֽ�ʱ��ת�����ַ���������ӻ��з���---*/
char *asctime2(const struct tm *timeptr)
{
	const char wday_name[7][3] = {					/* ���� */
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
	};
	const char mon_name[12][3] = {					/* �·����� */
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	};
	static char result[25];				/* ���ڴ洢�ַ����Ŀռ��Ǿ�̬�ռ� */

	sprintf(result, "%.3s %.3s %02d %02d:%02d:%02d %4d",
					wday_name[timeptr->tm_wday], mon_name[timeptr->tm_mon],
					timeptr->tm_mday, timeptr->tm_hour, timeptr->tm_min,
					timeptr->tm_sec,  timeptr->tm_year + 1900);
	return result;
}

int main(void)
{
	time_t current = time(NULL);	/* ��ȡ��ǰʱ�� */

	printf("��ǰ���ں�ʱ����%s��\n", asctime2(localtime(&current)));

	return 0;
}
