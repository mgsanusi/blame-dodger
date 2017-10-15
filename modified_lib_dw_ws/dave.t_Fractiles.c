#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int main(void)
{
    int first_iteration;
    int t;
    int T;
    int K;
    int C;
    int s;
    int S;
    in = new_fopen(fileNameIn, "r");
    out = new_fopen(fileNameOut, "w");
    fscanf(in, "%d", &T);
    for (t = 1; t <= T; t++) {
	fprintf(out, "Case #%d:", t);
	fscanf(in, "%d", &K);
	fscanf(in, "%d", &C);
	fscanf(in, "%d", &S);
	for (s = 1; s <= K; ++s) {
	    fprintf(out, " %d", s);
	}
	fprintf(out, "\n");
    }
    new_fclose(in);
    new_fclose(out);
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
