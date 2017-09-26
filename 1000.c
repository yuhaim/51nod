#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned int A, B;
    while(scanf("%u%u", &A, &B))
    {
        printf("%u\n",A+B);
    }
    return 0;
}