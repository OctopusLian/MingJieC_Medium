/*
do-while ѭ�� 
*/

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int retry;  //������һ�Σ� 
	do{
		printf("%d",rand());
		
		printf("������һ�Σ�...��0����1���ǣ� ");
		scanf("%d",&retry);
	}while(retry == 1);
	
	return 0;
}
