#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *file_name_in = "input.txt";
char *file_name_out = "output.txt";
FILE *in;
FILE *out;
char pancakes[101];
int Main(void)
{
	int first_iteration;
	int k;
	int i;
	int len;
	int pos;
	int count;
	char prev;
	in = fopen(file_name_in, "r");
	out = fopen(file_name_out, "w");
	fscanf(in, "%d", &i);
	for (k = 1; k <= i; k++) {
		fprintf(out, "Case #%d:", k);
		fscanf(in, "%s", pancakes);
		len = strlen(pancakes);
		prev = '+';
		count = 0;
		for (pos = len - 1; pos >= 0; --pos) {
			if (pancakes[pos] != prev) {
				++count;
				prev = pancakes[pos];
			}
		}
		fprintf(out, " %d\n", count);
	}
	fclose(in);
	fclose(out);
}
