#include <stdio.h>
#include <stdlib.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int new_fgetc(FILE * stream);
 int main() 
{
	FILE * fin, *fout;
	fout = new_fopen("output.txt", "w");
	fin = new_fopen("A-small-attempt0.in", "r");
	int q, T, first, last, i;
	char c, A[2001];
	fscanf(fin, "%d", &T);
	c = new_fgetc(fin);
	for (q = 1; q <= T; q++) {
		first = 1000;
		last = 1000;
		c = new_fgetc(fin);
		A[1000] = c;
		while ((c = new_fgetc(fin)) != '\n' && c != EOF) {
			if (c >= A[first]) {
				A[first - 1] = c;
				first--;
			}
			
			else {
				A[last + 1] = c;
				last++;
			}
		}
		fprintf(fout, "Case #%d: ", q);
		for (i = first; i <= last; i++) {
			fprintf(fout, "%c", A[i]);
		}
		fprintf(fout, "\n");
	 }
	  new_fclose(fin);
	new_fclose(fout);
	return 0;
}

FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
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

int new_fclose(FILE * stream)
{
	return fclose(stream);
}
