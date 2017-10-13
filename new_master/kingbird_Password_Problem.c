#include <stdio.h>
#define MAX 200
#define min(a,b) ((a)<(b)?(a):(b))
double correct[MAX];
double chance[MAX];
int main()
{
    int cases,caseindex;
    double cons,temp;
    int a,b;
    int i;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d", &cases);
    correct[0] = 1;
    for(caseindex = 1; caseindex<=cases; caseindex++)
    {
        scanf("%d%d",&a,&b);
        for(i = 1; i<=a;i++)
        {
            scanf("%lf",&chance[i]);
            correct[i] = correct[i-1]*chance[i];
        }
        cons = 100000000;
        //give up
        cons = min(cons,b+2);
        //finish it
        temp = (b-a+1)*correct[a]+(1-correct[a])*(2*b-a+2);
        cons = min(cons,temp);
        //delete some
        for(i = 1; i<=a;i++)
        {
            temp = (b-a+1+2*i)*correct[a-i]+(1-correct[a-i])*(2*i+2*b-a+2);
            cons = min(cons, temp);
        }
        printf("Case #%d: %f\n",caseindex,cons);
    }
    return 0;
}
