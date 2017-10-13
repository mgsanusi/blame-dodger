#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

unsigned long long rnd[32]={0};
int main(int argc, char *argv[])
{
	int i=0;
	int T=0,N=0,cas=1;
	unsigned long long K=0;

	rnd[1] = 2;
	for (i = 2;i<=30;i++){
		rnd[i] = (rnd[i-1])*2;
	}

	scanf("%d",&T);
	while (T--){
		scanf("%d %llu",&N,&K);
		K=K%rnd[N];
		if (K==rnd[N]-1){
			printf("Case #%d: ON\n",cas++);
		}else{
			printf("Case #%d: OFF\n",cas++);
		}
	}
	return 0;
}
