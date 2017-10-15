#include <stdio.h>
#include <stdlib.h>
FILE *fin;
FILE *fout;
int Smax;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void solve()
{
    int first_iteration;
    char c;
    int i;
    int total = 0;
    int sol = 0;
    fscanf(fin, "%d", &Smax);
    fscanf(fin, "%c", &c);
    for (i = 0; i < (Smax + 1); i++) {
	fscanf(fin, "%c", &c);
	if (total < i) {
	    sol = (sol + i) - total;
	    total = i;
	}
	total = (total + c) - '0';
    }
    fprintf(fout, "%d\n", sol);
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
