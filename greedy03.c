// 输入

// 第一行一个正整数n (n <= 10000)代表活动的个数。
// 第二行到第(n + 1)行包含n个开始时间和结束时间。
// 开始时间严格小于结束时间，并且时间都是非负整数，小于1000000000

// 输出

// 一行包含一个整数表示最少教室的个数。

// 输入示例

// 3
// 1 2
// 3 4
// 2 9

// 输出示例

// 2

#include <stdio.h>
#include <stdlib.h>

typedef enum {START, END} time_attr_t;

typedef struct 
{
    int time_value;
    time_attr_t time_attr;
}time_point;

int compar_time_point(const void *a, const void *b)
{
    return ((time_point *)a)->time_value - ((time_point *)b)->time_value;
}

int main(int argc, char *argv[])
{
    unsigned int N; 
    time_point *S;
    int i;
    int count = 0;
    int count_max = 0;

    scanf("%u", &N);
    S = (time_point *)calloc(2*N, sizeof(time_point));

    for (i=0;i<2*N;i+=2)
    {
        scanf("%d%d",&((S+i)->time_value),&((S+i+1)->time_value));
        (S+i)->time_attr=START;
        (S+i+1)->time_attr=END;
    }

    qsort(S, 2*N, sizeof(time_point),compar_time_point);

    for(i=0;i<2*N;i++)
    {
        if(S[i].time_attr == START)
        {
            count++;
        }
        else
        {
            count--;
        }

        if(count > count_max)
            count_max = count;
    }

    printf("%d\n",count_max);

    free(S);
    return 0;
}