#include <stdio.h>
#include <stdlib.h>
 long long
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int qwerty(long long int k)
{
	long long int i, p = 1;
	for (i = 0; i < k; i++) {
		p = p * 10;
	}
	return p;
}

 long long haze(long long int N, long long int d)
{
	long long int q = N / qwerty(d);
	return q % 10;
}

 int main() 
{
	FILE * fin, *fout;
	fin = new_fopen("A-small-attempt2.in", "r");
	fout = new_fopen("output.txt", "w");
	long long int T, N, A[10], found, k, i, d, s;
	fscanf(fin, "%I64d", &T);
	for (k = 1; k <= T; k++) {
		fscanf(fin, "%I64d", &N);
		i = 1, found = 0;
		if (N == 0) {
			fprintf(fout, "Case #%I64d: INSOMNIA \n", k);
			continue;
		}
		for (s = 0; s < 10; s++) {
			A[s] = 0;
		}
		while (!(found)) {
			d = 0;
			while (qwerty(d) <= (N * i)) {
				A[haze(N * i, d)] = 1;
				d++;
			}
			found = 1;
			for (s = 0; s < 10; s++) {
				found = found * A[s];
			}
			 i++;
		 }
		i--;
		fprintf(fout, "Case #%I64d: %I64d \n", k, i * N);
	    }
	new_fclose(fin);
	new_fclose(fout);
	return 0;
}

FILE * new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}
