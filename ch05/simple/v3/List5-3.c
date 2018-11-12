/*
�汾��������Ӣ����ĸ-��һ��ֻ�����д��ĸ 
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
	const char ltr[] = "ABCDEFGHIGKLMNOPQRSTUVWXYZ";
	
	srand(time(NULL));
	
	printf("Ӣ����ĸ����ѵ��\n");
	
	do{
		printf("Ҫ��ս�ĵȼ���%d ~ %d����",LEVEL_MIN,LEVEL_MAX);
		scanf("%d",&level);
	}while(level < LEVEL_MIN || level > LEVEL_MAX);
	
	printf("������һ��%d��Ӣ����ĸ�ɡ�\n",level);
	
	start = clock();
	for(stage = 0;stage < MAX_STAGE;stage++){
		char mstr[LEVEL_MAX + 1];
		char x[LEVEL_MAX * 2];
		
		for(i = 0;i < level;i++)
			mstr[i] = ltr[rand() % strlen(ltr)];
		mstr[level] = '\0';
		
		printf("%s",mstr);
		fflush(stdout);
		sleep(125 * level);
		
		printf("\r%*s\r�����룺",level,"");
		scanf("%s",x);
		
		if(strcmp(x,mstr) != 0)
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
