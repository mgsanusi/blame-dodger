#include <stdio.h>
#include <string.h>
#include <stddef.h>
int ti;
int cas;
int atB;
char str[10000];
char out[10000];
char outa[10000];
char outb[10000];
char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
char *new_strncpy(char *destination, const char *source, size_t num);
int Main()
{
	fscanf(stdin, "%d", &cas);
	for (ti = 1; ti <= cas; ++ti) {
		fprintf(stdout, "Case #%d: ", ti);
		fscanf(stdin, "%s", str);
		for (atB = 0; str[atB]; ++atB) {
			new_strncpy(outa, out, atB);
			outa[atB] = str[atB];
			outa[atB + 1] = 0;
			new_strncpy(outb + 1, out, atB);
			outb[0] = str[atB];
			outb[atB + 1] = 0;
			if (strcmp(outa, outb) >= 0) {
				new_strcpy(out, outa);
			} else {
				new_strcpy(out, outb);
			}
		}
		fprintf(stdout, "%s\n", out);
	}
}

char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
char *new_strncpy(char *destination, const char *source, size_t num)
{
	return strncpy(destination, source, num);
}

char *new_strcpy(char *destination, const char *source)
{
	return strcpy(destination, source);
}
