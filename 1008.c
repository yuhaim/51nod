// 输入N和P（P为质数），求N! Mod P = ? (Mod 就是求模 %)
// 例如：n = 10， P = 11，10! = 3628800
// 3628800 % 11 = 10
// Input
// 两个数N,P，中间用空格隔开。(N < 10000, P < 10^9)
// Output
// 输出N! mod P的结果。
// Input示例
// 10 11
// Output示例
// 10

#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned long long N, P;
    unsigned long long tmpInt = 1;
    int i;
    scanf("%lld%lld", &N, &P);
    
    for(i=N;i>0;i--)
    {
        // tmpInt *= i%P;
        // tmpInt = tmpInt%P;
        tmpInt = tmpInt*i%P; //both OK, but OJ environment 32bit overflows
    }

    printf("%lld\n",tmpInt);
    return 0;
}