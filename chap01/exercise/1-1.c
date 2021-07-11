#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ans;
    srand(time(NULL));  //设定随机数的种子
    ans = rand() % 7;  //设定0~6的随机数

        switch (ans)
        {
        case 0:
            printf("大吉");
            break;
        case 1:
            printf("中吉");
            break;
        case 2:
            printf("小吉");
            break;
        case 3:
            printf("吉");
            break;
        case 4:
            printf("末吉");
            break;
        case 5:
            printf("凶");
            break;
        case 6:
            printf("大凶");
            break;

        default:
            break;
        }
        
}