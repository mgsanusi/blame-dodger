#include <stdio.h>

void solve() {
	int n,seen,i,j;
	char s[15];
	scanf("%d",&n);
	if(!n) { puts("INSOMNIA"); return; }
	seen=0;
	for(i=1;;i++) {
		sprintf(s,"%d",i*n);
		for(j=0;s[j];j++) seen|=1<<(s[j]-48);
		if(seen==1023) {
			printf("%d\n",i*n);
			return;
		}
	}
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
