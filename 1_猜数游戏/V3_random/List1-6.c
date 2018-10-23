/*
目标数字是0-999的随机数 
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
	printf("请猜一个0-999的整数。\n");
	
	do{
		printf("是多少：");
		scanf("%d",&no);
		
		if(no > ans)
			printf("再小一点。\n");
		else if(no < ans)
			printf("再大一点。\n");
	}while(no != ans);
	printf("回答正确！");
	
	return 0;
}
