#include <stdio.h>
#define MAXN 1000
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);


int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int tcase,T,N,counter,i,j,A[MAXN],B[MAXN];
    
    if (argc>1)
       fin=new_fopen(argv[1],"r");
    else
       fin=new_fopen("rope.in","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=new_fopen(argv[2],"w");
    else
       fout=new_fopen("rope.out","w");
    if (!fout){
       new_fclose(fin);
       return 1;
 	   }
    fscanf(fin,"%d",&T);
    for (tcase=1;tcase<=T;tcase++)
    {
       fscanf(fin,"%d",&N);
	   for(i=0;i<N;i++)
	   {
		   fscanf(fin,"%d",A+i);
		   fscanf(fin,"%d",B+i);
	   }
	   counter = 0;
	   for(i=0;i<N;i++)
	   {
		   for(j=i+1;j<N;j++)
		   {
			   if((A[i]>A[j] && B[i]<B[j]) || (A[i]<A[j] && B[i]>B[j]))
				   counter++;
		   }
	   }
       fprintf(fout,"Case #%d: %d\r\n",tcase,counter);
    }
    new_fclose(fin);
    new_fclose(fout);
    return 0;
}

FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}