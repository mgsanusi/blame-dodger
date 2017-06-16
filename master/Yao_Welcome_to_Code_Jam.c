#include<stdio.h>
#include<string.h>

#define M 10000

int dp[512][30];
char str[]="welcome to code jam";
char a[512];
int n;

int main() {
	int cs=0,i,j;

	for(scanf("%d",&n),gets(a);n--;) {
		gets(a);
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(i=0;a[i];i++) {
			for(j=0;str[j];j++) if (a[i]==str[j]) 
				if ((dp[i+1][j+1]+=dp[i][j])>=M) dp[i+1][j+1]-=M;
			for(j=0;str[j];j++) if ((dp[i+1][j]+=dp[i][j])>=M) dp[i+1][j]-=M;
			if ((dp[i+1][j]+=dp[i][j])>=M) dp[i+1][j]-=M;
		}
		printf("Case #%d: %04d\n",++cs,dp[i][j]);
	}
	return 0;
}
