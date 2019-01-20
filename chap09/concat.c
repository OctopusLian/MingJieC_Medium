/* concat ··· 文件的复制 */

#include <stdio.h>

/*--- 把从src输入的数据输出到dst ---*/
void copy(FILE *src, FILE *dst)
{
	int	ch;

	while ((ch = fgetc(src)) != EOF)
		fputc(ch, dst);
}

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
		copy(stdin, stdout);		/* 标准输入 → 标准输出 */
	else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "文件%s无法正确打开。\n", 
								*argv);
				return 1;
			} else {
				copy(fp, stdout);	/* 流fp → 标准输出 */
				fclose(fp);
			}
		}
	}
	return 0;
}
