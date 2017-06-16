#include <stdio.h>
#include <string.h>

int my_cmp(const void* a, const void* b) {
	const int* ia = (const int*) a;
	const int* ib = (const int*) b;
	return *ia > *ib;
}

int main() {
	int T, N, tc, i, j, k;
	int count[2600], sol[2600];
	scanf("%d", &T);
	for(tc = 1; tc <= T; ++tc) {
		scanf("%d", &N);
		memset(count, 0, 2600*sizeof(int));
		
		for(i = 0; i < 2*N-1; ++i) {
			for(j = 0; j < N; ++j) {
				scanf("%d", &k);
				++count[k];
			}
		}
		for(i = j = 0; j < 2600; ++j) {
			if(count[j]%2)
				sol[i++] = j;
		}
		printf("Case #%d:", tc);
		for(j = 0; j < i; ++j)
			printf(" %d", sol[j]);
		printf("\n");
	}
	return 0;
}
