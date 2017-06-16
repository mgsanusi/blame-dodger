#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b) {
	return *(int *)a-*(int *)b;
}

int a[256],b[256];
int n;

int main() {
	int N,i,cs=0,sum,j;
	long long tt;
	double t;

	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(sum=i=0;i<n;i++) scanf("%d",&a[i]),sum+=a[i],b[i]=a[i];
		qsort(b,n,sizeof(b[0]),cmp);
		for(tt=i=j=0;i<n && tt<sum;i++) {
			tt+=(b[i]-j)*i;
			j=b[i];
		}
		if (tt>=sum) t=b[i-1]-(double)(tt-sum)/(i-1);
		else t=b[n-1]+(double)(sum-tt)/n;
		printf("Case #%d:",++cs);
		for(i=0;i<n;i++) if (a[i]<t) printf(" %lf",(t-a[i])/sum*100); else printf(" 0");
		puts("");
	}
	return 0;
}
