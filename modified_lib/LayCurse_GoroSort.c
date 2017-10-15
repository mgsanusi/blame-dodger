#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int size,count=0;
  int res;

  scanf("%d",&size);
  while(size--){
    scanf("%d",&n);
    res=0;
    rep(i,n){
      scanf("%d",&k);
      if(i+1!=k) res++;
    }
    printf("Case #%d: %d\n",++count,res);
  }


  return 0;
}
