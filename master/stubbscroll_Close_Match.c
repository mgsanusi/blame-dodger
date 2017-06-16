#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[100],b[100];
int besta,bestb,bestd;
char ba[100],bb[100];

void check() {
	int ia=strtol(a,0,10);
	int ib=strtol(b,0,10);
	int dd=ia-ib>0?ia-ib:ib-ia;
	if(bestd>dd || (bestd==dd && (besta>ia || (besta==ia && bestb>ib)))) {
		bestd=dd,besta=ia,bestb=ib;
		strcpy(ba,a);
		strcpy(bb,b);
	}
}

void btrb(int at) {
	int i;
	if(!b[at]) return check();
	if(b[at]!='?') return btrb(at+1);
	else for(i=0;i<10;i++) {
		b[at]=i+'0';
		btrb(at+1);
		b[at]='?';
	}
}

void btra(int at) {
	int i;
	if(!a[at]) return btrb(0);
	if(a[at]!='?') return btra(at+1);
	else for(i=0;i<10;i++) {
		a[at]=i+'0';
		btra(at+1);
		a[at]='?';
	}
}

void solve() {
	scanf("%s %s",a,b);
	besta=bestb=bestd=123123123;
	strcpy(ba,"asfas");
	strcpy(bb,"asfas");
	btra(0);
	printf("%s %s\n",ba,bb);
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
