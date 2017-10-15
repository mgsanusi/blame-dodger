#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

const int MOD = 100003;
int dp[512][512]={{0}};

int C[512][512]={{0}};
void dodp(int x,int y){
	int i,j,k;
	int sum = 0;
	if (y==1){
		dp[x][y] = 1;
		return;
	}
	if (dp[x][y] == 0){
		for (i=1;i<y;i++){
			dodp(y,i);
			sum = (sum + dp[y][i]*C[x-y-1][y-i-1]%MOD)%MOD;
		}
		dp[x][y]=(sum)%MOD;
	}
}
int main(int argc, char *argv[]){
	int i=0,j=0,k=0,T=0,n,cas=1,res=0;

	for (i=0;i<=500;i++){
		C[i][0]=1;
		for (j=1;j<i;j++){
			C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
		}
		C[i][i]=1;
	}
	dp[1][1]=1;
	for (i=1;i<=500;i++){
		for (j=1;j<=i;j++){
			dodp(i,j);
		}
	}

	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);

		res=0;
		for (i=1;i<=n;i++){
			res = (res + dp[n][i])%MOD;
		}
		printf("Case #%d: %d\n",cas++,res);
	}
	return 0;
}
