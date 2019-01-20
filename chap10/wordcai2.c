/* Ӣ�ﵥ��ѧϰ�������������ص����⣩*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define QNO  12		/* ���ʵ����� */
#define CNO   4		/* ѡ������� */

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

/*--- ��ʾѡ�� ---*/
void print_cand(const int c[], int sw)
{
	int i;

	for (i = 0; i < CNO; i++)
		printf("(%d) %s  ", i, sw ? cptr[c[i]] : eptr[c[i]]);
	printf("��");
}

/*--- ����ѡ�������ȷ�𰸵��±� ---*/
int make_cand(int c[], int n)
{
	int	i;

	c[0] = n;					/* ����ȷ�𰸴��뿪ͷԪ�� */
	for (i = 1; i < CNO; i++)	/* �����Ԫ�� */
		c[i] = rand() % QNO;	/* �Ǵ��ڵ���0С��QNO��ֵ */

	return 0;
}

int main(void)
{
	int nq, pq;			/* ��Ŀ��ź���һ�ε���Ŀ��� */
	int na;				/* ��ȷ�𰸵ı�� */
	int sw;				/* ��Ŀ�����ԣ�0������/1��Ӣ�*/
	int retry;			/* ������ս��*/
	int cand[CNO];		/* ѡ��ı�� */

	srand(time(NULL));	/* �趨����������� */

	pq = QNO;			/* ��һ�ε���Ŀ��ţ������ڵı�ţ� */

	do {
		int no;

		do {						/* �������ڳ���ĵ��ʵı�� */
			nq = rand() % QNO;
		} while (nq == pq);			/* ��������ͬһ������ */

		na = make_cand(cand, nq);	/* ����ѡ�� */
		sw = rand() % 2;

		printf("��һ����%s��\n", sw ? eptr[nq] : cptr[nq]);

		do {
			print_cand(cand, sw);	/* ��ʾѡ�� */
			scanf("%d", &no);
			if (no != na)
				puts("\a�ش����");
		} while (no != na);
		puts("�ش���ȷ��");

		pq = nq;

		printf("����һ�Σ�0-��/1-�ǣ�");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}