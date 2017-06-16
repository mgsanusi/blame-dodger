#include<stdio.h>
#include<stdlib.h>
int t,T,n,N;
int c;
int best, best_prev;
char foo[128][128];
char l[128]; /*Letters*/
int num_l;
int med;
int ans;
int cur_l;
int felga;
int tmp;
int tmp_prev;
int norm[128][128];

int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&N);
for(n=1;n<=N;n++){
scanf("%s",&foo[n][0]);
}

num_l=0;
l[0]=foo[1][0];
norm[1][0]=1;
for(c=1;foo[1][c]!='\0';c++){
if (foo[1][c]!=foo[1][c-1]) {
 num_l++;
 l[num_l]=foo[1][c];
 norm[1][num_l]=1;
} else {
norm[1][num_l]++;
}
}
num_l++;

felga=0;
for(n=2;n<=N;n++){
 if (l[0]!=foo[n][0]) {felga=1; break;}
 norm[n][0]=1;
 cur_l=0;
 for(c=1;foo[n][c]!='\0';c++){
 if (foo[n][c]==l[cur_l]) {norm[n][cur_l]++;}
 else {
  cur_l++;
  if (cur_l==num_l) {felga=1; break;}
  if (foo[n][c]==l[cur_l]) {norm[n][cur_l]=1;}
  else {felga=1; break;}
 }
 }
 if (cur_l+1!=num_l) {felga=1;}
 if (felga==1) break;
}

if (felga==0) {
ans=0;
for(c=0;c<num_l;c++) {
best_prev=10000000;
for(med=1;;med++){
 best=0;
 for(n=1;n<=N;n++){
  best+=abs(norm[n][c]-med);
 }
 if (best>best_prev) break;
 best_prev=best;
}
ans+=best_prev;

}
}

printf("Case #%d: ",t);
if (felga==1) printf("Fegla Won\n");
else printf("%d\n",ans);
}
return 0;
}
