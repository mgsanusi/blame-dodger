#include<stdio.h>
int t,T;
int r,count,R,C,M,c;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
 printf("Case #%d: \n",t);
 scanf("%d",&R);
 scanf("%d",&C);
 scanf("%d",&M);
/* printf("Case #%d: %d %d %d %d\n",t,R,C,M,R*C-M);*/
 if (C==1) {
  printf("c\n");
  for(r=2;r<=R*C-M;r++) printf(".\n");
  for(;r<=R;r++) printf("*\n");
 } else if (R==1) {
  printf("c");
  for(c=2;c<=R*C-M;c++) printf(".");
  for(;c<=C;c++) printf("*");
  printf("\n");
 } else if (R*C-M<=1) {
  for(r=1;r<=R;r++){
   for(c=1;c<=C;c++){
    if ((r==1)&&(c==1)&&(R*C-M==1)) printf("c");
    else printf("*");
   }
   printf("\n");
  }
 } else if (R*C-M==2) {
  printf("Impossible\n");
 } else if (R==2) { 
  if ((R*C-M)%2==1) printf("Impossible\n");
  else {
   printf("c"); 
   for(c=2;c<=((R*C-M)/2);c++) printf(".");
   for(;c<=C;c++) printf("*");
   printf("\n");
   for(c=1;c<=((R*C-M)/2);c++) printf(".");
   for(;c<=C;c++) printf("*");
   printf("\n");
  }
 } else if (C==2) {
  if ((R*C-M)%2==1) printf("Impossible\n");
  else {
   printf("c.\n");
   for(r=2;r<=((R*C-M)/2);r++) printf("..\n");
   for(;r<=R;r++) printf("**\n");
  }
 } else if ((R*C-M)<=2*C+1) {
  if ((R*C-M==3)||(R*C-M==5)||(R*C-M==7)) printf("Impossible\n");
  else {
   if ((R*C-M)%2==0) {
    printf("c");
    for(c=2;c<=(R*C-M)/2;c++) printf(".");
    for(;c<=C;c++) printf("*");
    printf("\n");
    for(c=1;c<=(R*C-M)/2;c++) printf(".");
    for(;c<=C;c++) printf("*");
    printf("\n");
    for(r=3;r<=R;r++){
     for(c=1;c<=C;c++) printf("*");
     printf("\n");
    }
   } else {
    printf("c");
    for(c=2;c<=(R*C-M-3)/2;c++) printf(".");
    for(;c<=C;c++) printf("*");
    printf("\n");
    for(c=1;c<=(R*C-M-3)/2;c++) printf(".");
    for(;c<=C;c++) printf("*");
    printf("\n");
    for(c=1;c<=3;c++) printf(".");
    for(;c<=C;c++) printf("*");
    printf("\n");
    for(r=4;r<=R;r++){
     for(c=1;c<=C;c++) printf("*");
     printf("\n");
    }
   }
  }
 } else if ((C*R-M)%C==1) {
/*  printf("DEBUG\n");*/
  M+=2;
  count=1;
  printf("c");
  for(c=2;c<=C;c++) {printf("."); count++;}
  printf("\n");
  for(r=2;(r<=R)&&(count<C*R-M);r++){
   for(c=1;c<=C;c++) if (count<C*R-M) {printf("."); count++;} else {printf("*");}
   printf("\n");
  }
  printf("..");
  for(c=3;c<=C;c++) {printf("*");}
  r++;
  printf("\n");
  for(;r<=R;r++){
   for(c=1;c<=C;c++) if (count<C*R-M) {printf("."); count++;} else {printf("*");}
   printf("\n");
  }
 } else {
  count=1;
  printf("c");
  for(c=2;c<=C;c++) {printf("."); count++;}
  printf("\n");
  for(r=2;r<=R;r++){
   for(c=1;c<=C;c++) if (count<C*R-M) {printf("."); count++;} else {printf("*");}
   printf("\n");
  }
 }
}
return 0;
}
