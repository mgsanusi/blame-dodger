#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iCase, T, l1, l2;
    int A, B, K, num;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);
    for (iCase=1;iCase<=T;iCase++)
    {
        scanf("%d%d%d",&A,&B,&K);
        num = 0;
        for (l1=0;l1<A;l1++)
            for (l2=0;l2<B;l2++)
                if ( (l1 & l2) <K)
                    num++;
        printf("Case #%d: %d\n",iCase,num);
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
