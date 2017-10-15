#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L	(15)
#define D	(5000)
#define N	(500)
static int LL, DD, NN;
static char *words[D];
#define SZ	(512)
void setup(void)
{
    char buf[SZ];
    int i;
    fgets(buf, SZ, stdin);
    sscanf(buf, "%d %d %d", &LL, &DD, &NN);
    for (i = 0; i < DD; i++) {
	fgets(buf, SZ, stdin);
	words[i] = strdup(buf);
    }
}

int check_word(int d, char *l[L])
{
    char *w;
    int i, n;
    w = words[d];
    for (i = 0; i < LL; i++) {
	if (*l[i] == '(') {
	    n = 0;
	    while (l[i][n] != w[i]) {
		if (l[i][n] == ')')
		    return 0;
		++n;
	    }
	} else if (*l[i] != w[i])
	    return 0;
    }
    return 1;			/* Hit */
}

int solve_one(char *p)
{
    int x = 0, i;
    char *letter[L];
    i = 0;
    while (*p) {
	if (*p == '\n')
	    break;
	if (*p == '(') {
	    letter[i++] = p;
	    while (*p != ')')
		++p;
	} else {
	    letter[i++] = p;
	}
	++p;
    }
    if (i != LL) {
	fprintf(stderr, "BUG!\n");
	exit(1);
    }
    x = 0;
    for (i = 0; i < DD; i++)
	x += check_word(i, letter);
    return x;
}

void solve(void)
{
    char buf[512];
    int i, x;
    for (i = 0; i < NN; i++) {
	fgets(buf, SZ, stdin);
	x = solve_one(buf);
	printf("Case #%d: %d\n", i + 1, x);
    }
}

int main(int argc, char **argv)
{
    setup();
    solve();
    return 0;
}
