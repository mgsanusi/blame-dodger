#include <stdio.h>
#include <stdlib.h>
FILE *fin, *fout;
int masks[] = { 1, 5, 9, 17, 33, 21, 65, 129 };

int N = 8;
int t;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void sll(char *c)
{
    t++;
    if (t <= 50)
	fprintf(fout, "11%s11 3 4 5 6 7 8 9 10 11\n", c);
}

void solve()
{
    int i, j;
    sll("000000000000");
    for (i = 0; i < N; i++) {
	long long a = masks[i];
	int r = 0;
	while (!r) {
	    if ((a >> 10 & 1) == 1)
		r = 1;
	    char s[13];
	    for (j = 11; j >= 0; j--) {
		s[j] = 3 * a >> (11 - j) & 1;
		s[j] += '0';
	    }
	    s[12] = '\0';
	    sll(s);
	    a *= 2;
	}
    }
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
	    fprintf(fout, "Case #%d: \n", i + 1);
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
