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
int Main(void)
{
    int first_iteration;
    int f;
    int a;
    int opp;
    int ed;
    int a;
    int b;
    in = new_fopen(fileNameIn, "r");
    out = new_fopen(fileNameOut, "w");
    fscanf(in, "%d", &a);
    for (f = 1; f <= a; f++) {
	fprintf(out, "Case #%d:", f);
	fscanf(in, "%d", &opp);
	fscanf(in, "%d", &ed);
	fscanf(in, "%d", &b);
	for (a = 1; a <= opp; ++a) {
	    fprintf(out, " %d", a);
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
