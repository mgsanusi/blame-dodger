#include<stdio.h>
#include<string.h>

int uglies[300][100]; //0 none 1 + 2 -
int num[100];
int N, len;

int getnum(int s, int e) {
  int i, rem=0;
  for (i=s;i<=e;i++) {
    rem=rem*10+num[i];
    rem%=210;
  }
	return rem;
}

void process() {
  int i,j,k,num;
  int added,subtracted;
  int source;
  for (i=1;i<len;i++) {
    for (j=0;j<210;j++)
      uglies[j][i]=0;
    
    for (j=0;j<=i;j++) {
      num=getnum(j,i);
      if (j==0) {
	uglies[num][i]++;
      }
      else {
	for (k=0;k<210;k++) {
	  added = (k+num)%210;
	  subtracted = (k-num+210)%210;
	  uglies[added][i]+=uglies[k][j-1];
	  uglies[subtracted][i]+=uglies[k][j-1];
	}
      }
    }
  }
  return;
}

int getCount() {
  int i;
  int c=0;
  for (i=0;i<210;i++) {
    if (i%2==0 || i%3 == 0 || i%5 == 0 || i%7 == 0)
      c+= uglies[i][len-1];
  }
  return c;
}

void main() {
  FILE *in=fopen("test.in","r");
  FILE *out=fopen("test.out","w");
  int i,j,count;
  char string[100];
  
  fscanf(in,"%d ",&N);
  
  for (i=0;i<N;i++) {
    fscanf(in,"%s",string);
    len=strlen(string);
    
    for (j=0;j<len;j++) {
      num[j]=string[j]-'0';
    }
    for (j=0;j<300;j++)
      uglies[j][0]=0;
    uglies[num[0]][0]=1;
    
    process();
    count=getCount();
    
    fprintf(out,"Case #%d: %d\n",i+1,count);
  }
}
