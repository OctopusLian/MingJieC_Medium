#include<stdio.h>
int main(void)
{
	int i;
	int x;
	
	printf("Ҫ��ʾ�����У� ");
	scanf("%d",&x);
	
	for(i = 1;i <= x;i++){
		printf("%*d\n",i,i % 10);
	}
	
	return 0;
}
