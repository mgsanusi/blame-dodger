#include <stdio.h>
#include <stdlib.h>
FILE *fin, *fout;
int R, C, W;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int slv()
{
	if (W == 1)
		return R * C;
	if (W == C)
		return R - 1 + W;
	if (C % W != 0)
		return (C / W) * (R - 1) + W + C / W;
	return (C / W) * (R - 1) + W + C / W - 1;
}

void solve()
{
	fscanf(fin, "%d %d %d", &R, &C, &W);
	fprintf(fout, "%d\n", slv());
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
