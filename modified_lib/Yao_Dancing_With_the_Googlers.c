#include<stdio.h>

int f[10];
int a[10000001];
int b[10000001];

void init() {
	int i,j,k,t;
	for(f[0]=i=1;i<10;i++) f[i]=f[i-1]*10;
	for(i=0;i<7;i++) for(j=f[i];j<=f[i+1];j++) {
		a[j]=j;
		for(k=0,t=j;k<i;k++) {
			t=t%10*f[i]+t/10;
			if (t<a[j]) a[j]=t;
		}
	}
}

int main() {
	int N,A,B,i,cs=0;
	long long ret;
	init();
	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&A,&B);
		ret=0;
		for(i=A;i<=B;i++) {
			ret+=b[a[i]];
			b[a[i]]++;
		}
		printf("Case #%d: %lld\n",++cs,ret);
		for(i=A;i<=B;i++) b[a[i]]=0;
	}
	return 0;
}
