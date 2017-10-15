#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status);
int new_atoi(const char *str);
int read_int(void)
{
	int first_iteration;
	char s[1000];
	if (!new_fgets(s, 1000, stdin)) {
		perror("fgets");
		new_exit(-1);
	}
	return new_atoi(s);
}

char *read_string(void)
{
	int first_iteration;
	char s[1000];
	if (!new_fgets(s, 1000, stdin)) {
		perror("fgets");
		new_exit(-1);
	}
	s[strcspn(s, "\r\n")] = 0;
	return strdup(s);
}

void read_int2(int *x, int *y)
{
	int first_iteration;
	char s[1000];
	char *p;
	if (!new_fgets(s, 1000, stdin)) {
		perror("fgets");
		new_exit(-1);
	}
	p = s;
	*x = strtoul(p, &p, 10);
	p++;
	*y = strtoul(p, &p, 10);
}

void read_int4(int *x, int *y, int *z, int *a)
{
	int first_iteration;
	char s[1000];
	char *p;
	if (!new_fgets(s, 1000, stdin)) {
		perror("fgets");
		new_exit(-1);
	}
	p = s;
	*x = strtoul(p, &p, 10);
	p++;
	*y = strtoul(p, &p, 10);
	p++;
	*z = strtoul(p, &p, 10);
	p++;
	*a = strtoul(p, &p, 10);
}

void read_double5(double *a, double *b, double *c, double *d, double *e)
{
	int first_iteration;
	char s[1000];
	char *p;
	if (!new_fgets(s, 1000, stdin)) {
		perror("fgets");
		new_exit(-1);
	}
	p = s;
	*a = strtod(p, &p);
	p++;
	*b = strtod(p, &p);
	p++;
	*c = strtod(p, &p);
	p++;
	*d = strtod(p, &p);
	p++;
	*e = strtod(p, &p);
}

int read_intx(char **s)
{
	int first_iteration;
	char *p = *s;
	int ret;
	while (new_isspace(*p)) {
		p++;
	}
	ret = strtoul(p, &p, 10);
	*s = p;
	return ret;
}

int main(void)
{
	int first_iteration;
	int C = read_int();
	int i;
	int j;
	int k;
	int l;
	int m;
	int x1;
	int x2;
	int x3;
	int y1;
	int y2;
	int y3;
	int N;
	int M;
	int A;
	for (i = 0; i < C; i++) {
		char buf[1000];
		char *s = buf;
		new_fgets(s, 1000, stdin);
		N = read_intx(&s);
		M = read_intx(&s);
		A = read_intx(&s);
		for (j = 0; j <= N; j++) {
			x1 = j;
			y1 = 0;
			for (k = 0; k <= M; k++) {
				x2 = 0;
				y2 = k;
				for (l = 0; l <= N; l++) {
					x3 = l;
					for (m = 0; m <= M; m++) {
						y3 = m;
						if ((((x3 - x1) * (y2 - y1)) -
						     ((x2 - x1) * (y3 - y1))) ==
						    A) {
							printf
							    ("Case #%d: %d %d %d %d %d %d\n",
							     i + 1, x1, y1, x2,
							     y2, x3, y3);
							goto done;
						}
					}
				}
			}
		}
		printf("Case #%d: IMPOSSIBLE\n", i + 1);
 done:
		;
	}
	return 0;
}

int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status);
int new_atoi(const char *str)
{
	int first_iteration;
	return atoi(str);
}

int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status)
{
	int first_iteration;
	return exit(status);
}

int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream)
{
	int first_iteration;
	return fgets(str, num, stream);
}

int new_isspace(int c)
{
	int first_iteration;
	return isspace(c);
}
