#include<stdio.h>
int t,T;
long double l,rate,C,F,X,best_time,cur_time;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
 scanf("%llf",&C);/*cost*/
 scanf("%llf",&F);/*farm rate*/
 scanf("%llf",&X);/*target*/
 rate=2.0;
 cur_time=0.0;
 while (X*rate<(X-C)*(F+rate)) {
/*  printf("DEBUG: rate %llf %llf %llf\n",rate,X*rate,(X-C)*(F+rate));*/
  cur_time+=C/rate;
  rate+=F;
  }
 cur_time+=X/rate;

 printf("Case #%d: ",t);
 printf("%.7llf\n",cur_time);
}
return 0;
}
