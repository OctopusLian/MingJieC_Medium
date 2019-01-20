/* concat ������ �ļ��ĸ��� */

#include <stdio.h>

/*--- �Ѵ�src��������������dst ---*/
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
		copy(stdin, stdout);		/* ��׼���� �� ��׼��� */
	else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "�ļ�%s�޷���ȷ�򿪡�\n", 
								*argv);
				return 1;
			} else {
				copy(fp, stdout);	/* ��fp �� ��׼��� */
				fclose(fp);
			}
		}
	}
	return 0;
}
