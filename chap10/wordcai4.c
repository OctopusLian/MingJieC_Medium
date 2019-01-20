/* ����ѧϰ�������ģ����ļ��ж�ȡ���ʣ�*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	CNO		4		/* ѡ������ */

#define swap(type, x, y)   do { type t = x; x = y; y = t; } while (0)

int	QNO;				/* �������� */
char **cptr;			/* ָ�����ĵ��ʵ�ָ������ */
char **eptr;			/* ָ��Ӣ�ﵥ�ʵ�ָ������ */

/*--- ��ʾѡ�� ---*/
void print_cand(const int c[], int sw)
{
	int i;

	for (i = 0; i < CNO; i++)
		printf("(%d) %s  ", i, sw ? cptr[c[i]] : eptr[c[i]]);
	printf("��");
}

/*--- ����ѡ�������ȷ���±� ---*/
int make_cand(int c[], int n)
{
	int i, j, x;

	c[0] = n;						/* �ڿ�ͷԪ���д�����ȷ�� */

	for (i = 1; i < CNO; i++) {
		do {						/* ���ɲ��ظ�������� */
			x = rand() % QNO;
			for (j = 0; j < i; j++)
				if (c[j] == x)		/* �Ѿ���������ͬ������� */
					break;
		} while (i != j);
		c[i] = x;
	}

	j = rand() % CNO;
	if (j != 0)
		swap(int, c[0], c[j]);	/* �ƶ���ȷ�� */

	return j;
}

/*--- ��ȡ���� ---*/
int read_tango(void)
{
	int	i;
	FILE *fp;

	if ((fp = fopen("TANGO", "r")) == NULL) return 1;

	fscanf(fp, "%d", &QNO);			/* ��ȡ�������� */

	if ((cptr = calloc(QNO, sizeof(char *))) == NULL) return 1;
	if ((eptr = calloc(QNO, sizeof(char *))) == NULL) return 1;

	for (i = 0; i < QNO; i++) {
		char etemp[1024];
		char ctemp[1024];

		fscanf(fp, "%s%s", etemp, ctemp);
		if ((eptr[i] = malloc(strlen(etemp) + 1)) == NULL) return 1;
		if ((cptr[i] = malloc(strlen(ctemp) + 1)) == NULL) return 1;
		strcpy(eptr[i], etemp);
		strcpy(cptr[i], ctemp);
	}
	fclose(fp);

	return 0;
}

int main(void)
{
	int i;
	int nq, pq;			/* ��Ŀ��ź���һ�ε���Ŀ��� */
	int na;				/* ��ȷ�𰸵ı�� */
	int sw;				/* ��Ŀ���ԣ�0������/1��Ӣ�*/
	int retry;			/* ������ս��*/
	int cand[CNO];		/* ѡ��ı�� */

	if (read_tango() == 1) {
		printf("\a�����ļ���ȡʧ�ܡ�\n");
		return 1;
	}
	srand(time(NULL));	/* �趨����������� */

	pq = QNO;			/* ��һ�ε���Ŀ��ţ������ڵı�ţ�*/

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
				puts("�ش����");
		} while (no != na);
		puts("�ش���ȷ��");

		pq = nq;

		printf("����һ�Σ�0-��/1-�ǣ�");
		scanf("%d", &retry);
	} while (retry == 1);

	for (i = 0; i < QNO; i++) {
		free(eptr[i]);
		free(cptr[i]);
	}
	free(cptr);
	free(eptr);

	return 0;
}
