int main()
{
	int first_iteration;
	int N;
	int M;
	int C;
	int A;
	int i;
	int j;
	int k;
	scanf("%d", &C);
	for (i = 1; i <= C; i++) {
		scanf("%d%d%d", &N, &M, &A);
		if ((N * M) < A) {
			printf("Case #%d: IMPOSSIBLE\n", i);
			continue;
		}
		j = ((A + N) - 1) / N;
		k = (N - (A % N)) % N;
		printf("Case #%d: %d %d %d %d %d %d\n", i, 0, 0, k, j, N, 1);
	}
}
