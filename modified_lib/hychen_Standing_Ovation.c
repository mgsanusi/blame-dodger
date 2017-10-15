#include<stdio.h>
char s[1024];
int main(int argc,char*argv[]){
  int a,d,e,t,t2;
  scanf("%d",&t);
  for(t2=1;t2<=t;t2++){
    scanf("%d%s",&e,s);
    d=0;
    int ans=0;
    for(a=0;a<=e;a++){
      if(s[a]!='0'&&d<a){
        ans+=a-d;
        d=a;
      }
      d+=s[a]-'0';
    }
    printf("Case #%d: %d\n",t2,ans);
  }
  return 0;
}
