#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void caishu(int maxnum)
{
    int no;  //读取的值
    int ans;  //目标数字
    srand(time(NULL));  //设定随机数的种子
    ans = rand()% (maxnum + 1);  //随机数0 ~ maxnum
    printf("请猜一个0 ~ %d的整数。\n\n",maxnum);

    do {
        scanf("%d",&no);

        if (no > ans)
            printf("再小一点。\n");
        else if (no < ans)
            printf("再大一点。\n");
    } while (no != ans);

    if (no != ans)
        printf("很遗憾，正确答案是%d。\n",ans);
    else {
        printf("回答正确。\n");
    }
}

int main(void)
{
    
    int rank;  //难度
    printf("请选择难度等级:(1)1~9 (2)1~99 (3)1~999 (4)1~9999\n");
    scanf("%d",&rank);
    switch (rank)
    {
    case 1:
    caishu(9);

    case 2:
    caishu(99);

    case 3:
    caishu(999);

    case 4:
    caishu(9999);

    default:
    printf("无效数字\n");

    }
}

