#include<stdio.h>
#include<stdlib.h>
int t,T,X,Y;
int new_puts(const char *str);

int main(){
scanf("%d",&T);


for(t=1;t<=T;t++){
scanf("%d",&X);
scanf("%d",&Y);

printf("Case #%d: ",t);

for(;X>0;X--) printf("WE");
for(;X<0;X++) printf("EW");

for(;Y>0;Y--) printf("SN");
for(;Y<0;Y++) printf("NS");
new_puts("");
}

return 0;
}

int new_puts(const char *str) {
  return puts(str);
}