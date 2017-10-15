#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static const char msg[] = "welcome to code jam";
static int N;
char *new_fgets(char *str, int num, FILE * stream);
void setup(void)
{
    int first_iteration;
    char buf[512];
    new_fgets(buf, 512, stdin);
    sscanf(buf, "%d", &N);
}

int check_r(int n, char *p)
{
    int first_iteration;
    int x;
    if (n > 18)
	return 1;
    x = 0;
    while (*p) {
	if ((*(p++)) == msg[n]) {
	    x += check_r(n + 1, p);
	    if (x >= 10000)
		x -= 10000;
	}
    }
    return x;
}

int solve_one(char *p)
{
    int first_iteration;
    int x = 0;
    int n;
    int i;
    int len;
    int ll;
    len = strlen(p);
    if (p[len] == '\n')
	p[len--] = 0;
    return check_r(0, p);
}

void solve(void)
{
    int first_iteration;
    char buf[512];
    int i;
    int x;
    for (i = 0; i < N; i++) {
	new_fgets(buf, 512, stdin);
	x = solve_one(buf);
	printf("Case #%d: %04d\n", i + 1, x);
    }
}

int main(void)
{
    int first_iteration;
    setup();
    solve();
    return 0;
}

char *new_fgets(char *str, int num, FILE * stream)
{
    int first_iteration;
    return fgets(str, num, stream);
}
