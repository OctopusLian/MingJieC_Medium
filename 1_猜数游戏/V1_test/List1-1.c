#include<stdio.h>
int main(void)
{
	int no;
	int ans = 7;
	printf("请猜一个0~9的整数。\n");
	
	printf("是多少呢:");
	scanf("%d",&no);
	
	if(no > ans)
		printf("\a再小一点。\n");
	else if(no < ans)
		printf("\a再大一点。\n");
	else
		printf("回答正确。\n");
	
	return 0;
}
