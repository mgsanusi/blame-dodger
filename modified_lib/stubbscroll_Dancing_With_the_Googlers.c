#include <stdio.h>
#include <stdlib.h>
void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));


int compi(const void *a,const void *b) {
	if(*(int *)a>*(int *)b) return -1;
	if(*(int *)a<*(int *)b) return 1;
	return 0;
}

int main() {
	int T,caseno=1;
	int n,s,p,lo1,lo2;
	int i,score[100],ans;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&n,&s,&p);
		for(i=0;i<n;i++) scanf("%d",&score[i]);
		new_qsort(score,n,sizeof(int),compi);
		lo1=p-1;
		lo2=p-2;
		if(lo1<0) lo1=0;
		if(lo2<0) lo2=0;
		for(ans=i=0;i<n;i++) {
			if(score[i]>=p+lo1+lo1) ans++;
			else if(s && score[i]>=p+lo2+lo2) ans++,s--;
		}
		printf("Case #%d: %d\n",caseno++,ans);
	}
	return 0;
}

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}