/* Ӣ�ﵥ��ѧϰ��������԰棺�����ʾ���ĵ���/Ӣ�ﵥ�ʣ�*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define	QNO	   12		/* ���ʵ����� */

/*--- ���� ---*/
char *cptr[] = {
	"����", "����",	"��",	"��",	"����",	"��",
	"����", "�ְ�",	"����",	"��",	"��ƽ",	"��־",
};

/*--- Ӣ�� ---*/
char *eptr[] = {
	"animal", "car",	"flower", "house", "desk",	"book",
	"chair",  "father",	"mother", "love",  "peace",	"magazine",
};

int main(void)
{
	int nq, pq;			/* ��Ŀ��ź���һ�ε���Ŀ��� */
	int sw;				/* 0������/1��Ӣ�� */
	int retry;			/* ������ս��*/

	srand(time(NULL));	/* �趨����������� */

	pq = QNO;			/* ��һ�ε���Ŀ��ţ������ڵı�ţ� */

	do {
		do {					/* ��������ͬһ������ */
			nq = rand() % QNO;
		} while (nq == pq);

		sw = rand() % 2;		/* ���Ļ���Ӣ�� */

		printf("%s\n", sw ? eptr[nq] : cptr[nq]);

		pq = nq;

		printf("����һ�Σ�0-��/1-�ǣ�");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
