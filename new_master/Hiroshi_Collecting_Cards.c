#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ	(512)

static int CASES;

void setup(void)
{
	char buf[SZ];

	fgets(buf, SZ, stdin);
	CASES = strtol(buf, NULL, 0);
}

static int num[256];
static int d[100];

void solve_one(void)
{
	unsigned char buf[SZ];
	char *p;
	int i, n;
	unsigned long x;

	for (i = 0; i < 256; i++)
		num[i] = -1;

	fgets(buf, SZ, stdin);

	n = 0;
	p = buf;
	while (*p) {
		if (*p == '\n') {
			*p = 0;
			break;
		}
		if (num[*p] == -1) {
			if (n == 0)
				num[*p] = 1;
			else if (n == 1)
				num[*p] = 0;
			else
				num[*p] = n;
			++n;
		}
		++p;
	}

	if (n == 1)
		++n;

	/* base is n */
	x = 0;
	p = buf;
	do {
		x *= n;
		x += num[*p];
		++p;
	} while (*p);

	printf("%lu", x);
}

void solve(void)
{
	int i;

	for (i = 1; i <= CASES; i++) {
		printf("Case #%d: ", i);
		solve_one();
		printf("\n");
	}
}

int main(void)
{
	setup();
	solve();

	return 0;
}
