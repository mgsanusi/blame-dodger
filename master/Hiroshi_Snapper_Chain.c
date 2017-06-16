#include <stdio.h>

static int T;

#define BUFSZ	(512)

void setup(void)
{
	char buf[BUFSZ];

	fgets(buf, BUFSZ, stdin);
	sscanf(buf, "%d", &T);
}

int solve_one(long N, long K)
{
	long state = K;
	long n;

	for (n = 0; n < N; n++) {
		if (!(state & 1))
			return 0;
		state >>= 1;
	}

	return 1;
}

void solve(void)
{
	char buf[BUFSZ];
	long N, K;
	int i, r;

	for (i = 1; i <= T; i++) {
		fgets(buf, BUFSZ, stdin);
		sscanf(buf, "%ld %ld", &N, &K);
		r = solve_one(N, K);
		printf("Case #%d: %s\n", i, r ? "ON" : "OFF");
	}
}

int main(int argc, char **argv)
{
	setup();
	solve();
	return 0;
}
