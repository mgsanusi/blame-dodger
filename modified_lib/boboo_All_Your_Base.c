#include <stdio.h>
#include <string.h>
FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream);

int main() {
    FILE * fin = new_fopen("base.in","r");
    FILE * fout= new_fopen("base.out","w");
    int l,i,j,k,tt,test,n;
    char a[80];
    int c[300],b[300];
    long ans,t;
    fscanf(fin,"%d\n",&test);
    for (tt=1; tt<=test; tt++) {
        new_fgets(a,70,fin);
        for (i=0; i<300; i++)
          b[i] = -1;
        n = 0; 
        ans = 0; t=1;
        l = strlen(a)-1;
        b[a[0]]=1;
        for (i=1; i<l; i++) 
          if (b[a[i]] == -1) {
                 b[a[i]] = n;
                 n++;
                 if (n == 1) n++;
              }
        if (n==0) n=2;      
        for (i=l-1; i>=0; i--) { 
          ans += t * b[a[i]];
          if (i>0) t *= n;        
        }  
        fprintf(fout,"Case #%d: %d\n",tt,ans);
    }
    return 0;
} 

FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}