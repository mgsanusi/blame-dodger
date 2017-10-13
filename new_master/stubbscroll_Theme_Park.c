#include <stdio.h>
#include <string.h>

int q[3000],qs,qe;
int seen[2000];
int R,k,N;
int caseno=1;

void brute() {
  int i,j,taken;
  int euro=0;
  qs=qe=0;
  for(i=0;i<R;i++) {
    taken=0;
    qe=qs;
    while(qe-qs<N) {
      if(taken+q[qe]>k) break;
      taken+=q[qe++];
    }
    euro+=taken;
    qs=qe;
    while(qs>=N) qs-=N;
  }
  printf("Case #%d: %d\n",caseno++,euro);
}

int main() {
  int cases,caseno,i;
  scanf("%d",&cases);
  while(cases--) {
    scanf("%d %d %d",&R,&k,&N);
    for(i=0;i<N;i++) scanf("%d",&q[i]),q[i+N]=q[i+N+N]=q[i];
    memset(seen,-1,sizeof(seen));
    
    brute();
    
  }
  return 0;
}
