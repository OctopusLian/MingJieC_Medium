/*--- hit��blow���ж� ---*/
void judge(const char s[], const int no[], int *hit, int *blow)
{
	int i, j;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j])	/* ����һ�� */
				if (i == j)
					(*hit)++;			/* hit��λ��Ҳһ�£�*/
				else
					(*blow)++;			/* blow��λ�ò�һ�£�*/
		}
	}
}
