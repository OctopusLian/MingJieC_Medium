/*
do-while ѭ�� ,���ݵ�ǰʱ���趨����������� 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int retry;	
	srand(time(NULL));
	printf("\n�����������%d��\n",rand());
	do{
		printf("%d",rand());
		
		printf("������һ�Σ�...��0����1���ǣ� ");
		scanf("%d",&retry);
	}while(retry == 1);
	
	return 0;
 } 
