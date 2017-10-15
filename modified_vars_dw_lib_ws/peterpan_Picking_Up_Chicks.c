#include <stdio.h>
#include <string.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_strncmp(const char *str1, const char *str2, int num);
int Main(int argc, char *argv[])
{
	int first_iteration;
	FILE *Fin;
	FILE *Fout;
	int caseIndex;
	int j;
	int tcase;
	int a;
	int cs;
	int st;
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
	fscanf(Fin, "%d", &a);
	for (tcase = 1; tcase <= a; tcase++) {
		fscanf(Fin, "%d", &cs);
		fscanf(Fin, "%d", &st);
		for (caseIndex = 0; caseIndex < cs; caseIndex++)
			fscanf(Fin, "%s", dirs[caseIndex]);
		for (caseIndex = 0; caseIndex < st; caseIndex++)
			fscanf(Fin, "%s", dirs[caseIndex + cs]);
		counter = 0;
		for (caseIndex = cs; caseIndex < (cs + st); caseIndex++) {
			pos = 0;
			j = 0;
			while (dirs[caseIndex][pos]) {
				pos++;
				while (dirs[caseIndex][pos]
				       && (dirs[caseIndex][pos] != '/'))
					pos++;
				while (j < caseIndex) {
					if ((new_strncmp
					     (dirs[caseIndex], dirs[j],
					      pos) == 0)
					    && ((dirs[j][pos] == '/')
						|| (dirs[j][pos] == 0)))
						break;
					j++;
				}
				if (j == caseIndex) {
					while (dirs[caseIndex][pos]) {
						if (dirs[caseIndex][pos++] ==
						    '/')
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
int new_strncmp(const char *str1, const char *str2, int num)
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
