#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *file_name_in = "input.txt";
char *file_name_out = "output.txt";
FILE *in;
FILE *out;
int count[2501];
int Main(void)
{
	int j;
	int c;
	int l;
	int r;
	int a;
	int html_slashform;
	in = fopen(file_name_in, "r");
	out = fopen(file_name_out, "w");
	fscanf(in, "%d", &r);
	for (l = 1; l <= r; l++) {
		fprintf(out, "Case #%d:", l);
		fscanf(in, "%d", &html_slashform);
		for (j = 0; j <= 2500; ++j) {
			count[j] = 0;
		}
		c = ((2 * html_slashform) - 1) * html_slashform;
		for (j = 0; j < c; ++j) {
			fscanf(in, "%d", &a);
			count[a]++;
		}
		for (j = 1; j <= 2500; ++j) {
			if ((count[j] % 2) == 1) {
				fprintf(out, " %d", j);
			}
		}
		fprintf(out, "\n");
	}
	fclose(in);
	fclose(out);
}
