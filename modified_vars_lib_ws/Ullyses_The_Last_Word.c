#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int new_fgetc(FILE * stream);
int Main()
{
	FILE *m;
	FILE *ahOps;
	ahOps = new_fopen("outputa.txt", "w");
	m = new_fopen("inputa.in", "r");
	int tn;
	int fileSensorsShtml;
	int pp;
	int first;
	int last;
	int kl;
	char an[3002];
	char cs;
	fscanf(m, "%d", &tn);
	if (new_fgetc(m) == '\n') {
		printf("hi");
	}
	for (kl = 1; kl <= tn; kl++) {
		fprintf(ahOps, "Case #");
		fprintf(ahOps, "%d", kl);
		fprintf(ahOps, ":");
		fprintf(ahOps, " ");
		first = 0;
		last = 0;
		cs = new_fgetc(m);
		while (cs != '\n') {
			if (first == 0) {
				an[1001] = cs;
				first = 1001;
				last = 1001;
			} else {
				if (cs >= an[first]) {
					first = first - 1;
					an[first] = cs;
				} else {
					last = last + 1;
					an[last] = cs;
				}
			}
			cs = new_fgetc(m);
		}
		for (fileSensorsShtml = first; fileSensorsShtml <= last;
		     fileSensorsShtml++) {
			fprintf(ahOps, "%c", an[fileSensorsShtml]);
		}
		fprintf(ahOps, "\n");
	}
	return 1;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int new_fgetc(FILE * stream)
{
	return fgetc(stream);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}
