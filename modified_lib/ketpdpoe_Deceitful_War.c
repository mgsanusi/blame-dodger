#include<stdio.h>
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++){
		int n,i,j;
		scanf("%d",&n);
		double a[1005],b[1005],tmp;
		for(i=0;i<n;i++)scanf("%lf",&a[i]);
		for(i=0;i<n;i++)scanf("%lf",&b[i]);
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(a[i]>a[j]){
					tmp=a[i];
					a[i]=a[j];
					a[j]=tmp;
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(b[i]>b[j]){
					tmp=b[i];
					b[i]=b[j];
					b[j]=tmp;
				}
			}
		}
		int ansa=0,ansb=0;
		int fr=0,be=n;
		for(i=0;i<n;i++){
			if(a[i]>b[fr]){
				ansa++;
				fr++;
			}
		}
		for(i=n-1;i>=0;i--){
			if(a[i]<b[be-1]){
				be--;
			}
			else{
				ansb++;
			}
		}
		printf("Case #%d: %d %d\n",I+1,ansa,ansb);
	}
	return 0;
}