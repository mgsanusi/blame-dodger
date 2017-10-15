#include <stdio.h>
int main(){
  int N, K, T;
  int i,b;
  scanf("%d",&T);
  for(i = 0; i<T; i++){
    scanf("%d%d",&N,&K);
    b = (1<<N)-1;
    if((K & b) == b){
      printf("Case #%d: ON\n",i+1);
    } else {
      printf("Case #%d: OFF\n",i+1);
    }
  }
}
