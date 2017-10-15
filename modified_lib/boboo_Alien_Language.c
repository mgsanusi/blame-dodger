#include <stdio.h>
FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream);

int main(){
    FILE *fin = new_fopen("a1.in","r");
    FILE *fout= new_fopen("a1.out","w");
    int l,d,n;
    fscanf(fin,"%d%d%d\n",&l,&d,&n);
    char dic[5001][17];
    int b[17][27];
    int i,j,k,ans,flag;
    char ch;
    for (i=1; i<=d; i++) 
      new_fgets(dic[i],16,fin);
      
    for (k=1; k<=n; k++) {
      memset(b,0,sizeof(b));
      for (j=1; j<=l; j++) {
          fscanf(fin,"%c",&ch);
          if (ch == '(') {
                 fscanf(fin,"%c",&ch);
                 while (ch != ')') {
                    b[j][ch-'a'] = 1;
                    fscanf(fin,"%c",&ch);   
                 }
              } 
           else b[j][ch-'a'] = 1;                 
      } 
      fscanf(fin,"\n");
      ans = 0;
      for (i = 1; i<=d; i++) {
          for (j = 1; (j<=l)&&(b[j][dic[i][j-1]-'a'] == 1); j++);
          if (j>l) ++ans;            
      }     
      fprintf(fout,"Case #%d: %d\n",k,ans);
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