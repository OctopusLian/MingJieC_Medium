#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int no;  //读取的值
    int ans;
    int startrand,endrand;  //声明开始和结束范围的随机数
    int max_stage;  //声明用户的最大猜数次数
    int diff;  //开始数字和结束数字的差
    int remain = max_stage;  //还可以输入几次

    srand(time(NULL));  //设定随机数的种子
    startrand = rand();
    endrand = rand();
    while (startrand > endrand)  //开始种子数大于结束种子数
    {
        endrand = rand();
    }
    ans = startrand + rand() % (endrand + 1);
    
    diff = endrand - startrand;  //开始和结束的数字差
    if (diff > 0 && diff <= 100) {
        max_stage = 10;
    } else if (diff > 100 && diff <= 500) {
        max_stage = 50;
    } else if (diff > 500 && diff <= 5000) {
        max_stage = 100;
    } else {
        max_stage = 500;
    }

    do {
        printf("请猜一个范围在%d ~ %d的数字\n",startrand,endrand);
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