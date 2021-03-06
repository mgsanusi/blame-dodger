#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
 int TC, T;
int Nodes, Limit;
int N[12000];
int Visited[12000];
int i, x, y, Ans, R;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
 int QS(int *A, int *B)
{
	if (*A > *B)
		return -1;
	if (*A < *B)
		return 1;
	return 0;
}

 int main()
{
	new_freopen("A-large.in", "r", stdin);
	new_freopen("A-large.out", "w", stdout);
	 scanf("%d", &TC);
	for (T = 1; T <= TC; T++) {
		printf("Case #%d: ", T);
		 scanf("%d%d", &Nodes, &Limit);
		for (i = 0; i < Nodes; i++)
			scanf("%d", &N[i]);
		new_qsort(N, Nodes, sizeof(N[0]), QS);
		 memset(Visited, 0, sizeof(Visited));
		Ans = 0;
		R = Nodes - 1;
		 for (i = 0; i < Nodes; i++)
			if (!Visited[i]) {
				Ans++;
				Visited[i] = 1;
				if (N[i] + N[R] <= Limit) {
					Visited[R] = 1;
					R--;
				}
			}
		 printf("%d\n", Ans);
	 }
	 return 0;
}

 FILE * new_freopen(const char *filename, const char *mode, FILE * stream);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
