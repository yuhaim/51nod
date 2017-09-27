// 给出两个字符串A B，求A与B的最长公共子序列（子序列不要求是连续的）。
// 比如两个串为：

// abcicba
// abdkscab

// ab是两个串的子序列，abc也是，abca也是，其中abca是这两个字符串最长的子序列。
// Input
// 第1行：字符串A
// 第2行：字符串B
// (A,B的长度 <= 1000)
// Output
// 输出最长的子序列，如果有多个，随意输出1个。
// Input示例
// abcicba
// abdkscab
// Output示例
// abca

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    const int LENGTH = 1001;
    char strA[LENGTH];
    char strB[LENGTH];
    int lengthA;
    int lengthB;
    int i, j;

    char strCommon[LENGTH];

    scanf("%s%s",strA,strB);
    lengthA = strlen(strA);
    lengthB = strlen(strB);

    for(i=0;i<lengthA;i++)
    {
        for(j=0;j<lengthB;j++)
        {
            
        }
    }

    printf("%s\n",strCommon);
    return 0;
}