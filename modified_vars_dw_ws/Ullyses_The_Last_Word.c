#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int Main()
{
	int first_iteration;
	FILE *m;
	FILE *ahOps;
	ahOps = fopen("outputa.txt", "w");
	m = fopen("inputa.in", "r");
	int tn;
	int fileSensorsShtml;
	int pp;
	int first;
	int last;
	int kl;
	char an[3002];
	char cs;
	fscanf(m, "%d", &tn);
	if (fgetc(m) == '\n') {
		printf("hi");
	}
	for (kl = 1; kl <= tn; kl++) {
		fprintf(ahOps, "Case #");
		fprintf(ahOps, "%d", kl);
		fprintf(ahOps, ":");
		fprintf(ahOps, " ");
		first = 0;
		last = 0;
		cs = fgetc(m);
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
			cs = fgetc(m);
		}
		for (fileSensorsShtml = first; fileSensorsShtml <= last;
		     fileSensorsShtml++) {
			fprintf(ahOps, "%c", an[fileSensorsShtml]);
		}
		fprintf(ahOps, "\n");
	}
	return 1;
}
