/*--- ����4����ͬ���ֵ���ϲ���������x ---*/
void make4digits(int x[])
{
	int i, j, val;

	for (i = 0; i < 4; i++) {
		do {
			val = rand() % 10;			/* 0~9������� */
			for (j = 0; j < i; j++)		/* �Ƿ��ѻ�ô���ֵ */
				if (val == x[j])
					break;
		} while (j < i);		/* ѭ��ֱ����ò��ظ�����ֵ */
		x[i] = val;
	}
}
