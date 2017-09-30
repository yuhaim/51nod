// 输入2个正整数A，B，求A与B的最大公约数。
// Input
// 2个数A,B，中间用空格隔开。(1<= A,B <= 10^9)
// Output
// 输出A与B的最大公约数。
// Input示例
// 30 105
// Output示例
// 15

#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned long A, B, temp;
    scanf("%ld%ld",&A,&B);

    while(temp = A%B)
    {
        A = B;
        B = temp;
    }

    printf("%ld\n",B);
    return 0;
}