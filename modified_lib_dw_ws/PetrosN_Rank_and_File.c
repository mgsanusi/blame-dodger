#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int gigi(int N)
{
    int first_iteration;
    int q = (2 * N) - 1;
    return q * N;
}

int main()
{
    int first_iteration;
    FILE *fin;
    FILE *fout;
    fin = new_fopen("B-small-attempt0.in", "r");
    fout = new_fopen("output.txt", "w");
    int i;
    int q;
    int T;
    int H[2501];
    int N;
    int temph;
    for (i = 0; i < 2501; i++) {
	H[i] = 0;
    }
    fscanf(fin, "%d", &T);
    for (q = 1; q <= T; q++) {
	fscanf(fin, "%d", &N);
	for (i = 0; i < gigi(N); i++) {
	    fscanf(fin, "%d", &temph);
	    H[temph]++;
	}
	fprintf(fout, "Case #%d:", q);
	for (i = 0; i < 2501; i++) {
	    if (H[i] % 2) {
		fprintf(fout, " %d", i);
	    }
	}
	fprintf(fout, "\n");
	for (i = 0; i < 2501; i++) {
	    H[i] = 0;
	}
    }
    new_fclose(fin);
    new_fclose(fout);
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
