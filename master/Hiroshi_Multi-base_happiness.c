#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ	(512)
#define NR	(10)
#define MAX	(8192)

static int N;

void setup(void)
{
	char buf[SZ];

	fgets(buf, SZ, stdin);
	N = strtol(buf, NULL, 0);
}

static unsigned long cols[MAX];

unsigned long split_sq(unsigned long val, int base)
{
	unsigned long ret;
	int i;

	for (i = 0; val > 0; i++) {
		cols[i] = val % base;
		val /= base;
	}

	--i;
	for (ret = 0; i >= 0; i--)
		ret += cols[i] * cols[i];

	return ret;
}

static int t[100000];

static int check(unsigned long x, int *bases, int nr)
{
	unsigned long r, q;
	int i;

	for (i = 0; i < nr; i++) {
		memset(t, 0, sizeof(t));
		r = x;
		for (;;) {
			q = split_sq(r, bases[i]);
			if (q == r)
				return 0;
			if (q == 1)
				break;
			if (t[q])
				return 0;
			t[r] = 1;
			r = q;
		}
		if (q != 1)
			return 0;
	}

	return 1;
}

int solve_one(char *s)
{
	char *next;
	int bases[NR];
	int i, nr;
	unsigned long x, ret;

	for (i = 0; i < NR; i++) {
		int b = strtol(s, &next, 0);

		if (!b)
			break;
		bases[i] = b;
		s = next;
	}
	nr = i;

	for (x = 2; ; x++) {
		if (check(x, bases, nr))
			return x;
	}

	return 0;
}

void solve(void)
{
	char buf[SZ];
	int i;

	for (i = 0; i < N; i++) {
		int x;

		printf("Case #%d: ", i + 1);
		fgets(buf, SZ, stdin);
		x = solve_one(buf);
		printf("%d\n", x);
	}
}

int main(void)
{
	setup();
	solve();
	return 0;
}
