#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000000

int main()
{
    int iCase, T, l1;
    int P, Q;
    int ans,flag;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);
    for (iCase=1;iCase<=T;iCase++)
    {
        scanf("%d/%d",&P,&Q);
        if (P>Q)
        {
            printf("Case #%d: impossible\n",iCase);
            continue;
        }
        for (l1=2;l1<=P;l1++)
            while ( P%l1 ==0 && Q%l1 ==0 )
            {
                P = P/l1;
                Q = Q/l1;
            }
        ans = 0;
        flag = 1;
        while (Q>1)
        {
            if ( Q % 2 !=0)
            {
                flag = 0;
                break;
            }
            if ( P < Q)
                ans++;
            Q = Q/2;
        }
        if (flag==1)
            printf("Case #%d: %d\n",iCase,ans);
        else
            printf("Case #%d: impossible\n",iCase);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
