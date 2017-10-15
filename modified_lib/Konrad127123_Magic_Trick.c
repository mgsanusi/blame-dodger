#include<stdio.h>
int t,T;
int z[32];
int y[5][5];
int a,b,c;
int ans,num_ans;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&ans);
 for(a=1;a<=4;a++)
  for(b=1;b<=4;b++){
   scanf("%d",&y[a][b]);
  }

 for(c=0;c<32;c++) z[c]=0;
 for(b=1;b<=4;b++) z[y[ans][b]]++;

scanf("%d",&ans);
 for(a=1;a<=4;a++)
  for(b=1;b<=4;b++){
   scanf("%d",&y[a][b]);
  }
 for(b=1;b<=4;b++) z[y[ans][b]]++;

 ans=0;
 num_ans=0;
 for(c=1;c<=16;c++) if (z[c]>1) {ans=c; num_ans++;}

 printf("Case #%d: ",t);
 if (num_ans==0) printf("Volunteer cheated!\n");
 if (num_ans==1) printf("%d\n",ans);
 if (num_ans>1) printf("Bad magician!\n");
}
return 0;
}
