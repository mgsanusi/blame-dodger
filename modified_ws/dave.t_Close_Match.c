#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE * in;
FILE * out;
 int P[27];
int S[27];
 int cmpP(const void *a, const void *b)
{
	int A = P[*(int *)a];
	int B = P[*(int *)b];
	 if (A > B)
		return -1;
	if (A == B)
		return 0;
	return 1;
}

 int main(void)
{
	 int t, T, n, N, p, C;
	 in = fopen(fileNameIn, "r");
	out = fopen(fileNameOut, "w");
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
		qsort(S, N, sizeof(int), cmpP);
		while (C > 3) {
			if (P[S[0]] > P[S[1]]) {
				fprintf(out, " %c", 'A' - 1 + S[0]);
				P[S[0]] -= 1;
				C--;
			} else {
				fprintf(out, " %c%c", 'A' - 1 + S[0],
					 'A' - 1 + S[1]);
				P[S[0]] -= 1;
				P[S[1]] -= 1;
				C--;
				C--;
				qsort(S, N, sizeof(int), cmpP);
		} } qsort(S, N, sizeof(int), cmpP);
		if (C == 3) {
			fprintf(out, " %c", 'A' - 1 + S[0]);
			fprintf(out, " %c%c", 'A' - 1 + S[1], 'A' - 1 + S[2]);
		} else {
			fprintf(out, " %c%c", 'A' - 1 + S[0], 'A' - 1 + S[1]);
		}
		fprintf(out, "\n");
	}
	 fclose(in);
	fclose(out);
}
