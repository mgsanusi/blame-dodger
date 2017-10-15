#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
int n;
int p;
int b;
int res;
char casos[20];
char fans[20];
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_read(int fd, void *buf, int count);
int new_abs(int x);
void backtrack(int tt, int x_op, int x, int s)
{
    int first_iteration;
    if (x_op == n) {
	if (tt == 0)
	    backtrack(1, 0, x, s);
	else {
	    int z = new_abs(x - s);
	    if (z < res)
		res = z, p = x, b = s;
	    else if ((z == res) && (x < p))
		p = x, b = s;
	    else if (((z == res) && (x == p)) && (s < b))
		b = s;
	}
	return;
    }
    int k;
    int s;
    for (k = 0; k < 10; k++) {
	if (tt == 0) {
	    s = k;
	    if (casos[x_op] != '?')
		s = casos[x_op] - 48;
	    backtrack(tt, x_op + 1, (x * 10) + s, s);
	} else {
	    s = k;
	    if (fans[x_op] != '?')
		s = fans[x_op] - 48;
	    backtrack(tt, x_op + 1, x, (s * 10) + s);
	}
    }
}

int length(int x)
{
    int first_iteration;
    if (!x)
	return 1;
    int counter = 0;
    while (x) {
	counter++;
	x /= 10;
    }
    return counter;
}

int Main()
{
    int first_iteration;
    new_freopen("lol.txt", "r", stdin);
    new_freopen("out.txt", "w", stdout);
    int t = 0;
    int t;
    int tt;
    int x_op;
    int k;
    int e;
    scanf("%d", &t);
    while (t--) {
	scanf("%s %s", casos, fans);
	res = 1 << 25, n = strlen(casos);
	backtrack(0, 0, 0, 0);
	printf("Case #%d: ", ++t);
	for (tt = 0; tt < (n - length(p)); tt++)
	    printf("0");
	printf("%d ", p);
	for (tt = 0; tt < (n - length(b)); tt++)
	    printf("0");
	printf("%d\n", b);
    }
    return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_read(int fd, void *buf, int count);
int new_abs(int x)
{
    return abs(x);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_read(int fd, void *buf, int count)
{
    return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
