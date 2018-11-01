/*
版本四：导入表示手势的字符串 
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
	char *hd[] = {"石头","剪刀","布"};
	
	srand(time(NULL));
	
	printf("猜拳游戏开始！\n");
	
	do{
		comp = rand() % 3;
		
		do{
			printf("\n石头剪刀布---");
			for(i = 0;i < 3;i++)
				printf("(%d)%s",i,hd[i]);
			printf(":");
			scanf("%d",&human);
		}while(human < 0 || human > 2);
		
		printf("我出%s,你出%s。\n",hd[comp],hd[human]);
		
		judge = (human - comp + 3) % 3;
		switch(judge){
			case 0:printf("平局"); break;
			case 1:printf("你输了"); break;
			case 2:printf("你赢了"); break;
		}
		
		printf("再来一次吗？---(0)否(1)是: ");
		scanf("%d",&retry);
	}while(retry == 1);
	
	return 0;
}
