#include <stdio.h>
#include <stdlib.h>

long long int qwerty(long long int k){
long long int i,p=1;
for(i=0;i<k;i++){
        p=p*10;
}
return p;
}

long long haze(long long int N, long long int d){
long long int q=N/qwerty(d);
return q%10;
}

int main()
{
    FILE *fin,*fout;
    fin=fopen("A-small-attempt2.in","r");
    fout=fopen("output.txt","w");
    long long int T,N,A[10],found,k,i,d,s;
    fscanf(fin,"%I64d",&T);
    for(k=1 ; k<=T ; k++){
        fscanf(fin,"%I64d",&N);
        i=1,found=0;
        if(N==0){fprintf(fout,"Case #%I64d: INSOMNIA \n",k); continue;}
        for(s=0; s<10 ; s++){ A[s]=0;}
        while(!(found)){
            d=0;
            while(qwerty(d)<=(N*i)){
                A[haze(N*i,d)]=1;
                d++;
            }
            found=1;
            for(s=0; s<10; s++){
                found=found*A[s];
            }

            i++;

        }
            i--;
            fprintf(fout,"Case #%I64d: %I64d \n",k,i*N);




    }
    fclose(fin);
    fclose(fout);
    return 0;
}
