/* bcopy：文件的复制 */

#include <stdio.h>

#define BSIZE	1024			/* 分割成这个大小后进行复制 */

int main(int argc, char *argv[])
{
	int n;
	FILE *src, *dst;
	unsigned char buf[BSIZE];

	if (argc != 3) {
		fprintf(stderr, "参数不正确。\n");
		fprintf(stderr, "bcopy 源位置的文件名 目标位置的文件名\n");
	} else {
		if ((src = fopen(*++argv, "rb")) == NULL) {
			fprintf(stderr, "文件%s无法打开。\n", *argv);
			return 1;
		} else if ((dst = fopen(*++argv, "wb")) == NULL) {
			fprintf(stderr, "文件%s无法打开。\n", *argv);
			fclose(src);
			return 1;
		} else {
			while ((n = fread(buf, BSIZE, 1, src)) > 0)
				fwrite(buf, n, 1, dst);
			fclose(src);
			fclose(dst);
		}
	}
	return 0;
}
