/* Ѱ����������ѵ������������ʾ��һ�ε����ں���ߵ÷֣�*/

#include <time.h>
#include <float.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "getputch.h"

#define MAX_STAGE	10
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

char dtfile[] = "LACKNUM.DAT";				/* �ļ��� */

/*--- ��ȡ����ʾ��һ�ε�ѵ����Ϣ��������ߵ÷� ---*/
double get_data(void)
{
	FILE *fp;
	double best;		/* ��ߵ÷� */

	if ((fp = fopen(dtfile, "r")) == NULL) {
		printf("���ǵ�һ�����б�����ɡ�\n\n");
		best = DBL_MAX;
	} else {
		int year, month, day, h, m, s;

		fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);
		fscanf(fp, "%lf", &best);
		printf("�ϴν�����������%d��%d��%d��%dʱ%d��%d�롣\n",
											year, month, day, h, m, s);

		printf("��ʷ��ߵ÷֣��������ʱ�䣩Ϊ%.1f�롣\n\n", best);
		fclose(fp);
	}

	return best;
}

/*--- д�뱾��ѵ����Ϣ ---*/
void put_data(double best)
{
	FILE *fp;
	time_t t = time(NULL);
	struct tm *local = localtime(&t);

	if ((fp = fopen(dtfile, "w")) == NULL)
		printf("��������!!");
	else {
		fprintf(fp, "%d %d %d %d %d %d\n",
					local->tm_year + 1900, local->tm_mon + 1, local->tm_mday,
					local->tm_hour,		   local->tm_min,	  local->tm_sec);

		fprintf(fp, "%f\n", best);
		fclose(fp);
	}
}

/*--- ����ѵ�����򲢷��ص÷֣�����ʱ�䣩 ---*/
double go(void)
{
	int i, j, stage;
	int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a[8];
	double jikan;				/* ʱ�� */
	clock_t start, end;			/* ��ʼʱ��ͽ���ʱ�� */

	printf("������ȱ�ٵ����֡�\n");
	printf("���¿ո����ʼ��\n");
	while (getch() != ' ')
		;

	start = clock();

	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;		/* ���������0 ~ 8 */
		int	no;					/* �Ѷ�ȡ��ֵ */

		i = j = 0;
		while (i < 9) {			/* ����ʱ����dgt[x] */
			if (i != x)
				a[j++] = dgt[i];
			i++;
		}

		for (i = 7; i > 0; i--) {		/* ������������a */
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (i = 0; i < 8; i++)		/* ��ʾ����Ԫ�� */
			printf("%d ", a[i]);
		printf("��");
		fflush(stdout);

		do {
			no = getch();
			if (isprint(no)) {				/* �������ʾ�Ļ� */
				putch(no);					/* ��ʾ���µļ� */
				if (no != dgt[x] + '0')		/* ����ش���� */
					putch('\b');			/* �ѹ����ǰ��һ�� */
				else
					printf("\n");			/* ���� */
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC;

	printf("��ʱ%.1f�롣\n", jikan);

	if (jikan > 25.0)
		printf("��Ӧ̫���ˡ�\n");
	else if (jikan > 20.0)
		printf("��Ӧ�е���ѽ��\n");
	else if (jikan > 17.0)
		printf("��Ӧ���аɡ�\n");
	else
		printf("��Ӧ��찡��\n");

	return jikan;
}

int main(void)
{
	int retry;		/* ����һ�Σ�*/
	double score;	/* �÷֣�����ʱ�䣩*/
	double best;	/* ��ߵ÷֣��������ʱ�䣩*/

	best = get_data();			/* ��ȡ��ʷ��ߵ÷� */

	init_getputch();
	srand(time(NULL));			/* �趨����������� */

	do {
		score = go();			/* ����ѵ������ */

		if (score < best) {
			printf("��������ߵ÷֣�����ʱ�䣩!!\n");
			best = score;		/* ������ߵ÷� */
		}

		printf("����һ���𡤡���(0)��(1)�ǣ�");
		scanf("%d", &retry);
	} while (retry == 1);

	put_data(best);				/* д�뱾��ѵ�������ڡ�ʱ���Լ��÷� */

	term_getputch();

	return 0;
}
