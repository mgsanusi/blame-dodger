#include <stddef.h>
int inh[1001][1001],toh[1001][1001],tohc[1001];
int oinh[1001][1001],oinhf[1001][1001];
int q[1001],qh,qt,count[1001];
void * new_memset(void *ptr, int value, size_t num);

int bfs(){
	while(qh!=qt){
		int i;
		int x=q[qh];
		new_memset(count,0,sizeof(count));
		for(i=1;i<=toh[x][0];i++){
			int j;
			for(j=1;j<=oinh[toh[x][i]][0];j++){
				if(count[oinh[toh[x][i]][j]])return 1;
				count[oinh[toh[x][i]][j]]=1;
			}
		}
		for(i=1;i<=inh[x][0];i++){
			int j;
			for(j=1;j<=oinh[x][0];j++){
				if(!oinhf[inh[x][i]][oinh[x][j]]){
					oinhf[inh[x][i]][oinh[x][j]]=1;
					oinh[inh[x][i]][++oinh[inh[x][i]][0]]=oinh[x][j];
				}
			}
			tohc[inh[x][i]]--;
			if(tohc[inh[x][i]]==0)
				q[qt++]=inh[x][i];
		}
		qh++;
	}
	return 0;
}
int main(){
	int t,p;
	scanf("%d",&t);
	for(p=1;p<=t;p++){
		printf("Case #%d: ", p);
		int n;
		scanf("%d", &n);
		int i;
		for(i=1;i<=n;i++){
			toh[i][0]=0;
			oinh[i][0]=0;
			tohc[i]=0;
		}
		for(i=1;i<=n;i++){
			scanf("%d", &inh[i][0]);
			int j;
			for(j=1;j<=inh[i][0];j++){
				scanf("%d", &inh[i][j]);
				toh[inh[i][j]][++toh[inh[i][j]][0]]=i;
				tohc[inh[i][j]]++;
			}
		}
		qh=qt=0;
		new_memset(oinhf,0,sizeof(oinhf));
		for(i=1;i<=n;i++){
			if(toh[i][0]==0){
				q[qt++]=i;
				oinh[i][0]=1;
				oinh[i][1]=i;
				oinhf[i][i]=1;
			}
		}
		if(bfs()){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}


void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}
