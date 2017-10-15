#include<stdio.h>
#include<string.h>

void solve(int casenum);

int main(void){
  int T,i;
  scanf("%d%*c",&T);
  for(i=1;i<=T;i++) solve(i);
  return 0;
}

void solve(int casenum){
  char S[1000];
  int i,j,k,l,num=0;
  scanf("%s%*c%d%*c",S,&k);
  l=strlen(S);
  for(i=0;i<=l-k;i++){
    if(S[i]=='+') continue;
    num++;
    for(j=0;j<k;j++)
      S[i+j]=(S[i+j]=='-')?'+':'-';
  }
  for(i=0;i<l;i++){
    if(S[i]=='-'){
      printf("Case #%d: IMPOSSIBLE\n",casenum);
      return;
    }
  }
  printf("Case #%d: %d\n",casenum,num);
}
  
