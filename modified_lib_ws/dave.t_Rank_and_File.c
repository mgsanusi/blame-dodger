#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE * in;
FILE * out;
 int count[2501];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
 int main(void)
{
     int i, I, t, T, n, N;
     in = new_fopen(fileNameIn, "r");
    out = new_fopen(fileNameOut, "w");
     fscanf(in, "%d", &T);
     for (t = 1; t <= T; t++) {
	fprintf(out, "Case #%d:", t);
	fscanf(in, "%d", &N);
	for (i = 0; i <= 2500; ++i) {
	    count[i] = 0;
	}
	I = (2 * N - 1) * N;
	for (i = 0; i < I; ++i) {
	    fscanf(in, "%d", &n);
	    count[n]++;
	}
	for (i = 1; i <= 2500; ++i) {
	    if (count[i] % 2 == 1) {
		fprintf(out, " %d", i);
	    }
	}
	fprintf(out, "\n");
    }
     new_fclose(in);
    new_fclose(out);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
