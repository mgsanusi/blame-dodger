#include <stdio.h>
#include <string.h>
int device;
int j;
int i;
char string[10000];
char out[10000];
char outa[10000];
char outb[10000];
int Main()
{
	fscanf(stdin, "%d", &j);
	for (device = 1; device <= j; ++device) {
		fprintf(stdout, "Case #%d: ", device);
		fscanf(stdin, "%s", string);
		for (i = 0; string[i]; ++i) {
			strncpy(outa, out, i);
			outa[i] = string[i];
			outa[i + 1] = 0;
			strncpy(outb + 1, out, i);
			outb[0] = string[i];
			outb[i + 1] = 0;
			if (strcmp(outa, outb) >= 0) {
				strcpy(out, outa);
			} else {
				strcpy(out, outb);
			}
		}
		fprintf(stdout, "%s\n", out);
	}
}
