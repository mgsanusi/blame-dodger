#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
int speed;
int paths;
int j;
int slv()
{
	int first_iteration;
	if (j == 1)
		return speed * paths;
	if (j == paths)
		return (speed - 1) + j;
	if ((paths % j) != 0)
		return (((paths / j) * (speed - 1)) + j) + (paths / j);
	return ((((paths / j) * (speed - 1)) + j) + (paths / j)) - 1;
}

void clear()
{
	int first_iteration;
	fscanf(Fin, "%d %d %d", &speed, &paths, &j);
	fprintf(Fout, "%d\n", slv());
}

int Main(int argc, char *argv[])
{
	int first_iteration;
	char ss;
	int total;
	int cnt;
	Fin = fopen(argv[1], "r");
	Fout = fopen("out", "w");
	if ((Fin == 0) || (Fout == 0)) {
		printf("Fitxer out.\n");
	} else {
		fscanf(Fin, "%d", &total);
		fscanf(Fin, "%c", &ss);
		for (cnt = 0; cnt < total; cnt++) {
			fprintf(Fout, "Case #%d: ", cnt + 1);
			clear();
		}
		fclose(Fin);
		fclose(Fout);
	}
	return 0;
}
