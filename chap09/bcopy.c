/* bcopy���ļ��ĸ��� */

#include <stdio.h>

#define BSIZE	1024			/* �ָ�������С����и��� */

int main(int argc, char *argv[])
{
	int n;
	FILE *src, *dst;
	unsigned char buf[BSIZE];

	if (argc != 3) {
		fprintf(stderr, "��������ȷ��\n");
		fprintf(stderr, "bcopy Դλ�õ��ļ��� Ŀ��λ�õ��ļ���\n");
	} else {
		if ((src = fopen(*++argv, "rb")) == NULL) {
			fprintf(stderr, "�ļ�%s�޷��򿪡�\n", *argv);
			return 1;
		} else if ((dst = fopen(*++argv, "wb")) == NULL) {
			fprintf(stderr, "�ļ�%s�޷��򿪡�\n", *argv);
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
