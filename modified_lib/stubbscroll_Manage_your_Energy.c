#include <stdio.h>
#include <string.h>

#define MAXN 12
#define MAXE 10
int v[MAXN];
int dp[MAXN][MAXE];

int main() {
	int T,no=1,E,R,N,i,j,k,z,ans;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&E,&R,&N);
		for(i=0;i<N;i++) scanf("%d",&v[i]);
		memset(dp,-1,sizeof(dp));
		dp[0][E]=0;
		for(i=0;i<N;i++) for(j=0;j<=E;j++) if(dp[i][j]>-1) {
			for(k=0;k<=j;k++) {
				z=j-k+R;
				if(z>E) z=E;
				if(dp[i+1][z]<dp[i][j]+k*v[i]) dp[i+1][z]=dp[i][j]+k*v[i];
			}
		}
		ans=0;
		for(i=0;i<=E;i++) if(ans<dp[N][i]) ans=dp[N][i];
		printf("Case #%d: %d\n",no++,ans);
	}
	return 0;
}
