#include<stdio.h>
int main(void)
{
	int no;
	int ans = 7;
	printf("���һ��0~9��������\n");
	
	printf("�Ƕ�����:");
	scanf("%d",&no);
	
	if(no > ans)
		printf("\a��Сһ�㡣\n");
	else if(no < ans)
		printf("\a�ٴ�һ�㡣\n");
	else
		printf("�ش���ȷ��\n");
	
	return 0;
}
