#include <stdio.h>
int testc;
int test;
int _heap;
int j;
int k1;
int k2;
int type_a[110];
int type_b[110];
int n;
int envp;
long long account_a[110];
long long account_b[110];
long long a[110][110];
long long sum_a[110][110];
long long sum_b[110][110];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int Main()
{
	FILE *Fin = new_fopen("gcj3_3.in", "r");
	FILE *Fout = new_fopen("gcj3_3.out", "w");
	fscanf(Fin, "%d", &testc);
	for (test = 1; test <= testc; test++) {
		fscanf(Fin, "%d%d", &n, &envp);
		for (_heap = 1; _heap <= n; _heap++) {
			fscanf(Fin, "%I64d%d", &account_a[_heap],
			       &type_a[_heap]);
			a[_heap][0] = 0;
		}
		for (j = 1; j <= envp; j++) {
			fscanf(Fin, "%I64d%d", &account_b[j], &type_b[j]);
			a[0][j] = 0;
		}
		a[0][0] = 0;
		for (_heap = 1; _heap <= 100; _heap++)
			sum_a[0][_heap] = (sum_b[0][_heap] = 0);
		for (_heap = 1; _heap <= n; _heap++)
			for (j = 1; j <= 100; j++)
				sum_a[_heap][j] =
				    type_a[_heap] ==
				    j ? sum_a[_heap - 1][j] +
				    account_a[_heap] : sum_a[_heap - 1][j];
		for (_heap = 1; _heap <= envp; _heap++)
			for (j = 1; j <= 100; j++)
				sum_b[_heap][j] =
				    type_b[_heap] ==
				    j ? sum_b[_heap - 1][j] +
				    account_b[_heap] : sum_b[_heap - 1][j];
		for (_heap = 1; _heap <= n; _heap++)
			for (j = 1; j <= envp; j++) {
				a[_heap][j] =
				    a[_heap - 1][j] >
				    a[_heap][j - 1] ? a[_heap -
							1][j] : a[_heap][j - 1];
				if (type_a[_heap] == type_b[j]) {
					int target = type_a[_heap];
					for (k1 = 0; k1 < _heap; k1++)
						for (k2 = 0; k2 < j; k2++) {
							long long delta =
							    (sum_a[_heap]
							     [target] -
							     sum_a[k1][target])
							    <
							    (sum_b[j][target] -
							     sum_b[k2][target])
							    ?
							    sum_a[_heap][target]
							    -
							    sum_a[k1][target] :
							    sum_b[j][target] -
							    sum_b[k2][target];
							a[_heap][j] =
							    (a[k1][k2] +
							     delta) >
							    a[_heap][j] ?
							    a[k1][k2] +
							    delta : a[_heap][j];
						}
				}
			}
		fprintf(Fout, "Case #%d: %I64d\n", test, a[n][envp]);
	}
	new_fclose(Fin);
	new_fclose(Fout);
	return 0;
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}
