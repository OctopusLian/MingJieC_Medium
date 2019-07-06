#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int no;  //读取的值
    int ans;  //目标数字
    const int max_stage = 10;  //用户最多可以输入的次数
    int remain = max_stage;  //还可以输入几次

    srand(time(NULL));  //设定随机数的种子
    ans = -999 + rand()%1000;  //随机数-999 ~ 999
    printf("请猜一个-999 ~ 999的整数。\n\n");

    do {
        printf("还剩%d次机会。",remain);
        scanf("%d",&no);
        remain--;  //把所剩次数进行减量

        if (no > ans)
            printf("再小一点。\n");
        else if (no < ans)
            printf("再大一点。\n");
    } while (no != ans && remain > 0);

    if (no != ans)
        printf("很遗憾，正确答案是%d。\n",ans);
    else {
        printf("回答正确。\n");
        printf("您用了%d次猜中了。\n",max_stage - remain);
    }
    
    return 0;
}