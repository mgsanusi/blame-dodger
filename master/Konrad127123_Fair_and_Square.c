#include<stdio.h>
#include<math.h>
#include<string.h>
int blah[1001];
int t,a,A,B,b,T,num;

int is_pal(int A){
char a[50];
int s;
int c;
sprintf(a,"%d",A);
s = strlen(a);
for(c=0;c<s;c++){
s--;
if (a[c]!=a[s]) return 0;
}
return 1;
}

int main(){
for(a=1;a<32;a++){
if (is_pal(a)) 
if (is_pal(a*a)) blah[a*a]=1;
}

scanf("%d",&T);
for(t=1;t<=T;t++){
scanf("%d",&A);
scanf("%d",&B);
num=0;

for(a=A;a<=B;a++) {
if (blah[a]) num++;
}

printf("Case #%d: %d\n",t,num);
}


return 0;
}
