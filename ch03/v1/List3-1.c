/*
��ȭ��Ϸ�汾һ 
*/ 

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int human;
	int comp;
	int judge;
	int retry;
	
	srand(time(NULL));
	
	printf("��ȭ��Ϸ��ʼ��\n");
	
	do{
		comp = rand() % 3;
		
		printf("\n����ʯͷ��---(0)ʯͷ(1)����(2)���� ");
		scanf("%d",&human);
		
		printf("�ҳ�");
		switch(comp){
			case 0:printf("ʯͷ"); break;
			case 1:printf("����"); break;
			case 2:printf("��"); break;
		}
		printf("��\n");
		
		judge = (human - comp + 3) % 3;
		
		switch(judge){
			case 0:puts("ƽ�֡�"); break;
			case 1:puts("�����ˡ�"); break;
			case 2:puts("��Ӯ�ˡ�"); break;
		}
		
		printf("����һ����---(0)��(1)��: ");
		scanf("%d",&retry);
	}while(retry == 1);
	
	return 0;
}
