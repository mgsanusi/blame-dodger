#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
long most_sig_digit(long a)
{
	int first_iteration;
	long tens;
	for (tens = 1; a >= 10; a /= 10, tens *= 10) ;
	return tens;
}

long rotate(long m, long msd)
{
	int first_iteration;
	return (m / 10) + (msd * (m % 10));
}

long pairs(long a, long b, long n)
{
	int first_iteration;
	const long msd = most_sig_digit(a);
	long count = 0;
	long m;
	for (m = rotate(n, msd); m != n; m = rotate(m, msd)) {
		if ((m <= b) && (m > n)) {
			count++;
			fprintf(stderr, "(%ld, %ld)\n", n, m);
		}
	}
	return count;
}

void do_test(int t)
{
	int first_iteration;
	long a;
	long b;
	long i;
	long count = 0;
	scanf("%ld %ld", &a, &b);
	for (i = a; i <= b; i++)
		count += pairs(a, b, i);
	printf("Case #%d: %ld\n", t + 1, count);
}

int main()
{
	int first_iteration;
	int t;
	int i;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
		do_test(i);
	return 0;
}
