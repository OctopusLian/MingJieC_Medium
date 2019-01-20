/* �ۺϴ�����ϰ */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define	NO			15			/* ѵ������ */
#define	KTYPE		16			/* ���� */
#define	POS_LEN		10			/* ����λ��ѵ�����ַ����� */

/*--- ��ϰ�˵� ---*/
typedef enum { Term, KeyPos, KeyPosComp, Clang, Conversation, InValid } Menu;

/*--- ������ļ� ---*/
char *kstr[] = {
	"12345",  "67890-^\\",		/* �ڣ���        */
	"!\"#$%", "&'()=~|",		/* �ڣ���[Shift] */
	"qwert",  "yuiop@[",		/* ��2��         */
	"QWERT",  "YUIOP`{",		/* ��2��[Shift]  */
	"asdfg",  "hjkl;:]",		/* ��3��         */
	"ASDFG",  "HJKL+*}",		/* ��3��[Shift]  */
	"zxcvb",  "nm,./\\",		/* ��4��         */
	"ZXCVB",  "NM<>?_",			/* ��4��[Shift]  */
};

/*--- C���ԵĹؼ��ֺͿ⺯�� ---*/
char *cstr[] = {
	"auto",		"break",	"case",		"char",		"const",	"continue",
	"default",	"do",		"double",	"else",		"enum",		"extern",
	"float",	"for",		"goto",		"if",		"int",		"long",
	"register",	"return",	"short",	"signed",	"sizeof",	"static",
	"struct",	"switch",	"typedef",	"union",	"unsigned",	"void",
	"volatile",	"while",
	"abort",	"abs",		"acos",		"asctime",	"asin",		"assert",
	"atan",		"atan2",	"atexit",	"atof",		"atoi",		"atol",
	"bsearch",	"calloc",	"ceil",		"clearerr",	"clock",	"cos",
	"cosh",		"ctime",	"difftime",	"div",		"exit",		"exp",
	"fabs",		"fclose",	"feof",		"ferror",	"fflush",	"fgetc",
	"fgetpos",	"fgets",	"floor",	"fmod",		"fopen",	"fprintf",
	"fputc",	"fputs",	"fread",	"free",		"freopen",	"frexp",
	"fscanf",	"fseek",	"fsetpos",	"ftell",	"fwrite",	"getc",
	"getchar",	"getenv",	"gets",		"gmtime",	"isalnum",	"isalpha",
	"iscntrl",	"isdigit",	"isgraph",	"islower",	"isprint",	"ispunct",
	"isspace",	"isupper",	"isxdigit",	"labs",		"ldexp",	"ldiv",
	"localeconv",			"localtime","log",		"log10",	"longjmp",
	"malloc",	"memchr",	"memcmp",	"memcpy",	"memmove",	"memset",
	"mktime",	"modf",		"perror",	"pow",		"printf",	"putc",
	"putchar",	"puts",		"qsort",	"raise",	"rand",		"realloc",
	"remove",	"rename",	"rewind",	"scanf",	"setbuf",	"setjmp",
	"setlocale","setvbuf",	"signal",	"sin",		"sinh",		"sprintf",
	"sqrt",		"srand",	"sscanf",	"strcat",	"strchr",	"strcmp",
	"strcoll",	"strcpy",	"strcspn",	"strerror",	"strftime",	"strlen",
	"strncat",	"strncmp",	"strncpy",	"strpbrk",	"strrchr",	"strspn",
	"strstr",	"strtod",	"strtok",	"strtol",	"strtoul",	"strxfrm",
	"system",	"tan",		"tanh",		"time",		"tmpfile",	"tmpnam",
	"tolower",	"toupper",	"ungetc",	"va_arg",	"va_end",	"va_start",
	"vfprintf", "vprintf",	"vsprintf"
};

/*--- Ӣ��Ự ---*/
char *vstr[] = {
	"Hello!",							/* ��á�*/
	"How are you?",						/* �����*/
	"Fine thanks.",						/* �ţ��Һܺá�*/
	"I can't complain, thanks.",		/* �ţ����аɡ�*/
	"How do you do?",					/* ���μ��档*/
	"Good bye!",						/* �ټ���*/
	"Good morning!",					/* ���Ϻá�*/
	"Good afternoon!",					/* ����á�*/
	"Good evening!",					/* ���Ϻá�*/
	"See you later!",					/* �ټ������������*/
	"Go ahead, please.",				/* �����롣*/
	"Thank you.",						/* лл��*/
	"No, thank you.",					/* ����лл��*/
	"May I have your name?",			/* �������ʲô���֣�*/
	"I'm glad to meet you.",			/* �ܸ����ܼ����㡣*/
	"What time is it now?",				/* ���������Ǽ��㣿*/
	"It's about seven.",				/* ���7�㡣*/
	"I must go now.",					/* �Ҳ��ò����ˡ�*/
	"How much?",						/* ����Ǯ��*/
	"Where is the restroom?",			/* ����ϴ�ּ������*/
	"Excuse me.",						/* ��Ǹ��һ�ˣ���*/
	"Excuse us.",						/* ��Ǹ���������ϣ���*/
	"I'm sorry.",						/* �Բ���*/
	"I don't know.",					/* �Ҳ�֪����*/
	"I have no change with me.",		/* ��û����Ǯ��*/
	"I will be back.",					/* �һ�������ġ�*/
	"Are you going out?",				/* ��Ҫ������*/
	"I hope I'm not disturbing you.",	/* ϣ�����������㡣*/
	"I'll offer no excuse.",			/* ��û����Ϊ�Լ���⡣*/
	"Shall we dance?",					/* ������ɡ�*/
	"Will you do me a favor?",			/* ���ܰ��Ҹ�æ��*/
	"It's very unseasonable.",			/* ��ǳ�����ʱ�ڰ���*/
	"You are always welcome.",			/* ��ʱ��ӭ��*/
	"Hold still!",						/* �𶯣�*/
	"Follow me.",						/* ��������*/
	"Just follow my lead.",				/* ���������ͺá�*/
	"To be honest with you,",			/* ˵��ġ���*/
};

/*--- �ַ���str�Ĵ�����ϰ�����ش�������� ---*/
int go(const char *str)
{
	int i;
	int len = strlen(str);			/* �ַ����� */
	int mistake = 0;				/* ������� */

	for (i = 0; i < len; i++) {
		/* ��ʾstr[i]֮����ַ����ѹ�귵�ص���ͷ */
		printf("%s \r", &str[i]);
		fflush(stdout);
		while (getch() != str[i]) {
			mistake++;
		}
	}
	return mistake;
}

/*--- ��һλ��ѵ�� ---*/
void pos_training(void)
{
	int i;
	int stage;
	int temp, line;
	int len;						/* ���ڳ���Ŀ�ļ��� */
	int qno, pno;					/* ��Ŀ��ź���һ�ε���Ŀ��� */
	int tno, mno;					/* �ַ������ʹ������ */
	clock_t	start, end;				/* ��ʼʱ��ͽ���ʱ�� */

	printf("\n���е�һλ��ѵ����\n");
	printf("��ѡ��Ҫ��ϰ�Ŀ顣\n");
	printf("��1�� (1) �� %-8s    (2) �� %-8s\n", kstr[ 0], kstr[ 1]);
	printf("��2�� (3) �� %-8s    (4) �� %-8s\n", kstr[ 4], kstr[ 5]);
	printf("��3�� (5) �� %-8s    (6) �� %-8s\n", kstr[ 8], kstr[ 9]);
	printf("��4�� (7) �� %-8s    (8) �� %-8s\n", kstr[12], kstr[13]);

	/* �����ѡ��� */
	do {
		printf("��ţ�ֹͣ��ϰΪ99����");
		scanf("%d", &temp);
		if (temp == 99) return;				/* ֹͣ��ϰ */
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;

	printf("��ϰ%s��%d��Ŀ��\n", kstr[line], NO);

	printf("���¿ո����ʼ��\n");
	while (getch() != ' ')
		;

	tno = mno = 0;						/* ����ַ������ʹ������ */
	len = strlen(kstr[line]);			/* Ҫ��ϰ�Ŀ�ļ��� */

	start = clock();						/* ��ʼʱ�� */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++)	/* �������ڳ�����ַ��� */
			str[i] = kstr[line][rand() % len];
		str[i] = '\0';

		mno += go(str);						/* ������ϰ */
		tno += strlen(str);
	}

	end = clock();							/* ����ʱ�� */

	printf("��Ŀ��%d�ַ�/����%d��\n", tno, mno);
	printf("��ʱ%.1f�롣\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- ���λ��ѵ�� ---*/
void pos_training2(void)
{
	int i;
	int stage;
	int temp, line;
	int sno;						/* ��ѡ�еĿ��� */
	int select[KTYPE];				/* ��ѡ�еĿ� */
	int len[KTYPE];					/* ���ڳ���Ŀ�ļ��� */
	int tno, mno;					/* �ַ������ʹ������ */
	clock_t	start, end;				/* ��ʼʱ��ͽ���ʱ�� */
	char *format = "��%d�� (%2d) �� %-8s (%2d) �� %-8s "
					      "(%2d)[��] %-8s (%2d)[��] %-8s\n";

	printf("\n���л��λ��ѵ����\n");
	printf("��ѡ��Ҫ��ϰ�Ŀ飨���Զ�ѡ����\n");

	for (i = 0; i < 4; i++) {
		int k = i * 4;
		printf(format, i+1, k + 1, kstr[k],		k + 2, kstr[k + 1],
							k + 3, kstr[k + 2], k + 4, kstr[k + 3]);
	}

	/* ���ظ�ѡ��飨���16���� */
	sno = 0;
	while (1) {
		printf("��ţ�����ѡ��Ϊ50/ֹͣ��ϰΪ99����");

		do {
			scanf("%d", &temp);
			if (temp == 99) return;			/* ֹͣ��ϰ */
		} while ((temp < 1 || temp > KTYPE) && temp != 50);

		if (temp == 50)
			break;
		for (i = 0; i < sno; i++)
			if (temp == select[i]) {
				printf("\a��һ���Ѿ���ѡ���ˡ�\n");
				break;
			}
		if (i == sno)
			select[sno++] = temp;			/* ע�ᱻѡ�еĿ� */
	}

	if (sno == 0)							/* һ����û��ѡ */
		return;

	printf("�����п����Ŀ��ϰ%d�Ρ�\n", NO);

	for (i = 0; i < sno; i++)
		printf("%s ", kstr[select[i] - 1]);

	printf("\n���¿ո����ʼ��\n");
	while (getch() != ' ')
		;

	tno = mno = 0;							/* ����ַ������ʹ������ */
	for (i = 0; i < sno; i++)
		len[i] = strlen(kstr[select[i] - 1]);	/* ��ļ��� */

	start = clock();						/* ��ʼʱ�� */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++) {		/* �������ڳ�����ַ��� */
			int q = rand() % sno;
			str[i] = kstr[select[q] - 1][rand() % len[q]];
		}
		str[i] = '\0';

		mno += go(str);						/* ������ϰ */
		tno += strlen(str);
	}

	end = clock();							/* ����ʱ�� */

	printf("��Ŀ��%d�ַ�/����%d��\n", tno, mno);
	printf("��ʱ%.1f�롣\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- C����/Ӣ��Ựѵ�� ---*/
void word_training(const char *mes, const char *str[], int n)
{
	int stage;
	int qno, pno;					/* ��Ŀ��ź���һ�ε���Ŀ��� */
	int tno, mno;					/* �ַ������ʹ������ */
	clock_t	start, end;				/* ��ʼʱ��ͽ���ʱ�� */

	printf("\n��ϰ%d��%s��\n", mes, NO);

	printf("���¿ո����ʼ��\n");
	while (getch() != ' ')
		;

	tno = mno = 0;					/* ����ַ������ʹ������ */
	pno = n;						/* ��һ�ε���Ŀ��ţ������ڵı�ţ� */

	start = clock();				/* ��ʼʱ�� */

	for (stage = 0; stage < NO; stage++) {
		do {						/* ��������ͬһ����Ŀ */
			qno = rand() % n;
		} while (qno == pno);

		mno += go(str[qno]);		/* ��Ŀ��str[qno] */
		tno += strlen(str[qno]);
		pno = qno;
	}

	end = clock();					/* ����ʱ�� */

	printf("��Ŀ��%d�ַ�/����%d��\n", tno, mno);
	printf("��ʱ%.1f�롣\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- ѡ��˵� ---*/
Menu SelectMenu(void)
{
	int ch;

	do {
		printf("\n��ѡ����ϰ��\n");
		printf("(1) ��һλ��       (2) ���λ��\n");
		printf("(3) C���Եĵ���    (4) Ӣ��Ự      (0) ���� ��");
		scanf("%d", &ch);
	} while (ch < Term || ch >= InValid);

	return (Menu)ch;
}

int main(void)
{
	Menu menu;										/* �˵� */
	int cn = sizeof(cstr) / sizeof(cstr[0]);		/* C���Եĵ������� */
	int vn = sizeof(vstr) / sizeof(vstr[0]);		/* Ӣ��Ự���ĵ����� */

	init_getputch();

	srand(time(NULL));								/* �趨��������� */

	do {
		switch (menu = SelectMenu()) {

		 case KeyPos :						/* ��һλ��ѵ�� */
		 			pos_training();
		 			break;

		 case KeyPosComp :					/* ���λ��ѵ�� */
		 			pos_training2();
		 			break;

		 case Clang :						/* C���Եĵ��� */
		 			word_training("C���Եĵ���", cstr, cn);
		 			break;

		 case Conversation :				/* Ӣ��Ự */
		 			word_training("Ӣ��Ự���ĵ�", vstr, vn);
		 			break;
		}
	} while (menu != Term);

	term_getputch();

	return 0;
}
