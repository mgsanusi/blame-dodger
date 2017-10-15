#include <stdio.h>
#include <string.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_strncmp(const char *str1, const char *str2, size_t num);
int Main(int argc, char *argv[])
{
    FILE *Fin;
    FILE *Fout;
    int speed;
    int idx;
    int tcase;
    int ans1;
    int n;
    int cc;
    int counter;
    int pos;
    char dirs[200][102];
    if (argc > 1)
	Fin = new_fopen(argv[1], "r");
    else
	Fin = new_fopen("fixit.in", "r");
    if (!Fin)
	return 1;
    if (argc > 2)
	Fout = new_fopen(argv[2], "w");
    else
	Fout = new_fopen("fixit.out", "w");
    if (!Fout) {
	new_fclose(Fin);
	return 1;
    }
    fscanf(Fin, "%d", &ans1);
    for (tcase = 1; tcase <= ans1; tcase++) {
	fscanf(Fin, "%d", &n);
	fscanf(Fin, "%d", &cc);
	for (speed = 0; speed < n; speed++)
	    fscanf(Fin, "%s", dirs[speed]);
	for (speed = 0; speed < cc; speed++)
	    fscanf(Fin, "%s", dirs[speed + n]);
	counter = 0;
	for (speed = n; speed < (n + cc); speed++) {
	    pos = 0;
	    idx = 0;
	    while (dirs[speed][pos]) {
		pos++;
		while (dirs[speed][pos] && (dirs[speed][pos] != '/'))
		    pos++;
		while (idx < speed) {
		    if ((new_strncmp(dirs[speed], dirs[idx], pos) == 0)
			&& ((dirs[idx][pos] == '/')
			    || (dirs[idx][pos] == 0)))
			break;
		    idx++;
		}
		if (idx == speed) {
		    while (dirs[speed][pos]) {
			if (dirs[speed][pos++] == '/')
			    counter++;
		    }
		    counter++;
		    break;
		}
	    }
	}
	fprintf(Fout, "Case #%d: %d\n", tcase, counter);
    }
    new_fclose(Fin);
    new_fclose(Fout);
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_strncmp(const char *str1, const char *str2, size_t num)
{
    return strncmp(str1, str2, num);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
