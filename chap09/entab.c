/* entab ··· 把空白字符转换成水平制表符 */

#include <stdio.h>
#include <stdlib.h>

/*--- 把从src输入的空白字符转换成制表符后输出到dst ---*/
void entab(FILE *src, FILE *dst, int width)
{
	int	ch;
	int	count = 0;
	int	ntab  = 0;
	int	pos   = 1;

	for ( ; (ch = fgetc(src)) != EOF; pos++)
		if (ch == ' ') {
			if (pos % width != 0)
				count++;
			else {
				count = 0;
				ntab++;
			}
		} else {
			for ( ; ntab > 0; --ntab)
				fputc('\t', dst);
			if (ch == '\t')
				count = 0;
			else
				for ( ; count > 0; count--)
					fputc(' ', dst);
			fputc(ch, dst);
			if (ch == '\n')
				pos = 0;
			else if (ch == '\t')
				pos += width - (pos - 1) % width - 1;
		}
}

int main(int argc, char *argv[])
{
	int	 width = 8;
	FILE *fp;

	if (argc < 2)
		entab(stdin, stdout, width);		/* 标准输入 → 标准输出 */
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
				entab(fp, stdout, width);	/* 流fp → 标准输出 */
				fclose(fp);
			}
		}
	}
	return 0;
}
