#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int x, T;
    int i, K, C, S;
    unsigned long long y, kc;

    scanf("%u", &T);

    for(x=1; x<=T; x++)
    {
        scanf("%d %d %d", &K, &C, &S);

        for(kc=1, i=1; i<C; i++) kc *= K;
        //printf("kc=%llu\n", kc);

        printf("Case #%d:", x);

        for(y=0, i=0; i<S; i++) { printf(" %llu", y+1); y+=kc; }

        printf("\n");
    }
}

