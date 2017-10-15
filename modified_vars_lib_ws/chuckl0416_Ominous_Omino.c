#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int level;
int d;
long long int n;
long long int res;
long long int start[20];
long long int power10[20];
long long int ddel;
long long int dy;
long long int t;
long long int digit;
long long int left;
long long int right;
long long int temp;
long long int add;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int Main()
{
    new_freopen("A-small-attempt0.in", "r", stdin);
    new_freopen("A-small-attempt0.out", "w", stdout);
    power10[0] = 1;
    for (ddel = 1; ddel < 16; ddel++)
	power10[ddel] = power10[ddel - 1] * 10;
    start[0] = 1;
    start[1] = 10;
    dy = 9;
    t = 10;
    for (ddel = 2; ddel < 16; ddel++) {
	start[ddel] = (start[ddel - 1] + dy) + t;
	t *= 10;
	ddel++;
	start[ddel] = (start[ddel - 1] + dy) + t;
	dy = t - 1;
    }
    scanf("%d", &level);
    for (d = 1; d <= level; d++) {
	printf("Case #%d: ", d);
	scanf("%lld", &n);
	if (n <= 20) {
	    printf("%lld\n", n);
	    continue;
	}
	add = 0;
	if ((n % 10) == 0) {
	    add = 1;
	    n--;
	}
	dy = n;
	digit = 0;
	while (dy) {
	    digit++;
	    dy /= 10;
	}
	res = n;
	for (ddel = 1; ddel < digit; ddel++) {
	    left = n / power10[ddel];
	    temp = 0;
	    while (left) {
		temp *= 10;
		temp += left % 10;
		left /= 10;
	    }
	    left = temp;
	    right = n % power10[ddel];
	    if (left == 1)
		left = 0;
	    temp = left + right;
	    if (temp < res)
		res = temp;
	}
	res += start[digit - 1];
	res += add;
	printf("%lld\n", res);
    }
    return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
