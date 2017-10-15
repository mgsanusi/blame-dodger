#include<stdio.h>

int fillable(int x,int r,int c){
  if((r*c)%x!=0)return 0;
  if(x>=7)return 0;
  int a;
  if(c>r){
    a=c;
    c=r;
    r=a;
  }
  for(a=1;a<=x;a++){
    int b=x-a+1;
    if(a<=r&&b<=c)continue;
    if(b<=r&&a<=c)continue;
    return 0;
  }
  for(a=c+1;a<=x;a++){
    if(x-a<c-1)break;
    int b,f;
    for(b=0;b<a*c-x;b++){
      for(f=0;f+a<=r;f++){
        if((f*c+b)%x!=0)return 0;
        if((r*c-(f*c+b)-x)%x!=0)return 0;
      }
    }
  }
  return 1;
}

int main(int argc,char*argv[]){
  int x,r,c,t,nt;
  scanf("%d",&nt);
  for(t=1;t<=nt;t++){
    scanf("%d%d%d",&x,&r,&c);
    printf("Case #%d: %s\n",t,fillable(x,r,c)?"GABRIEL":"RICHARD");
  }
  return 0;
}
