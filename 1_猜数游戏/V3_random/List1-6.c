/*
Ŀ��������0-999������� 
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int no;
	int ans;
	
	srand(time(NULL));
	ans = rand() % 1000;
	printf("���һ��0-999��������\n");
	
	do{
		printf("�Ƕ��٣�");
		scanf("%d",&no);
		
		if(no > ans)
			printf("��Сһ�㡣\n");
		else if(no < ans)
			printf("�ٴ�һ�㡣\n");
	}while(no != ans);
	printf("�ش���ȷ��");
	
	return 0;
}
