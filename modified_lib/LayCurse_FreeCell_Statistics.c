#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
int new_puts(const char *str);


int main(){
  int i,j,k,l,m; ll n;
  int x,y;
  int size,count=0;
  int is_can[101][101] = {};

  REP(i,1,101) rep(j,i+1){
    k = j*100;
    if(k%i) continue;
    k/=i;
    REP(m,i,101) is_can[m][k] = 1;
  }

  scanf("%d",&size);
  while(size--){
    scanf("%lld%d%d",&n,&x,&y);
    printf("Case #%d: ",++count);

    if(x<100 && y==100){ new_puts("Broken"); continue; }
    if(x>  0 && y==  0){ new_puts("Broken"); continue; }

    if(n>100) n = 100;
    if(is_can[n][x]) new_puts("Possible"); else new_puts("Broken");
  }

  return 0;
}

int new_puts(const char *str) {
  return puts(str);
}