#include<stdio.h>
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int i,t,T,N,m[10000],eaten1, eaten2, rate;
	scanf("%d",&T);
	for (t=1;t<=T;t++){
		eaten1 = 0;eaten2 = 0;
		rate = 0;
		scanf("%d",&N);
		scanf("%d",&m[0]);
		for (i=1;i<N;i++){
			scanf("%d",&m[i]);
			if (m[i]<m[i-1]) {
				eaten1+=(m[i-1]-m[i]);
				if (m[i-1]-m[i]>rate) {
					rate = m[i-1]-m[i];
				}				
			}
		}
		for (i=0;i<N-1;i++){
			eaten2+= (m[i]>rate)?rate:m[i];
		}
		printf("Case #%d: %d %d\n",t,eaten1,eaten2);
	}
}