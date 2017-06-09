#include<stdio.h>
int pla0[1001];
int pla[1001];
int main(int argc,char*argv[]){
  int t,t2,p,a,b,c;
  scanf("%d",&t2);
  for(t=1;t<=t2;t++){
    int ans=1000000000;
    scanf("%d",&p);
    if(p==0){
      ans=0;
      goto answer;
    }
    for(a=0;a<1001;a++)pla0[a]=0;
    for(a=0;a<p;a++){
      scanf("%d",&b);
      pla0[b]++;
    }

    for(c=1;c<=1000;c++){
      b=0;
      for(a=c+1;a<=1000;a++){
        b+=pla0[a]*(a/c-(a%c==0));
      }
      if(ans>b+c)ans=b+c;
    }
    answer:
    printf("Case #%d: %d\n",t,ans);
  }
  return 0;
}
