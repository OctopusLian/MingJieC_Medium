/*������Ϸ��������ظ����¶�Ϊֹ��������do��䣩*/

#include <stdio.h>

int main(void)
{
	int no;			/* ��ȡ��ֵ */
	int ans = 7;	/* Ŀ������ */

	printf("���һ��0~9��������\n\n");

	do {
		printf("�Ƕ����أ�");
		scanf("%d", &no);

		if (no > ans)
			printf("\a��Сһ�㡣\n");
		else if (no < ans)
			printf("\a�ٴ�һ�㡣\n");
	} while (no != ans);						/* �ظ����¶�Ϊֹ */

	printf("�ش���ȷ��\n");

	return 0;
}
