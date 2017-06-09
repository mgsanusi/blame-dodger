#include <stdio.h>
#include <stdlib.h>
#define MINF 0.00000000001

int main()
{
    int T;
    int iCase;
    double C, F, X;
    double curC, curP, tim;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);

    for ( iCase=1; iCase<=T; iCase++)
    {
        scanf("%lf%lf%lf",&C,&F,&X);

        curC = 0;
        curP = 2.0;
        tim = 0;
        while (curC+MINF<X)
            if ((curC >= C-MINF) && (C/F < (X-curC)/curP))
            {
                curC = curC-C;
                curP = curP+F;
            }
            else if ((X-curC>C)&&(curC < C-MINF))
            {
                tim = tim+(C-curC)/curP;
                curC = C;
            }
            else
            {
                tim = tim + (X-curC)/curP;
                curC = X;
            }
        printf("Case #%d: %.8lf\n", iCase, tim);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
