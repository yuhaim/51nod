
// 约翰认为字符串的完美度等于它里面所有字母的完美度之和。每个字母的完美度可以由你来分配，不同字母的完美度不同，分别对应一个1-26之间的整数。

// 约翰不在乎字母大小写。（也就是说字母F和f）的完美度相同。给定一个字符串，输出它的最大可能的完美度。例如：dad，你可以将26分配给d，25分配给a，这样整个字符串完美度为77。

// 分析： 由排序不等式，出现次数最多的字母显然应该给26。所以这个题目变成了统计每种字母出现的次数了，然后按照出现次数从大到小，依次分配从高到低的权值。这就是最朴素的贪心思想。

// 输入

// 输入一个字符串S(S的长度 <= 10000)，S中没有除字母外的其他字符。

// 输出

// 由你将1-26分配给不同的字母，使得字符串S的完美度最大，输出这个完美度。

// 输入示例

// dad

// 输出示例

// 77


#include <stdio.h>
#include <string.h>

int find_max_index(int data[], int length, int *index)
{
    int max_value, max_index;
    int i;

    max_value = data[0];
    max_index = 0;
    for(i=1;i<length;i++)
    {
        if(data[i]>max_value)
        {
            max_value = data[i];
            max_index = i;
        }
    }

    *index = max_index;
    return max_value;
}

int main(int argc, char *argv[])
{
    const int LENGTH = 10001;
    const int LIST_LENGTH = 26;
    char strS[LENGTH];
    int length;
    int count[LIST_LENGTH];
    int order[LIST_LENGTH];
    int i;
    char tmpChar;
    int currentOrder = LIST_LENGTH;
    unsigned long sum = 0;

    for (i=0;i<LIST_LENGTH;i++)
    {
        count[i] = 0;
        order[i] = 0;
    }

    scanf("%s",strS);
    length = strlen(strS);
    for(i=0;i<length;i++)
    {
        tmpChar = strS[i];
        if(tmpChar>='a' && tmpChar<='z')
        {
            count[tmpChar-'a']++;
        }
        else
        {
            count[tmpChar-'A']++;
        }
    }

    while(find_max_index(count, LIST_LENGTH, &i))
    {
        order[i] = currentOrder--;
        count[i] = 0; 
    }

    for (i=0;i<length;i++)
    {
        tmpChar = strS[i];
        if(tmpChar>='a' && tmpChar<='z')
        {
            sum += order[tmpChar-'a'];
        }
        else
        {
            sum += order[tmpChar-'A'];
        }
    }

    printf("%ld\n",sum);

    return 0;
}