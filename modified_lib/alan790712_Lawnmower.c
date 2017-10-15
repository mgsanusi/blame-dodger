#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n,m;
int map[123][123];
int gg;
int new_puts(const char *str);

int main(){
    int t,T;
    int i,j;
    int p;
    int max;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%d %d",&n,&m);
        memset(map,0,sizeof(map));
        for(i=max=1;i<=n;++i){
            for(j=1;j<=m;++j){
                scanf("%d",&map[i][j]);
                if(map[i][j] >= max)max = map[i][j];
            }
        }
        gg = 0;
        for(i=1;i<=n&&!gg;++i){
            for(j=1;j<=m && !gg ;++j){
                for(p=1;p<=m && map[i][p] <= map[i][j];++p);
                if(p>m)  continue;
                for(p=1;p<=n && map[p][j] <= map[i][j];++p);
                if(p<=n) gg = 1;
            }
        }
        printf("Case #%d: ",t);
        if(!gg)new_puts("YES");
        else new_puts("NO");
    }
    return 0;
}

int new_puts(const char *str) {
  return puts(str);
}