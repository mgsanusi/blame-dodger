#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x,y) ( ((x)<(y))?(x):(y) )
int e,r,n;
int v[1234];
int ans;
void DFS(int now,int eNow,int sum){
    if(now>=n){
        if(ans < sum){
            ans = sum;
        }
        return;
    }
    int i;
    for(i=0;i<=eNow;++i){
        DFS(now+1,MIN(eNow-i+r,e),sum+i*v[now]);
    }
}
int main(){
    int T,t;
    int i;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%d %d %d",&e,&r,&n);
        printf("Case #%d: ",t);
        for(i=ans=0;i<n;++i){
            scanf("%d",&v[i]);
        }
        DFS(0,e,0);
        printf("%d\n",ans);
    }

    return 0;
}
