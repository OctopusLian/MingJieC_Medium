/* detab ··· 展开水平制表符 */

#include <stdio.h>
#include <stdlib.h>

/*--- 展开tab，把从src输入的数据输出到dst ---*/
void detab(FILE *src, FILE *dst, int width)
{
	int ch, pos = 1;

	while ((ch = fgetc(src)) != EOF) {
		int num;

		switch (ch) {
		 case '\t':							/* 制表符 */ 
			num = width - (pos - 1) % width;
			for ( ; num > 0; num--) {
				fputc(' ', dst);
				pos++;
			}
			break;

		 case '\n':							/* 换行符 */
			fputc(ch, dst); pos=1; break;

		 default:							/* 其他字符 */
			fputc(ch, dst); pos++; break;
		}
	}
}

int main(int argc, char *argv[])
{
	int  width = 8;
	FILE *fp;

	if (argc < 2)
		detab(stdin, stdout, width);		/* 标准输入 → 标准输出 */
	else {
		while (--argc > 0) {
			if (**(++argv) == '-') {
				if (*++(*argv) == 't')
					width = atoi(++*argv);
				else {
					fputs("参数不正确。\n", stderr);
					return 1;
				}
			} else if ((fp = fopen(*argv, "r")) == NULL) {
				fprintf(stderr, "文件%s无法正确打开。\n",
								*argv);
				return 1;
			} else {
				detab(fp, stdout, width);	/* 流fp → 标准输出 */
				fclose(fp);
			}
		}
	}
	return 0;
}
