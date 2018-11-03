/*
�汾�壺��Ӯ��3����ʤ 
*/

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int human;
int comp;
int win_no;
int lose_no;
int draw_no;

char *hd[] = {"ʯͷ","����","��"};

void initialize(void)
{
	win_no = 0;
	lose_no = 0;
	draw_no = 0;
	
	srand(time(NULL));
	
	printf("��ȭ��Ϸ��ʼ��\n");
}

void jyanken(void)
{
	int i;
	
	comp = rand() % 3;
	
	do{
		printf("\nʯͷ������---");
		for(i = 0;i < 3;i++)
			printf("(%d)%s",i,hd[i]);
		printf(":");
		scanf("%d",&human);
	}while(human < 0 || human > 2);
}

void count_no(int result)
{
	switch(result){
		case 0:draw_no++;break;
		case 1:lose_no++;break;
		case 2:win_no++;break;
	}
}

void disp_result(int result)
{
	switch(result){
		case 0:puts("ƽ�֡�");
		case 1:puts("��Ӯ�ˡ�");
		case 2:puts("�����ˡ�");
	}
}

int main(void)
{
	int judge;
	int retry;
	
	initialize();
	
	do{
		jyanken();
		
		printf("�ҳ�%s,���%s��\n",hd[comp],hd[human]);
		
		judge = (human - comp + 3) % 3;
		count_no(judge);
		disp_result(judge);
	}while(win_no < 3 && lose_no < 3);
	
	printf(win_no == 3 ? "\n��Ӯ�ˡ�\n" : "\n��Ӯ�ˡ�\n");
	
	printf("%dʤ%d��%dƽ��\n",win_no,lose_no,draw_no);
	
	return 0;
}
