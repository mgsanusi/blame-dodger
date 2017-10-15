#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int tt,rr;
int main(){
    int T,t;
    int i;
    long long int l,r,m;
    long long int ans;
    long long int tmp[2];
    int key;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%lld %lld",&rr,&tt);
        printf("Case #%d: ",t);
        l=0,r=1000000000LL;
        ans = -1;

        while(l<=r){
                key = 1;
            m = (l+r)/2LL;
            tmp[0] = ((2*m)-1)*m;
            if(tmp[0]>tt)key = 0;
            tmp[1] = 2*m*rr;
            if(tmp[1]>tt)key = 0;
            if(tmp[0]+tmp[1]>tt)key = 0;
            if(key){
                if(m>ans)ans = m;
                l = m+1;
            }else {
                r = m-1;
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}

