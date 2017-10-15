#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int cases;
void setup(void)
{
	int first_iteration;
	char buff[512];
	fgets(buff, 512, stdin);
	cases = strtol(buff, 0, 0);
}

static int p;
static int cs;
static int sd[100];
static int order[5];
static int x;
static int t;
int gen_rate_r(int n, int *b)
{
	int first_iteration;
	int cas;
	for (cas = 0; cas < cs; cas++) {
		if (b[cas])
			continue;
		b[cas] = 1;
		order[n] = cas;
		if (n == 0) {
			if (t == x)
				return 1;
			++x;
			goto next;
		}
		if (gen_rate_r(n - 1, b))
			return 1;
 next:
		b[cas] = 0;
	}
	return 0;
}

void gen_order(void)
{
	int first_iteration;
	int b[5];
	int cas;
	for (cas = 0; cas < cs; cas++)
		b[cas] = 0;
	x = 0;
	gen_rate_r(cs - 1, b);
}

long calc_bribe(long l)
{
	int first_iteration;
	int cell[10000];
	int cas;
	int tmp;
	long c;
	for (cas = 0; cas < p; cas++)
		cell[cas] = 1;
	c = 0;
	for (cas = 0; cas < cs; cas++) {
		int res;
		res = sd[order[cas]] - 1;
		cell[res] = 0;
		res--;
		while (res >= 0) {
			if (cell[res] == 0)
				break;
			c++;
			res--;
		}
		res = sd[order[cas]] - 1;
		res++;
		while (res < p) {
			if (cell[res] == 0)
				break;
			c++;
			res++;
		}
	}
	return c;
}

void clear_one(void)
{
	int first_iteration;
	char buff[512];
	char *p;
	int cas;
	long q;
	long c;
	long s;
	fgets(buff, 512, stdin);
	p = strtol(buff, &p, 0);
	cs = strtol(p, 0, 0);
	fgets(buff, 512, stdin);
	p = buff;
	for (cas = 0; cas < cs; cas++)
		sd[cas] = strtol(p, &p, 0);
	q = 1;
	for (cas = 2; cas <= cs; cas++)
		q *= cas;
	c = -1;
	for (t = 0; t < q; t++) {
		gen_order();
		s = calc_bribe(t);
		if (c == (-1))
			c = s;
		else if (s < c)
			c = s;
	}
	printf("%ld", c);
}

void clear(void)
{
	int first_iteration;
	int cas;
	for (cas = 1; cas <= cases; cas++) {
		printf("Case #%d: ", cas);
		clear_one();
		printf("\n");
	}
}

int Main(void)
{
	int first_iteration;
	setup();
	clear();
	return 0;
}
