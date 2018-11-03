/*
猜拳游戏版本一 
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
	
	printf("猜拳游戏开始！\n");
	
	do{
		comp = rand() % 3;
		
		printf("\n剪刀石头布---(0)石头(1)剪刀(2)布： ");
		scanf("%d",&human);
		
		printf("我出");
		switch(comp){
			case 0:printf("石头"); break;
			case 1:printf("剪刀"); break;
			case 2:printf("布"); break;
		}
		printf("。\n");
		
		judge = (human - comp + 3) % 3;
		
		switch(judge){
			case 0:puts("平局。"); break;
			case 1:puts("你输了。"); break;
			case 2:puts("你赢了。"); break;
		}
		
		printf("再来一次吗？---(0)否(1)是: ");
		scanf("%d",&retry);
	}while(retry == 1);
	
	return 0;
}
