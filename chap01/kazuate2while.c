/* ������Ϸ[�������һ�ֽⷨ�����ظ����¶�Ϊֹ��������while���]*/

#include <stdio.h>

int main(void)
{
	int no;			/* ��ȡ��ֵ */
	int ans = 7;	/* Ŀ������ */

	printf("���һ��0~9��������\n\n");

	while (1) {
		printf("�Ƕ����أ�");
		scanf("%d", &no);

		if (no > ans)
			printf("\a��Сһ�㡣\n");
		else if (no < ans)
			printf("\a�ٴ�һ�㡣\n");
		else
			break;
	}

	printf("�ش���ȷ��\n");

	return 0;
}
