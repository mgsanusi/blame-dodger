#include <stdio.h>
#include <stdlib.h>

int main()
{
    double nao[1000],ken[1000], temp;
    int T, N, y, z;
    int iCase, i, j, i0;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);

    for ( iCase=1; iCase<=T; iCase++)
    {
        scanf("%d",&N);
        for ( i=0; i<N; i++)
            scanf("%lf",&nao[i]);
        for ( i=0; i<N; i++)
            scanf("%lf",&ken[i]);

        for ( i=0; i<N-1; i++)
            for ( j=N-2; j>=i; j--)
                if ( nao[j]>nao[j+1])
                {
                    temp = nao[j];
                    nao[j] = nao[j+1];
                    nao[j+1] = temp;
                }
        for ( i=0; i<N-1; i++)
            for ( j=N-2; j>=i; j--)
                if ( ken[j]>ken[j+1])
                {
                    temp = ken[j];
                    ken[j] = ken[j+1];
                    ken[j+1] = temp;
                }

        y = 0;
        i = N-1;
        i0 = 0;
        j = N-1;
        while ((i>=i0) && (j>=0))
            if (nao[i]>ken[j])
            {
                y++;
                i--;
                j--;
            }
            else
            {
                i0++;
                j--;
            }

        z = N;
        i = N-1;
        j = N-1;
        while ((j>=0)&&(i>=0))
            if (ken[j]>nao[i])
            {
                z--;
                j--;
                i--;
            }
            else
                i--;

        printf("Case #%d: %d %d\n", iCase, y, z);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
