#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int i,T,K,N;
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("snapperChain.in.txt","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("snapperChain.out.txt","w");
    if (!fout){
       fclose(fin);
       return 1;
 	   }
    fscanf(fin,"%d",&T);
    for (i=1;i<=T;i++)
    {
       fscanf(fin,"%d",&N);
       fscanf(fin,"%d",&K);
       fprintf(fout,"Case #%d: %s\n",i,(K%(1<<N)==(1<<N)-1)?"ON":"OFF");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
