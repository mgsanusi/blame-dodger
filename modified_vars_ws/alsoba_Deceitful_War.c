#include <stdio.h>
#include <stdlib.h>
int c;
int p;
int c;
int Main(int argc, char *argv[])
{
    FILE *Fin;
    FILE *Fout;
    char ans2;
    int total;
    int vz;
    int i_t;
    int x;
    int sum;
    Fin = fopen(argv[1], "r");
    Fout = fopen("out", "w");
    if ((Fin == 0) || (Fout == 0)) {
	printf("Fitxer out.\n");
    } else {
	fscanf(Fin, "%d", &total);
	fscanf(Fin, "%c", &ans2);
	for (vz = 0; vz < total; vz++) {
	    fscanf(Fin, "%d", &c);
	    fscanf(Fin, "%d", &p);
	    fscanf(Fin, "%d", &c);
	    sum = 0;
	    for (x = 0; x < c; x++) {
		for (i_t = 0; i_t < p; i_t++) {
		    if ((i_t & x) < c) {
			sum++;
		    }
		}
	    }
	    fprintf(Fout, "Case #%d: %d\n", vz + 1, sum);
	}
	fclose(Fin);
	fclose(Fout);
    }
    return 0;
}
