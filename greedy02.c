// X轴上有N条线段，每条线段有1个起点S和终点E。最多能够选出多少条互不重叠的线段。（注：起点或终点重叠，不算重叠）。
// 例如：[1 5][2 3][3 6]，可以选[2 3][3 6]，这2条线段互不重叠。

// 输入

// 第1行：1个数N，线段的数量(2 <= N <= 10000)
// 第2 - N + 1行：每行2个数，线段的起点和终点(-10^9 <= S,E <= 10^9)

// 输出

// 输出最多可以选择的线段数量。

// 输入示例

// 3
// 1 5
// 2 3
// 3 6

// 输出示例

// 2

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int start;
    int end;
} time_pair;

int compar_time_pair(const void *a, const void *b)
{
    return ((time_pair *)a)->end - ((time_pair *)b)->end;
}

int main(int argc, char *argv[])
{
    unsigned int N; 
    time_pair *S;
    int i;
    int count = 0;
    int current_end_time = -1000000000;

    scanf("%u", &N);
    S = (time_pair *)calloc(N, sizeof(time_pair));

    for (i=0;i<N;i++)
    {
        scanf("%d%d",&((S+i)->start),&((S+i)->end));
    }

    qsort(S, N, sizeof(time_pair), compar_time_pair);
    
    for (i=0;i<N;i++)
    {
        if(S[i].start >= current_end_time)
        {
            current_end_time = S[i].end;
            count++;
        }
    }

    printf("%d\n", count);

    free(S);
    return 0;
}