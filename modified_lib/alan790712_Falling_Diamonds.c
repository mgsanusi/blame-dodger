#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1234567];
int v[256]={0};
int l;
int main(){
    v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = 1;
    int t,T;
    int i,j,k;
    int len;
    int ans;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%s %d",str,&l);
        len = strlen(str);
        ans = 0;
        for(i=0;i<len;++i){
            for(j=i,k=0;j<len;++j){
                k=(v[str[j]]==1)?0:k+1;
                if(k==l)break;
            }
            ans += len-j;
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
