#include <stdio.h>
#include <string.h>
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))
int d[10008],l[10008],dp[10008];

int main(){
	int t,k,n,D,res=0,tmp,i,j;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		res=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&d[i],&l[i]);
		}
		scanf("%d",&D);
		memset(dp,-1,sizeof(dp));
		dp[0]=d[0]*2;
		for(i=0;i<n;i++){
			if(dp[i]>=D){res=1;break;}
			j=i+1;
			while(j<n&&d[j]<=dp[i]){
				tmp=MIN(l[j],d[j]-d[i]);
				dp[j]=MAX(dp[j],d[j]+tmp);
				j++;
			}
		}
		printf("Case #%d: %s\n",k,res?"YES":"NO");
	}
	return 0;
}
