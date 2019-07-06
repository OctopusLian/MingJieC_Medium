#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int no;  //读取的值
    int ans;  //目标数字

    srand(time(NULL));  //设定随机数的种子
    ans = 3 + rand()%1000;  //随机数-999 ~ 999
    do {
        if (ans % 3 == 0)  {
        printf("请输入一个3 ~ 999之间3的整数。\n\n");
        scanf("%d",&no);
        if (no % 3 != 0) {
            printf("游戏结束!\n");
            return 0;
        }
        if (no > ans)
            printf("再小一点。\n");
        else if (no < ans)
            printf("再大一点。\n");
    }
    } while (no != ans);
    

    if (no != ans)
        printf("很遗憾，正确答案是%d。\n",ans);
    else {
        printf("回答正确。\n");
    }
    
    return 0;
    
}