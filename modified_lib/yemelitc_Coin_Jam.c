#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int x, T;
    int i, j, k, m, N, J;
    long long a;

    scanf("%u", &T);

    for(x=1; x<=T; x++)
    {
        scanf("%d %d", &N, &J);

        printf("Case #%d:\n", x);

        for(i=0; i<J; i++) // for every jamcoin
        {
            printf("1"); // starting 1
            for(m=i, j=0; j<N/2-2; j++) { printf("%d", m&1); m/=2; }
            printf("11"); // middle 11
            for(m=i, j=0; j<N/2-2; j++) { printf("%d", m&1); m/=2; }
            printf("1 "); // ending 1

            for(k=2; k<=10; k++)
            {
                a=1; m=i;
                for(j=0; j<N/2-2; j++)
                { a = a*k+(m&1); m/=2; }
                a = a*k + 1;
                printf(" %lld", a);
            }
            printf("\n");
        }
    }
}

