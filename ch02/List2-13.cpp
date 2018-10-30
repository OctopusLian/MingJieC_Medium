#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int stage;
	int a,b,c;
	int x;
	int n;
	clock_t start,end;
	
	srand(time(NULL));
	
	printf("扩大视野心算训练开始！！\n");
	start = clock();
	
	for(stage = 0;stage < 10;stage++){
		a = 10 + rand() % 90;
		b = 10 + rand() % 90;
		c = 10 + rand() % 90;
		n = rand() % 17;
		
		printf("%d%*s+%*s%d%*s+%*s%d: ",a,n,"",n,"",b,n,"",n,"",c);
		
		do{
			scanf("%d",&x);
			if(x == a + b + c)
				break;
			printf("回答错误，重新输入: ");
		}while(1);
	}
	
	end = clock();
	
	printf("用时%.1f秒。\n",(double)(end - start) / CLOCKS_PER_SEC);
	
	return 0;
}
