#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ	(512)
#define MAX	(500)
static const char msg[] = "welcome to code jam";
			/* 0123456789012345678 */
static int N;
void setup(void)
{
	char buf[SZ];
	fgets(buf, SZ, stdin);
	sscanf(buf, "%d", &N);
}

int check_r(int n, char *p)
{
	int x;
	if (n > 18)
		return 1;
	x = 0;
	while (*p) {
		if (*p++ == msg[n]) {
			x += check_r(n + 1, p);
			if (x >= 10000)
				x -= 10000;
		}
	}
	return x;
}

int solve_one(char *p)
{
	int x = 0;
	int n, i, len, ll;
	len = strlen(p);
	if (p[len] == '\n')
		p[len--] = 0;
	return check_r(0, p);
}

void solve(void)
{
	char buf[SZ];
	int i, x;
	for (i = 0; i < N; i++) {
		fgets(buf, SZ, stdin);
		x = solve_one(buf);
		printf("Case #%d: %04d\n", i + 1, x);
	}
}

int main(void)
{
	setup();
	solve();
	return 0;
}
