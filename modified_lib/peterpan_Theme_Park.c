#include <stdio.h>

#define MAXN 1000
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_getchar();


int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int i,tcase,T,R,k,N,g[MAXN],r,cap,starti;
    unsigned long long res;
    
    /*i=0;
    while(1)
    {
	   printf("2^%d = %d",i,((int) 1)<<i);
	   i++;
	   new_getchar();
	}*/
    if (argc>1)
       fin=new_fopen(argv[1],"r");
    else
       fin=new_fopen("themePark.in.txt","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=new_fopen(argv[2],"w");
    else
       fout=new_fopen("themePark.out.txt","w");
    if (!fout){
       new_fclose(fin);
       return 1;
 	   }
    fscanf(fin,"%d",&T);
    for (tcase=1;tcase<=T;tcase++)
    {
       fscanf(fin,"%d",&R);
       fscanf(fin,"%d",&k);
       fscanf(fin,"%d",&N);
       for(i=0;i<N;i++)
          fscanf(fin,"%d",g+i);
	   r=0;
	   res=0;
       i = 0;
	   while(r<R)
	   {
 	      cap = k;
 	      starti = i;
 	      while(cap >= g[i])
 	      {
 	         cap -= g[i++];
 	         if(i==N)
 	            i = 0;
             if(i==starti)
                break;
	      }
	      if(cap == k)
	         break;
	      res += k - cap;
	      r++;
	      if(i == 0)
	      {
   	   	     res *= R/r;
   	   	     r *= R/r;
	   	  }
   	   }
       fprintf(fout,"Case #%d: %llu\n",tcase,res);
    }
    new_fclose(fin);
    new_fclose(fout);
    return 0;
}

FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_getchar() {
  return getchar();
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}