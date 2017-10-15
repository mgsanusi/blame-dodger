#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
FILE *fin, *fout;
int D;
int pan[1010];
void solve()
{
    int i, j, sq;
    int max = 0, min, sum;
    fscanf(fin, "%d", &D);
    for (i = 0; i < D; i++) {
	fscanf(fin, "%d", &pan[i]);
	if (pan[i] > max)
	    max = pan[i];
    }
    min = max;
    sq = sqrt(max);
    if (sq * sq != max)
	sq++;
    for (i = sq; i < max; i++) {
	sum = 0;
	for (j = 0; j < D; j++) {
	    if (pan[j] % i == 0)
		sum += pan[j] / i - 1;
	    else
		sum += pan[j] / i;
	}
	if (sum + i < min)
	    min = sum + i;
    }
    fprintf(fout, "%d\n", min);
}

int main(int argc, char *argv[])
{
    char kk;
    int total, i;
    fin = fopen(argv[1], "r");
    fout = fopen("out", "w");
    if (fin == NULL || fout == NULL) {
	printf("Fitxer out.\n");
    } else {
	fscanf(fin, "%d", &total);
	fscanf(fin, "%c", &kk);
	for (i = 0; i < total; i++) {
	    fprintf(fout, "Case #%d: ", i + 1);
	    solve();
	}
	fclose(fin);
	fclose(fout);
    }
    return 0;
}
