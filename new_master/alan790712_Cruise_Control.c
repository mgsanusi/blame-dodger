#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int num[12340];
int n;
char used[114];
int s[3234567];
int sNum;
int cmp(const void*a,const void*b){
    return *(int*)a - *(int*)b;
}
void DFS(int now,int sum){
    if(now==n){
        s[sNum++] = sum;
        return;
    }
    DFS(now+1,sum+num[now]);
    DFS(now+1,sum);
}
int ans;
int aaaa;
void DFS2(int now,int sum){

    if(sum==ans){
        int i,s;
        for(i=s=0;i<now;++i){
            if(used[i]){
                if(s==1)printf(" %d",num[i]);
                else printf("%d",num[i]);
                s=1;
            }
        }
        puts("");
        ++aaaa;
        return;
    }
    if(now==n || aaaa==2){
        return;
    }
    used[now] = 1;
    DFS2(now+1,sum+num[now]);
    used[now] = 0;
    DFS2(now+1,sum);
}
int main(){
    int Case = 0;
    int t;
    int i;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;++i){
            scanf("%d",&num[i]);
        }
        memset(s,0,sizeof(s));
        sNum=0;
        DFS(0,0);
        qsort(s,sNum,sizeof(int),cmp);
        for(i=1;i<sNum && s[i] != s[i-1];++i);
        printf("Case #%d:\n",++Case);
        if(i>=sNum){
            puts("Impossible");
        }else {
            ans = s[i];
            aaaa=0;
            memset(used,0,sizeof(used));
            DFS2(0,0);
        }

    }
    return 0;
}
