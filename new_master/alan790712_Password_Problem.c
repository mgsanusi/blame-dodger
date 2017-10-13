#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[1234][2];
int pass[1234];
int n;

int main(){
    int Case=0;
    int t;
    int i,j;
    int max;
    int star;
    int step;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;++i){
            scanf("%d %d",&num[i][0],&num[i][1]);
        }
        memset(pass,0,sizeof(pass));
        star = step = 0;
        while(1){
            for(i=0,max=-1;i<n;++i){
                if(star >= num[i][1] && pass[i]<2){
                    max = i;
                    break;
                }else if(star >= num[i][0] && pass[i] < 1){
                    if(max == -1 || num[max][1] < num[i][1]){
                        max = i;
                    }
                }
            }
            if(max == -1)break;
            if(star >= num[max][1]){
                star += 2-pass[max];
                pass[max] = 2;
            }else {
                star += 1-pass[max];
                pass[max] = 1;
            }
            ++step;
        }
        for(i=0;pass[i]==2;++i);
        if(i<n){
            printf("Case #%d: Too Bad\n",++Case);
        }else {
            printf("Case #%d: %d\n",++Case,step);
        }

    }
    return 0;
}
