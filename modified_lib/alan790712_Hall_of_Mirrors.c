#include <stdio.h>
#include <string.h>
#include <stdlib.h>


double pro[100000];
int right[100000];
int a,b;
double exp;
double minExp;

int main(){
    int Case = 0;
    int t;
    int i,j;
    double pp;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        for(i=0;i<a;++i){
            scanf("%lf",&pro[i]);
        }
        for(i=0,pp=1.0;i<a;++i){
            pp *= pro[i];
        }
        minExp = pp * (b-a+1) + (1.0-pp)*(b-a+b+2);
        exp = b+2;
        if(exp < minExp)minExp = exp;
        for(i=1;i<=a;++i){
            pp = 1.0;
            for(j=0;j<a-i;++j){
                pp *= pro[j];
            }
            exp = pp * (i+b-a+i+1) +(1-pp)*(i+b-a+i+1 + b+1);
            if(exp < minExp)minExp = exp;
        }
        printf("Case #%d: %lf\n",++Case,minExp);

    }
    return 0;
}
