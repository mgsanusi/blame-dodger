#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
int speed;
int paths;
int j;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
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
    Fin = new_fopen(argv[1], "r");
    Fout = new_fopen("out", "w");
    if ((Fin == 0) || (Fout == 0)) {
	printf("Fitxer out.\n");
    } else {
	fscanf(Fin, "%d", &total);
	fscanf(Fin, "%c", &ss);
	for (cnt = 0; cnt < total; cnt++) {
	    fprintf(Fout, "Case #%d: ", cnt + 1);
	    clear();
	}
	new_fclose(Fin);
	new_fclose(Fout);
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
