#include <stdio.h>
#include <string.h>

int n;
char s[111][111];

int can(int ix,int iy) {
	int i=0,j=0,op=0,a,b,x,y;
	while(s[ix][i] && s[iy][j]) {
		if(s[ix][i]!=s[iy][j]) return -1;
		a=b=0;
		x=i; y=j;
		while(s[ix][i]==s[ix][x]) i++,a++;
		while(s[iy][j]==s[iy][y]) j++,b++;
		op+=a>b?a-b:b-a;
	}
	return (s[ix][i] || s[iy][j])?-1:op;
}

void solve() {
	int i,j,best=1e9,cur;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%s",s[i]);
	for(i=1;i<n;i++) if(can(0,i)<0) {
		puts("Fegla Won");
		return;
	}
	for(i=0;i<n;i++) {
		for(cur=j=0;j<n;j++) cur+=can(i,j);
		if(best>cur) best=cur;
	}
	printf("%d\n",best);
}

int main() {
	int t,no=1;
	scanf("%d",&t);
	while(t--) printf("Case #%d: ",no++),solve();
	return 0;
}
