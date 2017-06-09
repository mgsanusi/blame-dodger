#include <stdio.h>

long a[1100];

int main(){
    long i,j,k,t,tt,d,ans,tmp;
    freopen("B-small-attempt0.in.txt", "r", stdin);
    freopen("B-small-attempt0.out.txt", "w", stdout);
    scanf("%ld",&t);
    for (tt=1;tt<=t;tt++){
        scanf("%ld",&d);
        for (i=0;i<d;i++){
            scanf("%ld",a+i);
        }
        for (i=1,ans=2000;i<=1000;i++){
            for (j=0,tmp=i;j<d;j++){
                if (a[j]%i==0)
                    tmp+=a[j]/i-1;
                else
                    tmp+=a[j]/i;
            }
            if (tmp<ans)
                ans=tmp;
        }
        printf("Case #%ld: %ld\n",tt,ans);
    }
    return 0;
}
