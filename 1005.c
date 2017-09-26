// 给出2个大整数A,B，计算A+B的结果。
// Input
// 第1行：大数A
// 第2行：大数B
// (A,B的长度 <= 10000 需注意：A B有可能为负数）
// Output
// 输出A + B
// Input示例
// 68932147586
// 468711654886
// Output示例
// 537643802472

#include <stdio.h>

int parse_str(const char *str, int *num, int *sign)
{
    int i = 0, j = 0;

    str[0] == '-' ? (*sign = -1, i++) : (*sign = 1); 

    while(str[i])
    {
        num[j] = str[i] - '0';
        i++;
        j++;
    }
    
    return j;
}

int main(int argc, char *argv[])
{
    const int LENGTH = 10001;
    char strA[LENGTH];
    char strB[LENGTH];
    //char strSum[LENGTH+1];

    int signA;
    int signB;
    int lengthA = 0;
    int lengthB = 0;

    int intA[LENGTH];
    int intB[LENGTH];
    int intSum[LENGTH+1];
    int signSum;

    int i = 0, j = 0;
    int tmpA, tmpB, tmpSum, carry = 0;

    scanf("%s",strA);
    scanf("%s",strB);

    lengthA = parse_str(strA, intA, &signA);
    lengthB = parse_str(strB, intB, &signB);

    if (signA == signB)
    {
        signSum = signA;
        while(i<lengthA || i<lengthB)
        {
            tmpA = i>lengthA - 1 ? 0 : intA[lengthA-1-i];
            tmpB = i>lengthB - 1 ? 0 : intB[lengthB-1-i];
            tmpSum = tmpA + tmpB + carry;
            intSum[i] = tmpSum%10;
            carry = tmpSum/10;
            i++;
        }
    }
    else
    {
        if (lengthA > lengthB)
        {
            signSum = signA;
        }
        else if (lengthA < lengthB)
        {
            signSum = signB;
        }
        else
        {
            while(j<lengthA && intA[j] == intB[j])
            {
                j++;
            }

            if (j == lengthA)
            {
                signSum = 0;
            }
            else
            {
                if(intA[j] > intB[j])
                {
                    signSum = signA;
                }
                else
                {
                    signSum = signB;
                }
            }
        }

        if (signSum == signA)
        {
            while(i<lengthA)
            {
                tmpA = i>lengthA - 1 ? 0 : intA[lengthA-1-i];
                tmpB = i>lengthB - 1 ? 0 : intB[lengthB-1-i];

                if (tmpA + carry >= tmpB)
                {
                    tmpSum = tmpA - tmpB + carry;
                    carry = 0;
                }
                else if (tmpA + carry < tmpB)
                {
                    tmpSum = 10 + tmpA - tmpB + carry;
                    carry = -1;
                }

                intSum[i] = tmpSum;
                i++;
            }
        }
        else if(signSum == signB)
        {
            while(i<lengthB)
            {
                tmpA = i>lengthA - 1 ? 0 : intA[lengthA-1-i];
                tmpB = i>lengthB - 1 ? 0 : intB[lengthB-1-i];

                if (tmpB + carry >= tmpA)
                {
                    tmpSum = tmpB - tmpA + carry;
                    carry = 0;
                }
                else if (tmpB + carry < tmpA)
                {
                    tmpSum = 10 + tmpB - tmpA + carry;
                    carry = -1;
                }

                intSum[i] = tmpSum;
                i++;
            }
        }
        else
        {
            intSum[i] = 0;
            i++;
        }
    }

    if(signSum<0) 
        printf("-");

    if(carry>0)
        intSum[i++] = 1;

    while(i>1 && intSum[i-1]==0)
        i--;

    while(i>0)
    {
        printf("%c", intSum[i-1] + '0');
        i--;
    }

    printf("\n");
    return 0;
}