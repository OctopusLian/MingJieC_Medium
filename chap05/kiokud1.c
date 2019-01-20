/* ��������ѵ��������4λ����*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE	10							/* �ؿ��� */

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
	int stage;
	int success = 0;						/* ������� */
	clock_t start, end;						/* ��ʼʱ��/����ʱ�� */

	srand(time(NULL));						/* �趨����������� */

	printf("������һ��4λ����ֵ�ɡ�\n");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x;								/* �Ѷ�ȡ��ֵ */
		int no = rand() % 9000 + 1000;		/* ��Ҫ�������ֵ */

		printf("%d", no);
		fflush(stdout);
		sleep(500);	/* ����ֻ��ʾ0.5�� */

		printf("\r�����룺");
		fflush(stdout);
		scanf("%d", &x);

		if (x != no)
			printf("\a�ش����\n");
		else {
			printf("�ش���ȷ��\n");
			success++;
		}
	}
	end = clock();

	printf("%d���д����%d�Ρ�\n", MAX_STAGE, success);
	printf("��ʱ%.1f�롣\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
