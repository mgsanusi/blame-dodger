#include <stdio.h>

int main() {
	long long int t, i, j, k, K, C, S;

	scanf("%lld", &t);
	for(i=1; i <= t; i++) {
		scanf("%lld%lld%lld", &K, &C, &S);

		printf("Case #%lld:", i);

		if(K+1-C > S) {
			printf(" IMPOSSIBLE\n");
			continue;
		}

		for(j=1; j <= S; j++)
			printf(" %lld", j);
		printf("\n");

/*		long long int n = K, s = 1;
		for(j=1; j < C; j++) {
			n--;
			s = s*K-n+1;
			if(n == 1)
				break;
		}
		for(j=0; j < n; j++) {
			printf(" %lld", s+j);
		}
		printf("\n");*/
	}
	return 0;
}

