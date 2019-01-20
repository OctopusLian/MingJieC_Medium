/* detab ������ չ��ˮƽ�Ʊ�� */

#include <stdio.h>
#include <stdlib.h>

/*--- չ��tab���Ѵ�src��������������dst ---*/
void detab(FILE *src, FILE *dst, int width)
{
	int ch, pos = 1;

	while ((ch = fgetc(src)) != EOF) {
		int num;

		switch (ch) {
		 case '\t':							/* �Ʊ�� */ 
			num = width - (pos - 1) % width;
			for ( ; num > 0; num--) {
				fputc(' ', dst);
				pos++;
			}
			break;

		 case '\n':							/* ���з� */
			fputc(ch, dst); pos=1; break;

		 default:							/* �����ַ� */
			fputc(ch, dst); pos++; break;
		}
	}
}

int main(int argc, char *argv[])
{
	int  width = 8;
	FILE *fp;

	if (argc < 2)
		detab(stdin, stdout, width);		/* ��׼���� �� ��׼��� */
	else {
		while (--argc > 0) {
			if (**(++argv) == '-') {
				if (*++(*argv) == 't')
					width = atoi(++*argv);
				else {
					fputs("��������ȷ��\n", stderr);
					return 1;
				}
			} else if ((fp = fopen(*argv, "r")) == NULL) {
				fprintf(stderr, "�ļ�%s�޷���ȷ�򿪡�\n",
								*argv);
				return 1;
			} else {
				detab(fp, stdout, width);	/* ��fp �� ��׼��� */
				fclose(fp);
			}
		}
	}
	return 0;
}
