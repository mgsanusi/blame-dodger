#include <stdio.h>
#include <stdlib.h>
FILE *fin;
FILE *fout;
int h[2501];
int sol[50];
int N;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void solve()
{
	int first_iteration;
	int i;
	int j;
	int k;
	int a;
	fscanf(fin, "%d", &N);
	for (i = 0; i < 2501; i++)
		h[i] = 0;
	for (i = 0; i < (((2 * N) - 1) * N); i++) {
		fscanf(fin, "%d", &a);
		h[a]++;
	}
	k = 0;
	for (i = 0; i < 2501; i++) {
		if ((h[i] % 2) != 0) {
			sol[k] = i;
			k++;
		}
	}
	for (i = 0; i < k; i++)
		for (j = i + 1; j < k; j++)
			if (sol[j] < sol[i]) {
				int t = sol[i];
				sol[i] = sol[j];
				sol[j] = t;
			}
	if (k != N)
		printf("ERROR\n");
	for (i = 0; i < N; i++) {
		fprintf(fout, "%d ", sol[i]);
	}
	fprintf(fout, "\n");
}

int main(int argc, char *argv[])
{
	int first_iteration;
	char kk;
	int total;
	int i;
	fin = new_fopen(argv[1], "r");
	fout = new_fopen("out", "w");
	if ((fin == 0) || (fout == 0)) {
		printf("Fitxer out.\n");
	} else {
		fscanf(fin, "%d", &total);
		fscanf(fin, "%c", &kk);
		for (i = 0; i < total; i++) {
			fprintf(fout, "Case #%d: ", i + 1);
			solve();
		}
		new_fclose(fin);
		new_fclose(fout);
	}
	return 0;
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
