#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin,*fout;
    fout = fopen("output.txt","w");
    fin = fopen("A-small-attempt0.in","r");
    int q,T,first,last,i;
    char c,A[2001];
    fscanf(fin,"%d",&T);
    c=fgetc(fin);
    for(q=1; q<=T; q++){
    first=1000;
    last=1000;
    c=fgetc(fin);
    A[1000]=c;
        while((c=fgetc(fin))!='\n' && c!=EOF){
                    if(c>=A[first]){A[first-1]=c; first--;}
                    else{A[last+1]=c; last++;}
                    }
        fprintf(fout,"Case #%d: ",q);
        for(i=first; i<=last; i++){
            fprintf(fout,"%c",A[i]);
        }
         fprintf(fout,"\n");

    }


    fclose(fin);
    fclose(fout);
    return 0;
}
