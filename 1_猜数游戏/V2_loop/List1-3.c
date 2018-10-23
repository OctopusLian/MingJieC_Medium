#include<stdio.h>
int main(void)
{
	int no;
	int ans = 7;
	printf("请猜一个0~9的整数。\n");
	
	while(1){
		printf("是多少呢: ");
		scanf("%d",&no);
		
		if(no > ans)
			printf("再小一点。\n");
		else if
			printf("再大一点。\n");
		else
			break;
	}
	printf("回答正确。\n");
	
	return 0;
}
