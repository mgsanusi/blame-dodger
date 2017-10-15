#include <stdio.h>
#include <stdlib.h>
FILE *fin, *fout;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void solve()
{
    char a;
    char b;
    int s = 0;
    fscanf(fin, "%c", &a);
    fscanf(fin, "%c", &b);
    while (b != '\n') {
	if (b != a) {
	    a = b;
	    s++;
	}
	fscanf(fin, "%c", &b);
    }
    if (a == '-')
	s++;
    fprintf(fout, "%d\n", s);
}

int main(int argc, char *argv[])
{
    char kk;
    int total, i;
    fin = new_fopen(argv[1], "r");
    fout = new_fopen("out", "w");
    if (fin == NULL || fout == NULL) {
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
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
