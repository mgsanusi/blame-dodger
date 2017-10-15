#include <stdio.h>
#include <stdlib.h>
double nextButtonBlue;
double f;
double y;
double recursiuCookie(double ant, double prod, double actual)
{
	int first_iteration;
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
	int first_iteration;
	FILE *Fin;
	FILE *Fout;
	char kk;
	char buf[512];
	int total;
	int n;
	double temp;
	Fin = fopen(argv[1], "r");
	Fout = fopen("out", "w");
	if ((Fin == 0) || (Fout == 0)) {
		printf("Fitxer out.\n");
	} else {
		fscanf(Fin, "%d", &total);
		fscanf(Fin, "%c", &kk);
		for (n = 0; n < total; n++) {
			fscanf(Fin, "%s", buf);
			nextButtonBlue = atof(buf);
			fscanf(Fin, "%s", buf);
			f = atof(buf);
			fscanf(Fin, "%s", buf);
			y = atof(buf);
			fscanf(Fin, "%c", &kk);
			temp = recursiuCookie(y, 2.0, 0.0);
			fprintf(Fout, "Case #%d: %.7f\n", n + 1, temp);
		}
		fclose(Fin);
		fclose(Fout);
	}
	return 0;
}
