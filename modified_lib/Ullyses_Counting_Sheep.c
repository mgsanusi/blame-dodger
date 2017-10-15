#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);




int main(){
int lol,krat,max,MU,T,i,j,n,fnumber[10],number[20000],N,check[12];
bool found;
long long int sum;
found=false;
    FILE *fp;
    FILE *fo;
    fo = new_fopen("outputa.txt","w");
    fp = new_fopen("inputa.in","r");
    fscanf(fp,"%d",&T);

for(i=1; i<=T; i++){
    for(j=1; j<=10003; j++){number[j]=0;}
    fprintf(fo,"Case #");
    fprintf(fo,"%d",i);
    fprintf(fo,":");
    fprintf(fo," ");
    fscanf(fp,"%d",&N);
    if(N==0){fprintf(fo,"INSOMNIA");}
    else {
    //array set up
    for(j=1; j<=7; j++){
    fnumber[j]=N%10;
    N=N/10;
    if (N==0){max=j; break;}
    }

    for(j=1; j<=10; j++){
        check[j]=0;
    }
    //check
    for(j=1; j<=max; j++){
        n=fnumber[j];
        check[n+1]=check[n+1]+1;
        }
    //found
     found=false;
    for(j=1; j<=10; j++){if(check[j]==0){found=true;}}
       //next
    MU=1;
    krat=0;
    while(found){
            krat=0;
            for(j=1; j<=max; j++){
            number[j]=fnumber[j]+number[j];
            }
            for(j=1; j<=(max+MU); j++){
            number[j]=number[j]+krat;
            krat=number[j]/10;
            number[j]=number[j]%10;
            }

            if (number[max+MU]!=0){MU=MU+1;}
           //check
            for(j=1; j<=max+MU-1; j++){
                  n=number[j];
                  check[n+1]=check[n+1]+1;
             }
            //found
            found=false;
            for(j=1; j<=10; j++){if(check[j]==0){found=true;}}
    }
    sum=0;
    lol=1;
    for(j=1; j<=max+MU; j++){
      sum=sum+number[j]*lol;
      lol=lol*10;
    }
fprintf(fo,"%lld",sum);

    }
fprintf(fo,"\n");
}
return 1;}

FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}