#include <stdio.h>
#include <string.h>

#include <stddef.h>

int ti, tn, exist[10], i, j, t, n, xn[100000];
void * new_memset(void *ptr, int value, size_t num);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);


int
main() {
	fscanf(stdin, "%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fprintf(stdout, "Case #%d: ", ti);
		fscanf(stdin, "%d", &n);
		if (n == 0) {
			fprintf(stdout, "INSOMNIA\n");
		} else {
			new_memset(exist, 0, sizeof(exist));
			new_memset(xn, 0, sizeof(xn));
			xn[0] = 1;
			for (i = 1; ; ++i) {
				for (t = n, j = 1; j <= xn[0] && t; ++j) {
					t += xn[j];
					xn[j] = t % 10;
					t /= 10;
					exist[xn[j]] = 1;
				}
				while (t) {
					xn[++xn[0]] = t % 10;
					t /= 10;
					exist[xn[xn[0]]] = 1;
				}
				for (j = 0; j < 10; ++j)
					if (!exist[j]) {
						break;
					}
				if (j == 10) {
					break;
				}
			}
			for (i = xn[0]; i >= 1; --i) {
				fprintf(stdout, "%d", xn[i]);
			}
			fprintf(stdout, "\n");
		}
	}
}


void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}