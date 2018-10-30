#include<stdio.h>
int main(void)
{
	int no;
	int ans = 7;
	printf("请猜一个0~9的整数。\n");
	
	do{
		printf("是多少呢: ");
		scanf("%d",&no);
		
		if(no > ans)
			printf("再小一点。\n");
		else if(no < ans)
			printf("再大一点。\n");
	}while(no != ans);
	
	return 0;
}
