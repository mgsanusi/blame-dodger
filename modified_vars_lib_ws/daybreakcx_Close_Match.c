#include <stdio.h>
#include <string.h>
int j;
int b3;
int fx;
int t;
int n;
int size;
int y;
int a[30];
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int Main()
{
	fscanf(stdin, "%d", &b3);
	for (j = 1; j <= b3; ++j) {
		fprintf(stdout, "Case #%d:", j);
		fscanf(stdin, "%d", &n);
		memset(a, 0, sizeof(a));
		for (fx = (t = 0); fx < n; ++fx) {
			fscanf(stdin, "%d", &a[fx]);
			t += a[fx];
		}
		while (t > 0) {
			for (size = (fx = 0); fx < 26; ++fx) {
				if (a[fx] && (a[fx] > a[size])) {
					size = fx;
				}
			}
			--a[size];
			--t;
			for (y = (fx = 0); fx < 26; ++fx) {
				if (a[fx] && (a[fx] > a[y])) {
					y = fx;
				}
			}
			if (a[y]) {
				--a[y];
				--t;
				for (fx = 0; fx < 26; ++fx)
					if (a[fx] > (t >> 1)) {
						break;
					}
				if (fx == 26) {
					fprintf(stdout, " %c%c", 'A' + size,
						'A' + y);
				} else {
					fprintf(stdout, " %c", 'A' + size);
					++a[y];
					++t;
				}
			} else {
				fprintf(stdout, " %c", 'A' + size);
			}
		}
		fprintf(stdout, "\n");
	}
}
