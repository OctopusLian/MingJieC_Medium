/* 综合打字练习 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define	NO			15			/* 训练次数 */
#define	KTYPE		16			/* 块数 */
#define	POS_LEN		10			/* 用于位置训练的字符数量 */

/*--- 练习菜单 ---*/
typedef enum { Term, KeyPos, KeyPosComp, Clang, Conversation, InValid } Menu;

/*--- 各个块的键 ---*/
char *kstr[] = {
	"12345",  "67890-^\\",		/* 第１层        */
	"!\"#$%", "&'()=~|",		/* 第１层[Shift] */
	"qwert",  "yuiop@[",		/* 第2层         */
	"QWERT",  "YUIOP`{",		/* 第2层[Shift]  */
	"asdfg",  "hjkl;:]",		/* 第3层         */
	"ASDFG",  "HJKL+*}",		/* 第3层[Shift]  */
	"zxcvb",  "nm,./\\",		/* 第4层         */
	"ZXCVB",  "NM<>?_",			/* 第4层[Shift]  */
};

/*--- C语言的关键字和库函数 ---*/
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

/*--- 英语会话 ---*/
char *vstr[] = {
	"Hello!",							/* 你好。*/
	"How are you?",						/* 你好吗？*/
	"Fine thanks.",						/* 嗯，我很好。*/
	"I can't complain, thanks.",		/* 嗯，还行吧。*/
	"How do you do?",					/* 初次见面。*/
	"Good bye!",						/* 再见。*/
	"Good morning!",					/* 早上好。*/
	"Good afternoon!",					/* 下午好。*/
	"Good evening!",					/* 晚上好。*/
	"See you later!",					/* 再见（过会见）。*/
	"Go ahead, please.",				/* 您先请。*/
	"Thank you.",						/* 谢谢。*/
	"No, thank you.",					/* 不，谢谢。*/
	"May I have your name?",			/* 请问你叫什么名字？*/
	"I'm glad to meet you.",			/* 很高兴能见到你。*/
	"What time is it now?",				/* 请问现在是几点？*/
	"It's about seven.",				/* 大概7点。*/
	"I must go now.",					/* 我不得不走了。*/
	"How much?",						/* 多少钱？*/
	"Where is the restroom?",			/* 请问洗手间在哪里？*/
	"Excuse me.",						/* 抱歉（一人）。*/
	"Excuse us.",						/* 抱歉（两人以上）。*/
	"I'm sorry.",						/* 对不起。*/
	"I don't know.",					/* 我不知道。*/
	"I have no change with me.",		/* 我没带零钱。*/
	"I will be back.",					/* 我还会回来的。*/
	"Are you going out?",				/* 你要出门吗？*/
	"I hope I'm not disturbing you.",	/* 希望不会打搅到你。*/
	"I'll offer no excuse.",			/* 我没打算为自己辩解。*/
	"Shall we dance?",					/* 来跳舞吧。*/
	"Will you do me a favor?",			/* 你能帮我个忙吗？*/
	"It's very unseasonable.",			/* 这非常不合时节啊。*/
	"You are always welcome.",			/* 随时欢迎。*/
	"Hold still!",						/* 别动！*/
	"Follow me.",						/* 跟我来。*/
	"Just follow my lead.",				/* 跟着我做就好。*/
	"To be honest with you,",			/* 说真的……*/
};

/*--- 字符串str的打字练习（返回错误次数） ---*/
int go(const char *str)
{
	int i;
	int len = strlen(str);			/* 字符数量 */
	int mistake = 0;				/* 错误次数 */

	for (i = 0; i < len; i++) {
		/* 显示str[i]之后的字符并把光标返回到开头 */
		printf("%s \r", &str[i]);
		fflush(stdout);
		while (getch() != str[i]) {
			mistake++;
		}
	}
	return mistake;
}

/*--- 单一位置训练 ---*/
void pos_training(void)
{
	int i;
	int stage;
	int temp, line;
	int len;						/* 用于出题的块的键数 */
	int qno, pno;					/* 题目编号和上一次的题目编号 */
	int tno, mno;					/* 字符数量和错误次数 */
	clock_t	start, end;				/* 开始时间和结束时间 */

	printf("\n进行单一位置训练。\n");
	printf("请选择要练习的块。\n");
	printf("第1层 (1) 左 %-8s    (2) 右 %-8s\n", kstr[ 0], kstr[ 1]);
	printf("第2层 (3) 左 %-8s    (4) 右 %-8s\n", kstr[ 4], kstr[ 5]);
	printf("第3层 (5) 左 %-8s    (6) 右 %-8s\n", kstr[ 8], kstr[ 9]);
	printf("第4层 (7) 左 %-8s    (8) 右 %-8s\n", kstr[12], kstr[13]);

	/* 让玩家选择块 */
	do {
		printf("编号（停止练习为99）：");
		scanf("%d", &temp);
		if (temp == 99) return;				/* 停止练习 */
	} while (temp < 1 || temp > 8);
	line = 4 * ((temp - 1) / 2) + (temp - 1) % 2;

	printf("练习%s次%d题目。\n", kstr[line], NO);

	printf("按下空格键开始。\n");
	while (getch() != ' ')
		;

	tno = mno = 0;						/* 清空字符数量和错误次数 */
	len = strlen(kstr[line]);			/* 要练习的块的键数 */

	start = clock();						/* 开始时间 */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++)	/* 生成用于出题的字符串 */
			str[i] = kstr[line][rand() % len];
		str[i] = '\0';

		mno += go(str);						/* 运行练习 */
		tno += strlen(str);
	}

	end = clock();							/* 结束时间 */

	printf("题目：%d字符/错误：%d次\n", tno, mno);
	printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- 混合位置训练 ---*/
void pos_training2(void)
{
	int i;
	int stage;
	int temp, line;
	int sno;						/* 被选中的块数 */
	int select[KTYPE];				/* 被选中的块 */
	int len[KTYPE];					/* 用于出题的块的键数 */
	int tno, mno;					/* 字符数量和错误次数 */
	clock_t	start, end;				/* 开始时间和结束时间 */
	char *format = "第%d层 (%2d) 左 %-8s (%2d) 右 %-8s "
					      "(%2d)[左] %-8s (%2d)[右] %-8s\n";

	printf("\n进行混合位置训练。\n");
	printf("请选择要练习的块（可以多选）。\n");

	for (i = 0; i < 4; i++) {
		int k = i * 4;
		printf(format, i+1, k + 1, kstr[k],		k + 2, kstr[k + 1],
							k + 3, kstr[k + 2], k + 4, kstr[k + 3]);
	}

	/* 不重复选择块（最多16个） */
	sno = 0;
	while (1) {
		printf("编号（结束选择为50/停止练习为99）：");

		do {
			scanf("%d", &temp);
			if (temp == 99) return;			/* 停止练习 */
		} while ((temp < 1 || temp > KTYPE) && temp != 50);

		if (temp == 50)
			break;
		for (i = 0; i < sno; i++)
			if (temp == select[i]) {
				printf("\a这一层已经被选过了。\n");
				break;
			}
		if (i == sno)
			select[sno++] = temp;			/* 注册被选中的块 */
	}

	if (sno == 0)							/* 一个都没有选 */
		return;

	printf("把下列块的题目练习%d次。\n", NO);

	for (i = 0; i < sno; i++)
		printf("%s ", kstr[select[i] - 1]);

	printf("\n按下空格键开始。\n");
	while (getch() != ' ')
		;

	tno = mno = 0;							/* 清空字符数量和错误次数 */
	for (i = 0; i < sno; i++)
		len[i] = strlen(kstr[select[i] - 1]);	/* 块的键数 */

	start = clock();						/* 开始时间 */

	for (stage = 0; stage < NO; stage++) {
		char str[POS_LEN + 1];

		for (i = 0; i < POS_LEN; i++) {		/* 生成用于出题的字符串 */
			int q = rand() % sno;
			str[i] = kstr[select[q] - 1][rand() % len[q]];
		}
		str[i] = '\0';

		mno += go(str);						/* 运行练习 */
		tno += strlen(str);
	}

	end = clock();							/* 结束时间 */

	printf("题目：%d字符/错误：%d次\n", tno, mno);
	printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- C语言/英语会话训练 ---*/
void word_training(const char *mes, const char *str[], int n)
{
	int stage;
	int qno, pno;					/* 题目编号和上一次的题目编号 */
	int tno, mno;					/* 字符数量和错误次数 */
	clock_t	start, end;				/* 开始时间和结束时间 */

	printf("\n练习%d个%s。\n", mes, NO);

	printf("按下空格键开始。\n");
	while (getch() != ' ')
		;

	tno = mno = 0;					/* 清空字符数量和错误次数 */
	pno = n;						/* 上一次的题目编号（不存在的编号） */

	start = clock();				/* 开始时间 */

	for (stage = 0; stage < NO; stage++) {
		do {						/* 不连续出同一个题目 */
			qno = rand() % n;
		} while (qno == pno);

		mno += go(str[qno]);		/* 题目是str[qno] */
		tno += strlen(str[qno]);
		pno = qno;
	}

	end = clock();					/* 结束时间 */

	printf("题目：%d字符/错误：%d次\n", tno, mno);
	printf("用时%.1f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);
}

/*--- 选择菜单 ---*/
Menu SelectMenu(void)
{
	int ch;

	do {
		printf("\n请选择练习。\n");
		printf("(1) 单一位置       (2) 混合位置\n");
		printf("(3) C语言的单词    (4) 英语会话      (0) 结束 ：");
		scanf("%d", &ch);
	} while (ch < Term || ch >= InValid);

	return (Menu)ch;
}

int main(void)
{
	Menu menu;										/* 菜单 */
	int cn = sizeof(cstr) / sizeof(cstr[0]);		/* C语言的单词数量 */
	int vn = sizeof(vstr) / sizeof(vstr[0]);		/* 英语会话的文档数量 */

	init_getputch();

	srand(time(NULL));								/* 设定随机数种子 */

	do {
		switch (menu = SelectMenu()) {

		 case KeyPos :						/* 单一位置训练 */
		 			pos_training();
		 			break;

		 case KeyPosComp :					/* 混合位置训练 */
		 			pos_training2();
		 			break;

		 case Clang :						/* C语言的单词 */
		 			word_training("C语言的单词", cstr, cn);
		 			break;

		 case Conversation :				/* 英语会话 */
		 			word_training("英语会话的文档", vstr, vn);
		 			break;
		}
	} while (menu != Term);

	term_getputch();

	return 0;
}
