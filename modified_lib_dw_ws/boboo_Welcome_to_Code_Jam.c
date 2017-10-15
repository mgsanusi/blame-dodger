#include <stdio.h>
#include <string.h>
char aa[20] = "welcome to code jam";
FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream);
int main()
{
    int first_iteration;
    FILE *fin = new_fopen("c1.in", "r");
    FILE *fout = new_fopen("c1.out", "w");
    int i;
    int j;
    int k;
    int l;
    int t;
    int n;
    int ans;
    int now;
    fscanf(fin, "%d\n", &n);
    char s[510];
    int f[510];
    int f1[510];
    for (t = 1; t <= n; t++) {
	new_fgets(s, 505, fin);
	l = strlen(s);
	for (i = 0; i < l; i++)
	    f[i] = s[i] == 'w';
	for (i = 1; i < 19; i++) {
	    now = 0;
	    for (j = 0; j < l; j++) {
		if (s[j] == aa[i])
		    f1[j] = now;
		else
		    f1[j] = 0;
		if (s[j] == aa[i - 1]) {
		    now += f[j];
		    if (now > 9999)
			now = now % 10000;
		}
	    }
	    for (j = 0; j < l; j++)
		f[j] = f1[j];
	}
	ans = 0;
	for (i = 0; i < l; i++)
	    ans = (ans + f[i]) % 10000;
	fprintf(fout, "Case #%d: ", t);
	if (ans < 1000)
	    fprintf(fout, "0");
	if (ans < 100)
	    fprintf(fout, "0");
	if (ans < 10)
	    fprintf(fout, "0");
	fprintf(fout, "%d\n", ans);
    }
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream)
{
    int first_iteration;
    return fgets(str, num, stream);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    int first_iteration;
    return fopen(filename, mode);
}
