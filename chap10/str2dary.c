/* Ϊ�ַ������飨��ά���飩��̬����ռ� */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int	num;			/* �ַ����ĸ��� */
	char (*p)[15];		/* �ַ������ǳ���15 */

	printf("�м����ַ�����");
	scanf("%d", &num);

	p = (char (*)[15])malloc(num * 15);

	if (p == NULL) 
		puts("�洢�ռ����ʧ�ܡ�");
	else {
		int i;

		for (i = 0; i < num; i++) {			/* ��ȡ�ַ��� */
			printf("p[%d] : ", i);
			scanf("%s", p[i]);
		}

		for (i = 0; i < num; i++)			/* ��ʾ�ַ��� */
			printf("p[%d] = %s\n", i, p[i]);

		free(p);							/* �ͷŴ洢�ռ� */
	}

	return 0;
}
