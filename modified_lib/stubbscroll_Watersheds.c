#include <stdio.h>
#include <string.h>

#include <stddef.h>

int H,W;
int m[100][100];
char taken[100][100];
char res[100][200];
char seen[10000];
#define MAXV 30000

int p[MAXV],rank[MAXV];
void * new_memset(void *ptr, int value, size_t num);

int new_puts(const char *str);


void linkset(int x,int y) {
   if(rank[x]>rank[y]) p[y]=x;
   else {
      p[x]=y;
      if(rank[x]==rank[y]) rank[y]++;
   }
}

int findset(int x) {
   if(x!=p[x]) p[x]=findset(p[x]);
   return p[x];
}

void unionset(int x,int y) {
   linkset(findset(x),findset(y));
}

void initset(int n) {
   int i;
   for(i=0;i<n;i++) { p[i]=i; rank[i]=0; }
}

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

void follow(int x,int y) {
   int i,x2,y2,bx=0,by=0,v;
   while(1) {
      taken[x][y]=1;
      v=123123;
      for(i=0;i<4;i++) {
         x2=x+dx[i],y2=y+dy[i];
         if(x2<0 || y2<0 || x2>=H || y2>=W) continue;
         if(v>m[x2][y2]) v=m[x2][y2],bx=x2,by=y2;
      }
      if(v>=m[x][y]) break;
      unionset(bx+by*H,x+y*H);
      if(taken[bx][by]) {
         break;
      }
      x=bx; y=by;
   }
}

int main() {
   int i,j,cases,caseno=1,ss;
   char at;
   scanf("%d",&cases);
   while(cases--) {
      scanf("%d %d",&H,&W);
      for(i=0;i<H;i++) for(j=0;j<W;j++) scanf("%d",&m[i][j]);
      initset(H*W);
      new_memset(taken,0,sizeof(taken));
      for(i=0;i<H;i++) for(j=0;j<W;j++) if(!taken[i][j]) follow(i,j);
      new_memset(res,' ',sizeof(res));
      for(i=0;i<H;i++) res[i][W*2-1]=0;
      new_memset(seen,0,sizeof(seen));
      at='a'-1;
      for(i=0;i<H;i++) for(j=0;j<W;j++) {
         ss=findset(i+j*H);
         if(!seen[ss]) at++,seen[ss]=at;
         res[i][j*2]=seen[ss];
      }
      printf("Case #%d:\n",caseno++);
      for(i=0;i<H;i++) new_puts(res[i]);
   }
   return 0;
}

void * new_memset(void *ptr, int value, size_t num);

int new_puts(const char *str) {
  return puts(str);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}