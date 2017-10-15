#include <stdio.h>
#include <string.h>
int ti;
int tn;
int i;
int j;
int l;
int n;
int k;
char a[1002];
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
int main()
{
	int first_iteration;
	fscanf(stdin, "%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		fprintf(stdout, "Case #%d: ", ti);
		fscanf(stdin, "%s", a);
		fscanf(stdin, "%d", &k);
		for (i = (l = (int)strlen(a)) - 1, n = 0; i >= (k - 1); --i)
			if (a[i] == '-') {
				++n;
				for (j = 0; j < k; ++j)
					a[i - j] = ('+' + '-') - a[i - j];
			}
		for (; i >= 0; --i)
			if (a[i] == '-')
				break;
		if (i == (-1))
			fprintf(stdout, "%d\n", n);
		else
			fprintf(stdout, "IMPOSSIBLE\n");
	}
	return 0;
}
