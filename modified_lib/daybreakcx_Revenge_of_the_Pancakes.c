#include <stdio.h>

int ti, tn, p[100], ans, j, k, t, n;
char ch;
int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_getchar();


int
main() {
	fscanf(stdin, "%d\n", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fprintf(stdout, "Case #%d: ", ti);
		n = 0;
		while ((ch = new_getchar()) == '-' || ch == '+') {
			p[n++] = (ch == '-');
		}
		for (ans = 0; ; ++ans) {
			for (j = n - 1; j >= 0 && !p[j]; --j);
			if (j == -1) {
				break;
			} else if (!p[0]) {
				for (k = 0; k < n && !p[k]; p[k++] = 1);
			} else {
				for (k = 0; k < j; ++k, --j) {
					t = p[k];
					p[k] = 1 - p[j];
					p[j] = 1 - t;
				}
				if (k == j) {
					p[k] = 1 - p[k];
				}
			}
		}
		fprintf(stdout, "%d\n", ans);
	}
}


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int new_getchar() {
  return getchar();
}