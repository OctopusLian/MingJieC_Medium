/*--- hit和blow的判断 ---*/
void judge(const char s[], const int no[], int *hit, int *blow)
{
	int i, j;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j])	/* 数字一致 */
				if (i == j)
					(*hit)++;			/* hit（位置也一致）*/
				else
					(*blow)++;			/* blow（位置不一致）*/
		}
	}
}
