/*
��ȭ��Ϸ�汾������ʾ˫�������� 
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
		
		do{
			printf("\n����ʯͷ��---(0)ʯͷ(1)����(2)���� ");
			scanf("%d",&human);
		}while(human < 0 || human > 2);
		
		printf("�ҳ�");
		switch(comp){
			case 0:printf("ʯͷ"); break;
			case 1:printf("����"); break;
			case 2:printf("��"); break;
		}
		
		printf("�����");
		switch(human){
			case 0:printf("ʯͷ"); break;
			case 1:printf("����"); break;
			case 2:printf("��"); break;
		}
		
		printf("��\n");
		
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
