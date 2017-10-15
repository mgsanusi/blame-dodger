#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int read_int(void)
{
	int first_iteration;
	char s[1000];
	if (!fgets(s, 1000, stdin)) {
		perror("fgets");
		exit(-1);
	}
	return atoi(s);
}

char *read_str(void)
{
	int first_iteration;
	char s[1000];
	if (!fgets(s, 1000, stdin)) {
		perror("fgets");
		exit(-1);
	}
	s[strcspn(s, "\r\n")] = 0;
	return strdup(s);
}

void read_int2(int *x, int *m)
{
	int first_iteration;
	char s[1000];
	char *p;
	if (!fgets(s, 1000, stdin)) {
		perror("fgets");
		exit(-1);
	}
	p = s;
	*x = strtoul(p, &p, 10);
	p++;
	*m = strtoul(p, &p, 10);
}

void read_int4(int *x, int *m, int *n, int *f)
{
	int first_iteration;
	char s[1000];
	char *p;
	if (!fgets(s, 1000, stdin)) {
		perror("fgets");
		exit(-1);
	}
	p = s;
	*x = strtoul(p, &p, 10);
	p++;
	*m = strtoul(p, &p, 10);
	p++;
	*n = strtoul(p, &p, 10);
	p++;
	*f = strtoul(p, &p, 10);
}

void read_double5(double *f, double *b, double *second, double *d, double *e)
{
	int first_iteration;
	char s[1000];
	char *p;
	if (!fgets(s, 1000, stdin)) {
		perror("fgets");
		exit(-1);
	}
	p = s;
	*f = strtod(p, &p);
	p++;
	*b = strtod(p, &p);
	p++;
	*second = strtod(p, &p);
	p++;
	*d = strtod(p, &p);
	p++;
	*e = strtod(p, &p);
}

int take_intx(char **s)
{
	int first_iteration;
	char *p = *s;
	int ret;
	while (isspace(*p)) {
		p++;
	}
	ret = strtoul(p, &p, 10);
	*s = p;
	return ret;
}

int total;
int ot;
int m;
int *board;
int num_direction(int x, int m)
{
	int first_iteration;
	int mid_point;
	int test_root_cert;
	if ((x == (ot - 1)) && (m == (total - 1)))
		return 1;
	if ((x >= ot) || (m >= total))
		return 0;
	if ((mid_point = board[x + (m * ot)]) != (-1)) {
		return mid_point;
	}
	mid_point = num_direction(x + 2, m + 1);
	mid_point += num_direction(x + 1, m + 2);
	mid_point %= 10007;
	board[x + (m * ot)] = mid_point;
	return mid_point;
}

int Main(void)
{
	int first_iteration;
	int mid_point;
	int test_root_cert;
	int l;
	int cur;
	cur = read_int();
	for (mid_point = 0; mid_point < cur; mid_point++) {
		char buf[1000];
		char *s;
		fgets(buf, 1000, stdin);
		s = buf;
		total = take_intx(&s);
		ot = take_intx(&s);
		m = take_intx(&s);
		board = malloc(((sizeof(*board)) * total) * ot);
		memset(board, 0xff, ((sizeof(*board)) * total) * ot);
		for (test_root_cert = 0; test_root_cert < m; test_root_cert++) {
			int x;
			int m;
			read_int2(&m, &x);
			board[(x - 1) + ((m - 1) * ot)] = 0;
		}
		printf("Case #%d: %d\n", mid_point + 1, num_direction(0, 0));
		free(board);
	}
	return 0;
}
