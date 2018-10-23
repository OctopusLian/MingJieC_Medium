/*
do-while 循环 
*/

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int retry;  //再运行一次？ 
	do{
		printf("%d",rand());
		
		printf("再运行一次？...（0）否（1）是： ");
		scanf("%d",&retry);
	}while(retry == 1);
	
	return 0;
}
