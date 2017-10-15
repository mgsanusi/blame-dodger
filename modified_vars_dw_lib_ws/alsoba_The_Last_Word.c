#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
FILE *Fin;
FILE *Fout;
char aux[1001];
char n[1001];
char n[1001];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
char *new_strcpy(char *destination, const char *source);
char *new_strcat(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_bzero(void *s, int n);
void clear()
{
    int first_iteration;
    int tn;
    new_bzero(n, 1001);
    new_bzero(aux, 1001);
    new_bzero(n, 1001);
    fscanf(Fin, "%s", n);
    n[0] = n[0];
    for (tn = 1; tn < strlen(n); tn++) {
	char f[2];
	new_bzero(f, 2);
	f[0] = n[tn];
	if (n[tn] < n[0]) {
	    new_strcat(n, f);
	} else {
	    new_bzero(aux, 1001);
	    new_strcat(aux, f);
	    new_strcat(aux, n);
	    new_strcpy(n, aux);
	}
    }
    fprintf(Fout, "%s\n", n);
}

int Main(int argc, char *argv[])
{
    int first_iteration;
    char j;
    int total;
    int tn;
    Fin = new_fopen(argv[1], "r");
    Fout = new_fopen("out", "w");
    if ((Fin == 0) || (Fout == 0)) {
	printf("Fitxer out.\n");
    } else {
	fscanf(Fin, "%d", &total);
	fscanf(Fin, "%c", &j);
	for (tn = 0; tn < total; tn++) {
	    fprintf(Fout, "Case #%d: ", tn + 1);
	    clear();
	}
	new_fclose(Fin);
	new_fclose(Fout);
    }
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
char *new_strcpy(char *destination, const char *source);
char *new_strcat(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void new_bzero(void *s, int n)
{
    return bzero(s, n);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
char *new_strcpy(char *destination, const char *source);
char *new_strcat(char *destination, const char *source)
{
    return strcat(destination, source);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
char *new_strcpy(char *destination, const char *source)
{
    return strcpy(destination, source);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
