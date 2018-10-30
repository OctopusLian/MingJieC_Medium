/*
版本四：限制输入次数 
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
	
	printf("请输入一个数：");
	
	do{
		printf("还剩%d次机会。",remain);
		scanf("%d",&no);
		
		if(no > ans)
			printf("再小一点。\n");
		else if(no < ans)
			printf("再大一点。\n");
	}while(no != ans && remain > 0);
	
	if(no != ans)
		printf("很遗憾，正确答案是%d。\n",ans);
	else{
		printf("回答正确。\n");
		printf("您用了%d次猜中了！\n",max_stage - remain);
	}
	
	return 0;
}
