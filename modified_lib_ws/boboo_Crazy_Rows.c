#include <stdio.h>
#include <string.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream);
int main()
{
	FILE * fin = new_fopen("row.in", "r");
	FILE * fout = new_fopen("row.out", "w");
	int t, i, j, k, n, m, test, ans, a[50];
	char c[50];
	fscanf(fin, "%d", &test);
	for (t = 1; t <= test; t++) {
		fscanf(fin, "%d\n", &n);
		for (i = 1; i <= n; i++) {
			new_fgets(c, 50, fin);
			a[i] = 0;
			for (j = strlen(c) - 2; (j >= 0) && (c[j] == '0');
			      j--, a[i]++) ;
		}
		for (i = n - 1; i >= 0; i--) {
			for (j = 1; j <= n; j++)
				if (a[j] >= i) {
					a[j] = -i;
					break;
				}
		}
		ans = 0;
		for (i = 1; i < n; i++)
			for (j = i + 1; j <= n; j++)
				if (a[j] < a[i])
					ans++;
		fprintf(fout, "Case #%d: %d\n", t, ans);
	}
	return 0;
}

FILE * new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream)
{
	return fgets(str, num, stream);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}
