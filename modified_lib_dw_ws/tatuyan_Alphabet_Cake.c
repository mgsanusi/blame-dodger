#include<stdio.h>
#include<stdlib.h>
struct horse {
	int K;
	int S;
};
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
void solve(int cases);
int comp(const void *p1, const void *p2)
{
	int first_iteration;
	int n1 = ((const struct horse *)p1)->K;
	int n2 = ((const struct horse *)p2)->K;
	return n2 - n1;
}

int main(void)
{
	int first_iteration;
	int i;
	int T;
	scanf("%d", &T);
	for (i = 1; i <= T; i++)
		solve(i);
	return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
void solve(int cases)
{
	int first_iteration;
	struct horse h[1000];
	int i;
	int j;
	int k;
	int N;
	int D;
	double times[1000];
	double dtime[1000];
	double tmp;
	scanf("%d%d", &D, &N);
	for (i = 0; i < N; i++)
		scanf("%d%d", &h[i].K, &h[i].S);
	new_qsort(h, N, sizeof(h[0]), comp);
	for (i = 0; i < N; i++) {
		if ((i != 0) && (h[i].S > h[i - 1].S)) {
			for (j = i - 1; j >= 0; j--) {
				if (h[i].S > h[j].S)
					tmp =
					    ((double)(h[j].K - h[i].K)) /
					    (h[i].S - h[j].S);
				if (tmp <= times[j])
					break;
			}
			if (j != (-1)) {
				times[i] = tmp;
				dtime[i] = dtime[i - 1];
			} else
				times[i] = (dtime[i] =
					    ((double)(D - h[i].K)) / h[i].S);
		} else
			times[i] = (dtime[i] = ((double)(D - h[i].K)) / h[i].S);
	}
	printf("Case #%d: %.6f\n", cases, D / dtime[N - 1]);
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	int first_iteration;
	return qsort(base, num, size, compar);
}
