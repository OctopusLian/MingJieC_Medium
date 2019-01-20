/*--- 检查已输入的字符串s的有效性 ---*/
int check(const char s[])
{
	int i, j;

	if (strlen(s) != 4)			/* 字符串长度不为4 */
		return 1;
	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i]))
			return 2;			/* 包含了除数字以外的字符 */
		for (j = 0; j < i; j++)
			if (s[i] == s[j])
				return 3;		/* 含有相同数字 */
	}
	return 0;					/* 字符串有效 */
}
