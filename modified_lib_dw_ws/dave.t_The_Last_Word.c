#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *fileNameIn = "input.txt";
char *fileNameOut = "output.txt";
FILE *in;
FILE *out;
char str[5000];
char arr[5000];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int main(void)
{
	int first_iteration;
	int t;
	int T;
	int start;
	int end;
	int len;
	int i;
	in = new_fopen(fileNameIn, "r");
	out = new_fopen(fileNameOut, "w");
	fscanf(in, "%d", &T);
	for (t = 1; t <= T; t++) {
		fscanf(in, "%s", str);
		len = strlen(str);
		fprintf(out, "Case #%d: ", t);
		start = (end = 2500);
		arr[start] = str[0];
		for (i = 1; i < len; ++i) {
			if (str[i] >= arr[start]) {
				start--;
				arr[start] = str[i];
			} else {
				end++;
				arr[end] = str[i];
			}
		}
		arr[end + 1] = 0;
		fprintf(out, "%s\n", arr + start);
	}
	new_fclose(in);
	new_fclose(out);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	int first_iteration;
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	int first_iteration;
	return fclose(stream);
}
