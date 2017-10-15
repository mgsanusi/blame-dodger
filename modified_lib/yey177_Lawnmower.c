#include <stdio.h>
#define MAX(p,q) (((p)>(q))?(p):(q))
#define MIN(p,q) (((p)<(q))?(p):(q))
int d[102][102];

int main(){
	int t,n,m,i,j,k,x,max,min,f;
	scanf("%d",&t);
	for(x=1;x<=t;x++){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&d[i][j]);
		f=1;
		for(k=1;k<=100;k++){
			for(i=0;i<n;i++){
				min=101;max=0;
				for(j=0;j<m;j++){
					if(d[i][j]){
						min=MIN(min,d[i][j]);
						max=MAX(max,d[i][j]);
					}
				}
				if(min==k&&max==k){
					for(j=0;j<m;j++)d[i][j]=0;
				}
			}
			for(j=0;j<m;j++){
				min=101;max=0;
				for(i=0;i<n;i++){
					if(d[i][j]){
						min=MIN(min,d[i][j]);
						max=MAX(max,d[i][j]);
					}
				}
				if(min==k&&max==k){
					for(i=0;i<n;i++)d[i][j]=0;
				}
			}
			for(i=0;i<n;i++)for(j=0;j<m;j++){
				if(d[i][j]==k){f=0;goto END;}
			}
		}
		END:
		printf("Case #%d: %s\n",x,f?"YES":"NO");
	}
	return 0;
}
