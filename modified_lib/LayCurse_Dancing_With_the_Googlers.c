#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int numdig(int n){
  int res = 0;
  while(n) n/=10, res++;
  return res;
}

int chk[2000010];

int main(){
  int i,j,k,l,m,n;
  int size, count = 0;
  int pw[20];
  int a, b, res;

  pw[0] = 1;
  REP(i,1,20) pw[i] = pw[i-1] * 10;

  scanf("%d",&size);
  while(size--){
    printf("Case #%d: ",++count);
    fprintf(stderr,"rest %d\n",size);

    scanf("%d%d",&a,&b);
    REP(i,a,b+1) chk[i] = -1;

    res = 0;
    REP(i,a,b){
      k = i;
      n = numdig(i);

      rep(m,n){
        k = k/10 + (k%10)*pw[n-1];
        if(i < k && k <= b){
          if(chk[k] != i) res++;
          chk[k] = i;
        }
      }
    }
    printf("%d\n",res);
  }

  return 0;
}
