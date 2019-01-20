/* ��һѵ�������ģ�
     �� ��ʾ����MAX_RECORD�ؿ��Ĵ������ ��				*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define LEVEL_MIN	 2				/* ��͵ȼ�����ֵ�ĸ�����*/
#define LEVEL_MAX	 5				/* ��ߵȼ�����ֵ�ĸ�����*/
#define	MAX_RECORD	10				/* ��¼�÷ֵĹؿ��� */

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
	int i, j, stage, stage2;
	int level;						/* �ȼ� */
	int success;					/* ������� */
	int point[MAX_RECORD];			/* �÷� */
	int retry;						/* ����һ�Σ�*/
	clock_t	start, end;				/* ��ʼʱ��/����ʱ�� */

	srand(time(NULL));				/* �趨����������� */

	printf("������ֵ��������Щ��ֵ��1���ֵ��\n");

	do {
		printf("Ҫ��ս�ĵȼ�(%d��%d)��", LEVEL_MIN, LEVEL_MAX);
		scanf("%d", &level);
	} while (level < LEVEL_MIN || level > LEVEL_MAX);

	success = stage = 0;
	start = clock();
	do {
		int no[LEVEL_MAX];		/* Ҫ�������ֵ */
		int x[LEVEL_MAX];		/* �Ѷ�ȡ��ֵ */
		int seikai = 0;			/* ���ؿ��Ĵ������ */

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

		point[stage++ % MAX_RECORD] = seikai;	/* ��¼�ؿ��Ĵ������ */
		success += seikai;						/* ��������Ĵ������ */

		printf("�Ƿ��������Yes������1��No������0����");
		scanf("%d", &retry);
	} while (retry == 1);
	end = clock();

	printf("\n���� �ɼ� ����\n");

	stage2 = stage - MAX_RECORD;
	if (stage2 < 0) stage2 = 0;

	for (i = level; i >= 1; i--) {
		for (j = stage2; j < stage; j++)
			if (point[j % MAX_RECORD] >= i)
				printf(" �� ");
			else
				printf("    ");
		putchar('\n');
	}
	printf("-----------------------------------------\n");

	for (j = stage2; j < stage; j++)
		printf(" %02d ", j + 1);
	putchar('\n');

	printf("%d���д����%d����\n", level * stage, success);
	printf("��ʱ%.1f�롣\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
