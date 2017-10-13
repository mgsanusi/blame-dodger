#include <stdio.h>

void solve() {
	int K,C,S,i;
	scanf("%d %d %d",&K,&C,&S);
	for(i=1;i<=K;i++) printf(" %d",i);
	putchar('\n');
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d:",caseno++),solve();
	return 0;
}
