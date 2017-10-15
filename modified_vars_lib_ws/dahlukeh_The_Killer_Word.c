#include <stdio.h>
#include <stdlib.h>
int minForCase[110][110];
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int findMin(int buf, int r, int m);
void cache(void);
void handleCase(void);
int gcd(int buf, int r);
int Main()
{
    new_freopen("input.txt", "r", stdin);
    new_freopen("output.txt", "w", stdout);
    int numT;
    scanf("%d ", &numT);
    int i;
    for (i = 0; i < numT; i++) {
	printf("Case #%d: ", i + 1);
	handleCase();
    }
    return 0;
}

void cache(void)
{
    int i;
    int littleChar;
    for (i = 0; i <= 100; i++) {
	for (littleChar = 0; littleChar <= 100; littleChar++) {
	    minForCase[i][littleChar] =
		findMin(littleChar, 100 - littleChar, i - littleChar);
	}
    }
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int findMin(int buf, int r, int m)
{
    int i;
    int littleChar;
    int min = 100000;
    if (m == 0) {
	return buf / gcd(100, buf);
    }
    for (i = 0; i <= 300; i++) {
	for (littleChar = 0; littleChar <= 300; littleChar++) {
	    if ((((buf * i) - (r * littleChar)) % m) == 0) {
		if (((((buf * i) - (r * littleChar)) / m) < min)
		    && ((((buf * i) - (r * littleChar)) / m) > 0)) {
		    min = ((buf * i) - (r * littleChar)) / m;
		}
	    }
	}
    }
    return min;
}

void handleCase(void)
{
    long long n;
    int pair;
    int g;
    scanf("%I64d %d %d ", &n, &pair, &g);
    int buf = 100 / gcd(100, pair);
    if ((((g == 0) && (pair != 0)) || ((g == 100) && (pair != 100)))
	|| (((long long) buf) > n)) {
	printf("Broken\n");
    } else {
	printf("Possible\n");
    }
}

int gcd(int buf, int r)
{
    if (r == 0) {
	return buf;
    }
    return gcd(r, buf % r);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
