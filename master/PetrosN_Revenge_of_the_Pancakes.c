#include <stdio.h>
#include <stdlib.h>
int func(int first,int last, int k){
if(first==-1 && last==-1) return (2*k+1);
else if(first==-1 && last==1) return (2*k-1);
else if(first==1 && last==1) return (2*k-2);
else if(first==1 && last==-1) return (2*k);
else return 0;
}
int main()
{
    FILE *fin,*fout;
    fin=fopen("B-small-attempt0.in","r");
    fout=fopen("output.txt","w");
    int T,w,first,last,plus,result;
    char c,cprev;
    fscanf(fin,"%d",&T);
    fgetc(fin);


    for(w=1 ; w<=T ; w++){
    plus=0;
    cprev=fgetc(fin);
    if(cprev=='+'){first=1; plus++;}
    else first=-1;

    while((c=fgetc(fin))!='\n' && c!=EOF){
        if(c==cprev) continue;
        else if(c=='+') plus++;

        cprev=c;

    }
    if(cprev=='-') last=-1;
    else last=1;
    result=func(first,last,plus);
    fprintf(fout,"Case #%d: %d \n",w,result);


    }
    fclose(fin);
    fclose(fout);
    return 0;
}
