/*
�汾�ģ������ʾ���Ƶ��ַ��� 
*/

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i;
	int human;
	int comp;
	int judge;
	int retry;
	char *hd[] = {"ʯͷ","����","��"};
	
	srand(time(NULL));
	
	printf("��ȭ��Ϸ��ʼ��\n");
	
	do{
		comp = rand() % 3;
		
		do{
			printf("\nʯͷ������---");
			for(i = 0;i < 3;i++)
				printf("(%d)%s",i,hd[i]);
			printf(":");
			scanf("%d",&human);
		}while(human < 0 || human > 2);
		
		printf("�ҳ�%s,���%s��\n",hd[comp],hd[human]);
		
		judge = (human - comp + 3) % 3;
		switch(judge){
			case 0:printf("ƽ��"); break;
			case 1:printf("������"); break;
			case 2:printf("��Ӯ��"); break;
		}
		
		printf("����һ����---(0)��(1)��: ");
		scanf("%d",&retry);
	}while(retry == 1);
	
	return 0;
}
