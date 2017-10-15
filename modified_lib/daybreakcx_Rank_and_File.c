#include <stdio.h>
#include <string.h>

#include <stddef.h>

int ti, tn, i;
char str[10000], out[10000], outa[10000], outb[10000];
char * new_strcpy(char *destination, const char *source);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

char * new_strncpy(char *destination, const char* source, size_t num);


int
main() {
	fscanf(stdin, "%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fprintf(stdout, "Case #%d: ", ti);
		fscanf(stdin, "%s", str);
		for (i = 0; str[i]; ++i) {
			new_strncpy(outa, out, i);
			outa[i] = str[i];
			outa[i + 1] = 0;
			new_strncpy(outb + 1, out, i);
			outb[0] = str[i];
			outb[i + 1] = 0;
			if (strcmp(outa, outb) >= 0) {
				new_strcpy(out, outa);
			} else {
				new_strcpy(out, outb);
			}
		}
		fprintf(stdout, "%s\n", out);
	}
}


char * new_strcpy(char *destination, const char *source);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

char * new_strncpy(char *destination, const char* source, size_t num) {
  return strncpy(destination, source, num);
}
char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}