#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int new_puts(const char *str);


int main(){
  int i,j,k,l,m,n,size,count=0;
  scanf("%d",&size);
  while(size--){
    printf("Case #%d: ",++count);
    scanf("%d%d",&n,&k);
    n=(1<<n)-1;
    if((n&k)==n) new_puts("ON"); else new_puts("OFF");
  }
  return 0;
}

int new_puts(const char *str) {
  return puts(str);
}