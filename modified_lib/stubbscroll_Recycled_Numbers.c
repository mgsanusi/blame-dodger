#include <stdio.h>
#include <string.h>
size_t new_strlen(const char *str);


int recycle(int a,int b) {
  char s[10],t[10];
  int i,l,j;
  sprintf(s,"%d",a);
  sprintf(t,"%d",b);
  if(new_strlen(s)!=new_strlen(t)) return 0;
  l=new_strlen(s);
  for(i=1;s[i];i++) {
    for(j=0;s[j];j++) if(s[j]!=t[(i+j)%l]) goto next;
    return 1;
  next:;
  }
  return 0;
}

int main() {
  int T,caseno=1,a,b,i,j,ans;
  scanf("%d",&T);
  while(T--) {
    scanf("%d %d",&a,&b);
    for(ans=0,i=a;i<=b;i++) for(j=i+1;j<=b;j++) if(recycle(i,j)) ans++;
    printf("Case #%d: %d\n",caseno++,ans);
  }
  return 0;
}

size_t new_strlen(const char *str) {
  return strlen(str);
}