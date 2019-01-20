/* 用于getch/putch的通用头文件"getputch.h" */

#ifndef __GETPUTCH

  #define __GETPUTCH

  #if defined(_MSC_VER) || (__TURBOC__) || (LSI_C)

	/* MS-Windows／MS-DOS（Visual C++, Borland C++, LSI-C 86 etc ...）*/

	#include <conio.h>

	static void init_getputch(void) { /* 空 */ }

	static void term_getputch(void) { /* 空 */ }


  #else

	/* 提供了Curses库的UNIX/Linux/OS X环境 */

	#include <curses.h>

	#undef putchar
	#undef puts
	#undef printf
	static char __buf[4096];

	/*--- _ _putchar：相当于putchar函数（用“换行符+回车符”代替换行符进行输出）---*/
	static int __putchar(int ch)
	{
		if (ch == '\n')
			putchar('\r');
		return putchar(ch);
	}

	/*--- putch：显示1个字符，清除缓冲区 ---*/
	static int putch(int ch)
	{
		int result = putchar(ch);

		fflush(stdout);
		return result;
	}

	/*--- _ _printf：相当于printf函数（用“换行符+回车符”代替换行符进行输出）---*/
	static int __printf(const char *format, ...)
	{
		va_list	ap;
		int 	count;

		va_start(ap, format);
		vsprintf(__buf, format, ap);
		va_end(ap);

		for (count = 0; __buf[count]; count++) {
			putchar(__buf[count]);
			if (__buf[count] == '\n')
				putchar('\r');
		}
		return count;
	}

	/*--- _ _puts：相当于puts函数（用“换行符+回车符”代替换行符进行输出）---*/
	static int __puts(const char *s)
	{
		int i, j;

		for (i = 0, j = 0; s[i]; i++) {
			__buf[j++] = s[i];
			if (s[i] == '\n')
				__buf[j++] = '\r';
		}
		return puts(__buf);
	}

	/*--- 库初始处理 ---*/
	static void init_getputch(void)
	{
		initscr();
		cbreak();
		noecho();
		refresh();
	}

	/*--- 库终止处理 ---*/
	static void term_getputch(void)
	{
		endwin();
	}

	#define putchar	__putchar
	#define	printf	__printf
	#define puts	__puts

  #endif

#endif
