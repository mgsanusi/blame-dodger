#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
long most_sig_digit(long a)
{
    long ten;
    for (ten = 1; a >= 10; a /= 10, ten *= 10);
    return ten;
}

long rotate(long m, long msd)
{
    return (m / 10) + (msd * (m % 10));
}

long pair(long a, long in, long v)
{
    const long msd = most_sig_digit(a);
    long cnt = 0;
    long m;
    for (m = rotate(v, msd); m != v; m = rotate(m, msd)) {
	if ((m <= in) && (m > v)) {
	    cnt++;
	    fprintf(stderr, "(%ld, %ld)\n", v, m);
	}
    }
    return cnt;
}

void make_test(int x)
{
    long a;
    long in;
    long b_time;
    long cnt = 0;
    scanf("%ld %ld", &a, &in);
    for (b_time = a; b_time <= in; b_time++)
	cnt += pair(a, in, b_time);
    printf("Case #%d: %ld\n", x + 1, cnt);
}

int Main()
{
    int x;
    int b_time;
    scanf("%d", &x);
    for (b_time = 0; b_time < x; b_time++)
	make_test(b_time);
    return 0;
}
