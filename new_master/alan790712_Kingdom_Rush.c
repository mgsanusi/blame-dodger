#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int num[123456];
int sum,avg,sss;
double ans[123456];
double a,b;
int N;
int main(){
    int Case = 0;
    int t;
    int i;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0,sum=0;i<n;++i){
            scanf("%d",&num[i]);
            sum +=num[i];
        }
        sss = sum;
        avg = sum*2/n;
        for(i=N=0;i<n;++i){
            if(num[i] > avg){
                ans[i] = 0;
                sum -= num[i];
            }else {
                ++N;
                ans[i] = -1;
            }
        }
        printf("Case #%d:",++Case);
        for(i=0;i<n;++i){
            if(ans[i]==0){
                printf(" %lf",ans[i]);
            }else {
                //printf("%lf %d %lf\n",(sss+sum)/N,num[i],sss);
                printf(" %lf",(double)(100*(((sss+(double)sum)/(double)N)-num[i]))/sss);
            }


        }
        puts("");
    }
    return 0;
}
