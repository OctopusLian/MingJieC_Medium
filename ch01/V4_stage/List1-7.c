/*
�汾�ģ������������ 
*/

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int no;
	int ans;
	const int max_stage = 10;
	int remain = max_stage;
	
	srand(time(NULL));
	ans = rand() % 1000;
	
	printf("������һ������");
	
	do{
		printf("��ʣ%d�λ��ᡣ",remain);
		scanf("%d",&no);
		
		if(no > ans)
			printf("��Сһ�㡣\n");
		else if(no < ans)
			printf("�ٴ�һ�㡣\n");
	}while(no != ans && remain > 0);
	
	if(no != ans)
		printf("���ź�����ȷ����%d��\n",ans);
	else{
		printf("�ش���ȷ��\n");
		printf("������%d�β����ˣ�\n",max_stage - remain);
	}
	
	return 0;
}
