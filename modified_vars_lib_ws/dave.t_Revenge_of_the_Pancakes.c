#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *file_name_in = "input.txt";
char *file_name_out = "output.txt";
FILE *in;
FILE *out;
char pancakes[101];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int Main(void)
{
	int k;
	int i;
	int len;
	int pos;
	int count;
	char prev;
	in = new_fopen(file_name_in, "r");
	out = new_fopen(file_name_out, "w");
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
	new_fclose(in);
	new_fclose(out);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	return fclose(stream);
}
