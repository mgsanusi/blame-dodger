#include <stdio.h>

int a[4][4],b[4][4];
int r1,r2;

void solve() {
	int i,j,num=-1,k;
	scanf("%d",&r1);
	for(i=0;i<4;i++) for(j=0;j<4;j++) scanf("%d",&a[i][j]);
	scanf("%d",&r2);
	for(i=0;i<4;i++) for(j=0;j<4;j++) scanf("%d",&b[i][j]);
	for(k=1;k<17;k++) {
		for(i=0;i<4;i++) if(a[r1-1][i]==k) goto next;
		continue;
	next:
		for(i=0;i<4;i++) if(b[r2-1][i]==k) goto next2;
		continue;
	next2:
		if(num>-1) {
			puts("Bad magician!");
			return;
		}
		num=k;
	}
	if(num<0) puts("Volunteer cheated!");
	else printf("%d\n",num);
}

int main() {
	int T,no=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",no++),solve();
	return 0;
}
