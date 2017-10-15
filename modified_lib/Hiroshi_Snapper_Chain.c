#include <stdio.h>

static int T;

#define BUFSZ	(512)
char * new_fgets(char *str, int num, FILE *stream);


void setup(void)
{
	char buf[BUFSZ];

	new_fgets(buf, BUFSZ, stdin);
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
		new_fgets(buf, BUFSZ, stdin);
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

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}