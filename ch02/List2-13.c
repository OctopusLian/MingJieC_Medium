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
	
	printf("������Ұ����ѵ����ʼ����\n");
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
			printf("�ش������������: ");
		}while(1);
	}
	
	end = clock();
	
	printf("��ʱ%.1f�롣\n",(double)(end - start) / CLOCKS_PER_SEC);
	
	return 0;
}
