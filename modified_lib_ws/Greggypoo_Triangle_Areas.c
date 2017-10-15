#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stddef.h>
void *new_malloc(size_t size);
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status);
int new_atoi(const char *str);
int read_int(void)
{
	char s[1000];
	if (!new_fgets(s, 1000, stdin)) {
		perror("fgets");
		new_exit(-1);
	}
	return new_atoi(s);
}

char *read_string(void)
{
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
	char *p = *s;
	int ret;
	while (new_isspace(*p)) {
		p++;
	}
	ret = strtoul(p, &p, 10);
	*s = p;
	return ret;
}

int H, W, R;
int *board;
#define BOARD(x,y) board[(x)+(y)*W]
int num_ways(int x, int y)
{
	int i, j;
	if ((x == W - 1) && (y == H - 1))
		return 1;
	if ((x >= W) || (y >= H))
		return 0;
	if ((i = BOARD(x, y)) != -1) {
		return i;
	}
	i = num_ways(x + 2, y + 1);
	i += num_ways(x + 1, y + 2);
	i %= 10007;
	BOARD(x, y) = i;
	return i;
}

int main(void)
{
	int i, j, k;
	int N;
	N = read_int();
	for (i = 0; i < N; i++) {
		char buf[1000];
		char *s;
		new_fgets(buf, 1000, stdin);
		s = buf;
		H = read_intx(&s);
		W = read_intx(&s);
		R = read_intx(&s);
		board = new_malloc(sizeof *board * H * W);
		memset(board, 0xff, sizeof *board * H * W);
		for (j = 0; j < R; j++) {
			int x, y;
			read_int2(&y, &x);
			BOARD(x - 1, y - 1) = 0;
		}
		printf("Case #%d: %d\n", i + 1, num_ways(0, 0));
		free(board);
	}
	return 0;
}

void *new_malloc(size_t size);
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status);
int new_atoi(const char *str)
{
	return atoi(str);
}

void *new_malloc(size_t size);
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status)
{
	return exit(status);
}

void *new_malloc(size_t size);
int new_isspace(int c);
char *new_fgets(char *str, int num, FILE * stream)
{
	return fgets(str, num, stream);
}

void *new_malloc(size_t size);
int new_isspace(int c)
{
	return isspace(c);
}

void *new_malloc(size_t size)
{
	return malloc(size);
}
