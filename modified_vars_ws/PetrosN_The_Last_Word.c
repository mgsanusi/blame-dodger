#include <stdio.h>
#include <stdlib.h>
int Main()
{
	FILE *Fin;
	FILE *Fout;
	Fout = fopen("output.txt", "w");
	Fin = fopen("A-small-attempt0.in", "r");
	int length;
	int length;
	int first;
	int last;
	int i;
	char j;
	char io[2001];
	fscanf(Fin, "%d", &length);
	j = fgetc(Fin);
	for (length = 1; length <= length; length++) {
		first = 1000;
		last = 1000;
		j = fgetc(Fin);
		io[1000] = j;
		while (((j = fgetc(Fin)) != '\n') && (j != EOF)) {
			if (j >= io[first]) {
				io[first - 1] = j;
				first--;
			} else {
				io[last + 1] = j;
				last++;
			}
		}
		fprintf(Fout, "Case #%d: ", length);
		for (i = first; i <= last; i++) {
			fprintf(Fout, "%c", io[i]);
		}
		fprintf(Fout, "\n");
	}
	fclose(Fin);
	fclose(Fout);
	return 0;
}
