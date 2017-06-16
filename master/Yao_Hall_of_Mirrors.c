#include<stdio.h>
#include<string.h>

int pre[1<<21];
int a[32];
int n;
int r1[32],r2[32];
int a1,a2;

int main() {
	int N,cs=0,i,j,k,sum,f;
	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		memset(pre,0xff,sizeof(pre));
		pre[0]=f=0;
		for(i=sum=0;i<n && !f;sum+=a[i],i++) for(j=sum;j>=0 && !f;j--) if (pre[j]>=0) {
			if (pre[j+a[i]]<0) pre[j+a[i]]=j; else {
				f=1;
				for(a1=0,k=j+a[i];k>0;k=pre[k]) r1[a1++]=k-pre[k];
				for(a2=0,k=j;k>0;k=pre[k]) r2[a2++]=k-pre[k];
				r2[a2++]=a[i];
			}
		}
		printf("Case #%d:\n",++cs);
		if (!f) {
			puts("Impossible");
			continue;
		}
		for(i=0;i<a1;i++) {
			for(j=0;j<a2-1;j++) if (r1[i]==r2[j]) break;
			if (j<a2-1) {
				r1[i]=r1[a1-1];
				a1--;
				i--;
				r2[j]=r2[a2-2];
				r2[a2-2]=r2[a2-1];
				a2--;
			}
		}
		for(i=0;i<a1-1;i++) printf("%d ",r1[i]);printf("%d\n",r1[i]);
		for(i=0;i<a2-1;i++) printf("%d ",r2[i]);printf("%d\n",r2[i]);
	}
	return 0;
}
