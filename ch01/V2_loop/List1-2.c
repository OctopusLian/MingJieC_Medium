#include<stdio.h>
int main(void)
{
	int no;
	int ans = 7;
	printf("���һ��0~9��������\n");
	
	do{
		printf("�Ƕ�����: ");
		scanf("%d",&no);
		
		if(no > ans)
			printf("��Сһ�㡣\n");
		else if(no < ans)
			printf("�ٴ�һ�㡣\n");
	}while(no != ans);
	
	return 0;
}
