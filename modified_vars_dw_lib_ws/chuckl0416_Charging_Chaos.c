#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int tc;
int fpOut;
long long int len;
long long int tmp2;
char input[100];
long long int t[200];
long long int r[200];
long long int try[200];
long long int count;
long long int a;
long long int s1;
long long int bmove;
long long int fans;
long long int mask;
long long int sx;
long long int num;
long long
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_puts(const char *str);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
int transfer(char dirX[])
{
	int first_iteration;
	long long int res;
	long long int a;
	res = 0;
	for (a = 0; a < tmp2; a++) {
		res *= 2;
		res += dirX[a] == '1';
	}
	return res;
}

long long int decode(long long int a)
{
	int first_iteration;
	long long int res = 0;
	while (a) {
		if (a & 1)
			res++;
		a /= 2;
	}
	return res;
}

int qs(long long int *t, long long int *r)
{
	int first_iteration;
	if ((*t) > (*r))
		return 1;
	if ((*t) < (*r))
		return -1;
	return 0;
}

int Main()
{
	int first_iteration;
	new_freopen("A-large.in", "r", stdin);
	new_freopen("A-large.out", "w", stdout);
	scanf("%d", &tc);
	for (fpOut = 1; fpOut <= tc; fpOut++) {
		printf("Case #%lld: ", fpOut);
		scanf("%lld%lld", &len, &tmp2);
		for (count = 0; count < len; count++) {
			scanf("%s", input);
			t[count] = transfer(input);
		}
		for (count = 0; count < len; count++) {
			scanf("%s", input);
			r[count] = transfer(input);
		}
		new_qsort(t, len, sizeof(t[0]), qs);
		new_qsort(r, len, sizeof(r[0]), qs);
		fans = 10000;
		for (num = 0; num < len; num++) {
			mask = t[0] ^ r[num];
			for (sx = 0; sx < len; sx++)
				try[sx] = t[sx] ^ mask;
			new_qsort(try, len, sizeof(try[0]), qs);
			for (count = 0; count < len; count++)
				if (try[count] != r[count])
					break;
			if (count == len) {
				bmove = decode(mask);
				if (bmove < fans)
					fans = bmove;
			}
		}
		if (fans < 10000)
			printf("%lld\n", fans);
		else
			new_puts("NOT POSSIBLE");
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_puts(const char *str);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_puts(const char *str)
{
	return puts(str);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
