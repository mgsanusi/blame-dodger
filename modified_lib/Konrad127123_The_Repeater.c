#include<stdio.h>
#include<stdlib.h>
int t,T,n,N;
int a,b;
int A,B,K,ans;

int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&A);
scanf("%d",&B);
scanf("%d",&K);

ans=0;
for(a=0;a<A;a++)
for(b=0;b<B;b++)
if ((a&b)<K) ans++;


printf("Case #%d: ",t);
printf("%d\n",ans);
}
return 0;
}
