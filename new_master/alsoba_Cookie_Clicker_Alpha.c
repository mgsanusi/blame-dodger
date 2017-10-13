#include <stdio.h>
#include <stdlib.h>

double C, F, X;

double recursiuCookie(double ant, double prod, double actual) {
	double previst;
	previst = actual + X/prod; 
	if (ant<previst) {
		return ant;
	}
	else
	{
		return recursiuCookie(previst, prod+F, actual + C/prod);
	}
}

int main(int argc, char *argv[]){
	FILE *fin, *fout;
	char kk;
	char buffer[512];
	int total, i;
	double temps;

	fin=fopen(argv[1], "r");
	fout=fopen("out", "w");
	if (fin==NULL || fout == NULL)
	{
		printf("Fitxer out.\n");
	}
	else 
	{
		fscanf(fin, "%d", &total);
		fscanf(fin, "%c", &kk);
		for (i = 0; i<total; i++)
		{
			fscanf(fin, "%s", buffer);
			C = atof(buffer);
			fscanf(fin, "%s", buffer);
			F = atof(buffer);
			fscanf(fin, "%s", buffer);
			X = atof(buffer);
			fscanf(fin, "%c", &kk);
			temps = recursiuCookie(X, 2.0, 0.0);
			fprintf(fout, "Case #%d: %.7f\n", i+1, temps);

		}
		fclose(fin);
		fclose(fout);
	}
	return 0;
}