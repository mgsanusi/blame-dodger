#include <stdio.h>
#include <stdlib.h>
double C, F, X;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
double new_atof(const char *str);
double recursiuCookie(double ant, double prod, double actual)
{
	double previst;
	previst = actual + X / prod;
	if (ant < previst) {
		return ant;
	} else {
		return recursiuCookie(previst, prod + F, actual + C / prod);
	}
}

int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	char kk;
	char buffer[512];
	int total, i;
	double temps;
	fin = new_fopen(argv[1], "r");
	fout = new_fopen("out", "w");
	if (fin == NULL || fout == NULL) {
		printf("Fitxer out.\n");
	} else {
		fscanf(fin, "%d", &total);
		fscanf(fin, "%c", &kk);
		for (i = 0; i < total; i++) {
			fscanf(fin, "%s", buffer);
			C = new_atof(buffer);
			fscanf(fin, "%s", buffer);
			F = new_atof(buffer);
			fscanf(fin, "%s", buffer);
			X = new_atof(buffer);
			fscanf(fin, "%c", &kk);
			temps = recursiuCookie(X, 2.0, 0.0);
			fprintf(fout, "Case #%d: %.7f\n", i + 1, temps);
		}
		new_fclose(fin);
		new_fclose(fout);
	}
	return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
double new_atof(const char *str)
{
	return atof(str);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}
