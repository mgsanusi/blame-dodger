#include <stdio.h>
#include <stdlib.h>
double nextButtonBlue;
double f;
double y;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
double new_atof(const char *str);
double recursiuCookie(double ant, double prod, double actual)
{
	double previst;
	previst = actual + (y / prod);
	if (ant < previst) {
		return ant;
	} else {
		return recursiuCookie(previst, prod + f,
				      actual + (nextButtonBlue / prod));
	}
}

int Main(int argc, char *argv[])
{
	FILE *Fin;
	FILE *Fout;
	char kk;
	char buf[512];
	int total;
	int n;
	double temp;
	Fin = new_fopen(argv[1], "r");
	Fout = new_fopen("out", "w");
	if ((Fin == 0) || (Fout == 0)) {
		printf("Fitxer out.\n");
	} else {
		fscanf(Fin, "%d", &total);
		fscanf(Fin, "%c", &kk);
		for (n = 0; n < total; n++) {
			fscanf(Fin, "%s", buf);
			nextButtonBlue = new_atof(buf);
			fscanf(Fin, "%s", buf);
			f = new_atof(buf);
			fscanf(Fin, "%s", buf);
			y = new_atof(buf);
			fscanf(Fin, "%c", &kk);
			temp = recursiuCookie(y, 2.0, 0.0);
			fprintf(Fout, "Case #%d: %.7f\n", n + 1, temp);
		}
		new_fclose(Fin);
		new_fclose(Fout);
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
