/*
�������� 
*/

#include<time.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void make4digits(int x[])
{
	int i,j,val;
	
	for(i = 0;i < 4;i++){
		do{
			val = rand() % 10;
			for(j = 0;j < i;j++)
				if(val == x[j])
					break;
		}while(j < i);
		x[i] = val;
	}
}

int check(const char s[])
{
	int i,j;
	if(strlen(s) != 4)
		return 1;
	
	for(i = 0;i < 4;i++){
		if(!isdigit(s[i]))
			return 2;
		for(j = 0;j < i;j++)
			if(s[i] == s[j])
				return 3;
	}
	return 0;
}

void judge(const char s[],const int no[],int *hit,int *blow)
{
	int i,j;
	
	*hit = *blow = 0;
	for(i = 0;i < 4;i++){
		for(j = 0;j < 4;j++){
			if(s[i] == '0' + no[j])
				if(i == j)
					(*hit)++;
				else
					(*blow)++;
		}
	}
 } 
 
 void print_result(int snum,int spos)
 {
 	if(spos == 4)
 		printf("�ش���ȷ��");
 	else if(snum == 0)
 		printf("   ��Щ������û�д����֡�\n");
 	else{
 		printf("   ��Щ���������%d�������֡�\n",snum);
 		
 		if(spos == 0)
 			printf("   �������ֵ�λ�ö���һ�¡�\n");
 		else
 			printf("   ������%d�����ֵ�λ��ʱһ�µġ�\n",spos);
	 }
	 putchar('\n');
 }
 
 int main(void)
 {
 	int try_no = 0;
	 int chk;
	 int hit;
	 int blow;
	 int no[4];
	 char buff[10];
	 clock_t start,end;
	 
	 srand(time(NULL));
	 
	 puts("������������ɣ�"); 
	 puts("����ĸ����֡�");
	 puts("���в�������ͬ���֡�");
	 puts("����4307���������������֡�");
	 puts("��������ո��ַ�");
	 
	 make4digits(no);
	 
	 start = clock();
	 
	 do{
	 	do{
	 		printf("�����룺 ");
	 		scanf("%s",buff);
	 		
	 		chk = check(buff);
	 		
	 		switch(chk){
	 			case 1:puts("��ȷ������4���ַ���"); break;
	 			case 2:puts("�벻Ҫ�����������������ַ���"); break;
	 			case 3:puts("�벻Ҫ������ͬ�����֡�"); break;
			 }
		 }while(chk != 0);
		 
		 try_no++;
		 judge(buff,no,&hit,&blow);
		 print_result(hit + blow,hit);
	 }while(hit < 4);
	 
	 end = clock();
	 
	 printf("����%d�Ρ�\n��ʱ%.1f�롣\n",try_no,(double)(end - start) / CLOCKS_PER_SEC);
	 
	 return 0;
 }
 
