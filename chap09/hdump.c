/* hdump：文件的转储 */

#include <ctype.h>
#include <stdio.h>
#include <limits.h>

/*--- 把流src的内容转储到dst ---*/
void hdump(FILE *src, FILE *dst)
{
	int n;
	unsigned long count = 0;
	unsigned char buf[16];

	while ((n = fread(buf, 1, 16, src)) > 0) {
		int i;

		fprintf(dst, "%08lX ", count);						/* 地址 */

		for (i = 0; i < n; i++)								/* 十六进制数字 */
			fprintf(dst, "%0*X ", (CHAR_BIT + 3) / 4, (unsigned)buf[i]);

		if (n < 16)
			for (i = n; i < 16; i++) fputs("   ", dst);

		for (i = 0; i < n; i++)								/* 字符 */
			fputc(isprint(buf[i]) ? buf[i] : '.', dst);

		fputc('\n', dst);

		count += 16;
	}
	fputc('\n', dst);
}

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc < 2)
		hdump(stdin, stdout);		/* 标准输入 → 标准输出 */
	else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "rb")) == NULL) {
				fprintf(stderr, "文件%s无法正确打开。\n", 
								*argv);
				return 1;
			} else {
				hdump(fp, stdout);	/* 流fp → 标准输出 */
				fclose(fp);
			}
		}
	}
	return 0;
}
