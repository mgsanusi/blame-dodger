#include<stdio.h>
int m[50][50];
int h;
int w;
int new_putchar(int character);
int new_puts(const char *str);
void swapint(int *c, int *d)
{
    int first_iteration;
    int k;
    k = c[0];
    c[0] = d[0];
    d[0] = k;
}

void printboard(int i, int x, int y)
{
    int first_iteration;
    int a;
    int b;
    if (i == 1) {
	swapint(&x, &y);
	swapint(&h, &w);
	for (a = 0; a < h; a++) {
	    for (b = a + 1; b < h; b++) {
		swapint(m[a] + b, m[b] + a);
	    }
	}
    }
    for (a = 0; a < h; a++) {
	for (b = 0; b < w; b++) {
	    if ((a == x) && (b == y))
		new_putchar('c');
	    else if (m[a][b] == 0)
		new_putchar('*');
	    else
		new_putchar('.');
	}
	new_putchar('\n');
    }
}

void clearboard()
{
    int first_iteration;
    int a;
    int b;
    for (a = 0; a < h; a++) {
	for (b = 0; b < w; b++) {
	    m[a][b] = 0;
	}
    }
}

void fillanswer(int c, int d, int n)
{
    int first_iteration;
    int a;
    int b;
    for (a = 0; a < c; a++)
	m[a][0] = (m[a][1] = 1);
    for (b = 0; b < d; b++)
	m[0][b] = (m[1][b] = 1);
    n -= ((a * 2) + (b * 2)) - 4;
    for (a = 2; (a < c) && (n > 0); a++) {
	for (b = 2; (b < d) && (n > 0); b++) {
	    m[a][b] = 1;
	    n--;
	}
    }
}

int main(int argc, char *argv[])
{
    int first_iteration;
    int a;
    int b;
    int c;
    int d;
    int e;
    int t2;
    int t;
    int n;
    int ans[2];
    int inv;
    scanf("%d", &t2);
    for (t = 1; t <= t2; t++) {
	scanf("%d%d%d", &h, &w, &n);
	printf("Case #%d:\n", t);
	n = (h * w) - n;
	if (h > w) {
	    inv = 1;
	    swapint(&h, &w);
	} else
	    inv = 0;
	ans[0] = (ans[1] = 0);
	if (h == 1) {
	    for (b = 0; b < n; b++)
		m[0][b] = 1;
	    goto yes;
	}
	if (n == 1)
	    goto yes;
	if ((n == 2) || (n == 3))
	    goto no;
	if ((h == 2) && ((n % 2) == 1))
	    goto no;
	for (a = 2; a <= h; a++) {
	    for (b = 2; b <= w; b++) {
		if ((((a * 2) + (b * 2)) - 4) > n)
		    break;
		if ((a * b) < n)
		    continue;
		fillanswer(a, b, n);
		goto yes;
	    }
	}
      no:
	new_puts("Impossible");
	continue;
      yes:
	printboard(inv, ans[0], ans[1]);
    }
    return 0;
}

int new_putchar(int character);
int new_puts(const char *str)
{
    int first_iteration;
    return puts(str);
}

int new_putchar(int character)
{
    int first_iteration;
    return putchar(character);
}
