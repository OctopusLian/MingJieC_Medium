/*
�汾����������ֵ���趨�ɡ��ȼ� = λ���� 
*/

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STAGE 10
#define LEVEL_MIN  3
#define LEVEL_MAX 20

int sleep(unsigned long x)
{
	clock_t c1 = clock(),c2;
	do{
		if(c2 = clock() == (clock_t) - 1)
			return 0;
	}while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int i,stage;
	int level;
	int success = 0;
	clock_t start,end;
	
	srand(time(NULL));
	
	printf("��ֵ����ѵ��\n");
	
	do{
		printf("Ҫ��ս�ĵȼ���%d ~ %d����",LEVEL_MIN,LEVEL_MAX);
		scanf("%d",&level);
	}while(level < LEVEL_MIN || level > LEVEL_MAX);
	
	printf("������һ��%dλ����ֵ�ɡ�\n",level);
	
	start = clock();
	for(stage = 0;stage < MAX_STAGE;stage++){
		char no[LEVEL_MAX + 1];
		char x[LEVEL_MAX + 2];
		
		no[0] = '1' + rand() % 9;
		for(i = 1;i < level;i++)
			no[i] = '0' + rand() % 10;
		no[level] = '\0';
		
		printf("%s",no);
		fflush(stdout);
		sleep(125 * level);
		
		printf("\r%*s\r�����룺",level,"");
		scanf("%s",x);
		
		if(strcmp(no,x) != 0)
			printf("�ش����\n");
		else{
			printf("�ش���ȷ��\n");
			success++;
		}
	}
	end = clock();
	
	printf("%d���д����%d�Ρ�\n",MAX_STAGE,success);
	printf("��ʱ%.1f�롣\n",(double)(end - start) / CLOCKS_PER_SEC);
	
	return 0;
}
