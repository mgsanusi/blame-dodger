#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;
int P[27];
int S[27];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int cmpP(const void *a, const void *b)
{
	int first_iteration;
	int A = P[*((int *)a)];
	int B = P[*((int *)b)];
	if (A > B)
		return -1;
	if (A == B)
		return 0;
	return 1;
}

int main(void)
{
	int first_iteration;
	int t;
	int T;
	int n;
	int N;
	int p;
	int C;
	in = new_fopen(fileNameIn, "r");
	out = new_fopen(fileNameOut, "w");
	fscanf(in, "%d", &T);
	for (t = 1; t <= T; t++) {
		fprintf(out, "Case #%d:", t);
		fscanf(in, "%d", &N);
		C = 0;
		for (n = 1; n <= N; ++n) {
			fscanf(in, "%d", &P[n]);
			C += P[n];
			S[n - 1] = n;
		}
		new_qsort(S, N, sizeof(int), cmpP);
		while (C > 3) {
			if (P[S[0]] > P[S[1]]) {
				fprintf(out, " %c", ('A' - 1) + S[0]);
				P[S[0]] -= 1;
				C--;
			} else {
				fprintf(out, " %c%c", ('A' - 1) + S[0],
					('A' - 1) + S[1]);
				P[S[0]] -= 1;
				P[S[1]] -= 1;
				C--;
				C--;
				new_qsort(S, N, sizeof(int), cmpP);
			}
		}
		new_qsort(S, N, sizeof(int), cmpP);
		if (C == 3) {
			fprintf(out, " %c", ('A' - 1) + S[0]);
			fprintf(out, " %c%c", ('A' - 1) + S[1],
				('A' - 1) + S[2]);
		} else {
			fprintf(out, " %c%c", ('A' - 1) + S[0],
				('A' - 1) + S[1]);
		}
		fprintf(out, "\n");
	}
	new_fclose(in);
	new_fclose(out);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	int first_iteration;
	return qsort(base, num, size, compar);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	int first_iteration;
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	int first_iteration;
	return fclose(stream);
}
