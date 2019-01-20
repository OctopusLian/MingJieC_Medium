/* ��һѵ�������壺��������ֵ��������Щ��ֵ��1���ֵ��*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define LEVEL_MIN	2				/* ��͵ȼ�����ֵ�ĸ�����*/
#define LEVEL_MAX	6				/* ��ߵȼ�����ֵ�ĸ�����*/

/*--- �ȴ�x���� ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	/* ���� */
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x); 
	return 1;
}

int main(void)
{
	int i, stage;
	int max_stage;					/* �ؿ��� */
	int level;						/* �ȼ� */
	int success;					/* ������� */
	int *score;						/* ���йؿ��Ĵ������ */
	clock_t	start, end;					/* ��ʼʱ��/����ʱ�� */

	srand(time(NULL));					/* �趨����������� */

	printf("��һѵ����ʼ!!\n");
	printf("����2λ����ֵ��\n");
	printf("������ԭ��ֵ��1���ֵ��\n");

	do {
		printf("Ҫ��ս�ĵȼ�(%d��%d)��", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	do {
		printf("ѵ��������");
		scanf("%d", &max_stage);
	} while (max_stage <= 0);

	score = calloc(max_stage, sizeof(int));

	success = 0;
	start = clock();
	for (stage = 0; stage < max_stage; stage++) {
		int no[LEVEL_MAX];					/* Ҫ�������ֵ */
		int x[LEVEL_MAX];					/* �Ѷ�ȡ��ֵ */
		int seikai = 0;						/* ���ؿ��Ĵ������ */

		printf("\n��%d�ؿ���ʼ!!\n", stage + 1);

		for (i = 0; i < level; i++) {		/* ��level�� */
			no[i] = rand() % 90 + 10;		/* ����10 ~ 99������� */
			printf("%d ", no[i]);			/* ��ʾ */
		}
		fflush(stdout);
		sleep(300 * level);					/* �ȴ�0.30 �� level�� */
		printf("\r%*s\r", 3 * level, "");	/* ������Ŀ */
		fflush(stdout);

		for (i = 0; i < level; i++) {		/* ��ȡ�� */
			printf("��%d������", i + 1);
			scanf("%d", &x[i]);
		}

		for (i = 0; i < level; i++) {		/* �ж϶Դ���ʾ */
			if (x[i] != no[i] + 1)
				printf("�� ");
			else {
				printf("�� ");
				seikai++;
			}
		}
		putchar('\n');

		for (i = 0; i < level; i++)			/* ��ʾ��ȷ�� */
			printf("%2d ", no[i]);

		printf(" ������ �����%d����\n", seikai);
		score[stage] = seikai;				/* ��¼�ؿ��Ĵ������ */
		success += seikai;					/* ��������Ĵ������ */
	}
	end = clock();

	printf("%d���д����%d����\n", level * max_stage, success);

	for (stage = 0; stage < max_stage; stage++)
		printf("��%2d�ؿ���%d\n", stage + 1, score[stage]);

	printf("��ʱ%.1f�롣\n", (double)(end - start) / CLOCKS_PER_SEC);

	free(score);

	return 0;
}
