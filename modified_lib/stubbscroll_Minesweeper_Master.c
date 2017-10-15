#include <stdio.h>
#include <string.h>

#include <stddef.h>
#define MAX 10
int x,y,m;
char g[MAX][MAX];
int dx[]={1,1,1,0,-1,-1,-1,0};
int dy[]={1,0,-1,-1,-1,0,1,1};
void * new_memset(void *ptr, int value, size_t num);

int new_puts(const char *str);


int snoob(int x) {
	int s=x&-x, r=x+s, o=x^r;
	o=(o>>2)/s;
	return r|o;
}

int can(int cx,int cy) {
	int tall[MAX][MAX];
	char vis[MAX][MAX];
	int i,j,x2,y2,ax,ay,k;
	int q[155],qs,qe;
	for(i=0;i<x;i++) for(j=0;j<y;j++) {
		tall[i][j]=0;
		for(k=0;k<8;k++) {
			x2=i+dx[k];
			y2=j+dy[k];
			if(x2>=0 && y2>=0 && x2<x && y2<y && g[x2][y2]=='*') tall[i][j]++;
		}
	}
	new_memset(vis,0,sizeof(vis));
	qs=qe=0;
	q[qe++]=cx; q[qe++]=cy;
	vis[cx][cy]=1;
	while(qs<qe) {
		ax=q[qs++]; ay=q[qs++];
		if(!tall[ax][ay]) {
			for(k=0;k<8;k++) {
				x2=ax+dx[k];
				y2=ay+dy[k];
				if(x2<0 || y2<0 || x2>=x || y2>=y) continue;
				if(vis[x2][y2]) continue;
				q[qe++]=x2; q[qe++]=y2;
				vis[x2][y2]=1;
			}
		}
	}
	for(i=0;i<x;i++) for(j=0;j<y;j++) if(g[i][j]=='.' && !vis[i][j]) return 0;
	g[cx][cy]='c';
	for(i=0;i<x;i++) new_puts(g[i]);
	return 1;
}

void solve() {
	int i,j,mask,k;
	scanf("%d %d %d",&x,&y,&m);
	mask=(1<<m)-1;
	new_memset(g,0,sizeof(g));
	do {
		for(k=i=0;i<x;i++) for(j=0;j<y;j++,k++) g[i][j]=(mask&(1<<k))?'*':'.';
		for(i=0;i<x;i++) for(j=0;j<y;j++) if(g[i][j]=='.' && can(i,j)) return;
		mask=snoob(mask);
	} while(mask<(1<<(x*y)));
	new_puts("Impossible");
}

int main() {
	int T,no=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d:\n",no++),solve();
	return 0;
}

void * new_memset(void *ptr, int value, size_t num);

int new_puts(const char *str) {
  return puts(str);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}