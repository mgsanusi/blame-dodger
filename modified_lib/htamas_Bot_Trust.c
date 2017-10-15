#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int T,N,tc,i,j,b,cur,s,ts;
  char cc;
  int pos[2];
  int adv[2];
  scanf("%d",&T);
  for(tc=1;tc<=T;++tc) {
    scanf("%d",&N);
    pos[0]=1; pos[1]=1;
    adv[0]=0; adv[1]=0;
    ts=0;
    for(i=0;i<N;++i) {
      scanf(" %c %d",&cc,&b);
      cur=(cc=='B');
      s=b-pos[cur];
      if(s<0) s=-s;
      s-=adv[cur];
      if(s<0) s=0;
      s+=1;
      ts+=s;
      pos[cur]=b;
      adv[cur]=0;
      adv[!cur]+=s;
    }
    printf("Case #%d: %d\n", tc, ts);
  }
  return 0;
}

