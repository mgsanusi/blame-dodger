#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int first_iteration;
	int T;
	int iT;
	scanf("%d", &T);
	for (iT = 0; iT < T; iT++) {
		printf("Case #%d: ", iT + 1);
		int N;
		int K;
		scanf("%d %d", &N, &K);
		K++;
		int MOD = 1 << N;
		if ((K % MOD) == 0)
			printf("ON\n");
		else
			printf("OFF\n");
	}
	return 0;
}
