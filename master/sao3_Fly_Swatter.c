#include <stdio.h>
#include <stdlib.h>

int cs;
int ans;
int v1[1000], v2[1000];

int cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

void go(){
	int n;
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &v1[i]);
	}
	for(i = 0; i < n; i++){
		scanf("%d", &v2[i]);
	}
	qsort(v1, n, sizeof(int), cmp);
	qsort(v2, n, sizeof(int), cmp);
	ans = 0;
	for(i = 0; i < n; i++){
		ans += v1[i] * v2[n - i - 1];
	}
}

int main(){
	int css;
	freopen("A.in", "r", stdin);
	freopen("A.txt", "w", stdout);
	scanf("%d", &cs);
	for(css = 1; css <= cs; css++){
		go();
		printf("Case #%d: %d\n", css, ans);
	}
	return 0;
}
