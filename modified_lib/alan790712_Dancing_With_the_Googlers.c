#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int s;
int p;
int score;
int max[31][2];

int main(){
    int t;
    int i,j;
    int ans;
    int Case = 0;
    for(i=0;i<31;++i){
        max[i][0] = (i+2)/3;
        max[i][1] = 2+(i-2)/3;
        if(max[i][1]*3-4 > i || max[i][1]>10)max[i][1]=max[i][0];
//      printf("%d %d %d\n",i,max[i][0],max[i][1]);
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&s,&p);
        ans = 0;
        while(n--){
            scanf(" %d",&score);

            if(max[score][0] >= p){
                ++ans;
            }else if(max[score][1] >= p && s>0){
                ++ans;
                --s;
            }

        }
        printf("Case #%d: %d\n",++Case,ans);
    }
    return 0;
}
