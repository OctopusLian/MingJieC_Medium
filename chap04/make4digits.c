/*--- 生成4个不同数字的组合并存入数组x ---*/
void make4digits(int x[])
{
	int i, j, val;

	for (i = 0; i < 4; i++) {
		do {
			val = rand() % 10;			/* 0~9的随机数 */
			for (j = 0; j < i; j++)		/* 是否已获得此数值 */
				if (val == x[j])
					break;
		} while (j < i);		/* 循环直至获得不重复的数值 */
		x[i] = val;
	}
}
