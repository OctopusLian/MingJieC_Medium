/*
do-while 循环 ,根据当前时间设定随机数的种子 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int retry;	
	srand(time(NULL));
	printf("\n生成了随机数%d。\n",rand());
	do{
		printf("%d",rand());
		
		printf("再运行一次？...（0）否（1）是： ");
		scanf("%d",&retry);
	}while(retry == 1);
	
	return 0;
 } 
