#include <stdio.h>
#include <stdlib.h>
int C[1000004];
int setC[1000004];
void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int cmp(void const*a,void const*b){
    int c = *(int *)a;
    int d = *(int *)b;
    if(c>d)return -1;
    if(c<d)return 1;
    return 0;
}
int n;
int twoGroup(int a,int b,int now);
int max(int a,int b){
    if(a>b)return a;
    return b;
}
int main(){
    int t,Case;
    int i,j;
    int OK;
    int a,b;
    scanf("%d",&Case);
    for(t=1;t<=Case;++t){
        scanf("%d",&n);
        for(i=0;i<n;++i){
            scanf("%d",&C[i]);
        }
        new_qsort(C,n,sizeof(int),cmp);
        printf("Case #%d: ",t);
        if(twoGroup(0,0,0)){
            for(i=0,a=0,b=0;i<n;++i){
                if(setC[i]){
                    a+=C[i];
                }else {
                    b+=C[i];
                }
            }
            printf("%d\n",max(a,b));
        }else {
            printf("NO\n");
        }
    }
    return 0;
}
int twoGroup(int a,int b,int now){
    if(now == n){
        if(a==0 ||b==0)return 0;
        if(a==b)return 1;
        else return 0;
    }
    a = a^C[now];
    setC[now] = 0;
    if(twoGroup(a,b,now+1)){
        return 1;
    }
    a = a^C[now];
    setC[now] = 1;
    b = b^C[now];
    if(twoGroup(a,b,now+1)){
        return 1;
    }
    b = b^C[now];
    return 0;
}

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}