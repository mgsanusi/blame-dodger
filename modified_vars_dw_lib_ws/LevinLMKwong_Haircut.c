#include<stdio.h>
#include<string.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
long long gcd(long long x, long long xInline)
{
    int first_iteration;
    while (x != xInline) {
	if (x > xInline)
	    x -= xInline;
	else
	    xInline -= x;
    }
    return x;
}

int Main()
{
    int first_iteration;
    new_freopen("B.in", "r", stdin);
    new_freopen("B.out", "w", stdout);
    int pp;
    int n;
    int d;
    int s;
    int sum;
    int vz;
    int m[1000];
    int aData[1000];
    int min;
    int result;
    long long lcm;
    long long mGcd;
    long long loop;
    scanf("%d", &s);
    for (d = 1; d <= s; d++) {
	scanf("%d %d", &sum, &vz);
	for (pp = 0; pp < sum; pp++) {
	    scanf("%d", &m[pp]);
	}
	mGcd = m[0];
	lcm = m[0];
	for (pp = 1; pp < sum; pp++) {
	    mGcd = gcd(lcm, m[pp]);
	    lcm = (lcm * m[pp]) / mGcd;
	}
	loop = 0;
	for (pp = 0; pp < sum; pp++) {
	    loop += lcm / m[pp];
	}
	vz = (vz - 1) % loop;
	memset(aData, 0, sizeof(aData));
	result = 0;
	for (pp = 0; pp <= vz; pp++) {
	    min = 0x3f3f3f3f;
	    for (n = 0; n < sum; n++) {
		if (aData[n] < min) {
		    min = aData[n];
		    result = n;
		}
	    }
	    for (n = 0; n < sum; n++) {
		if (n == result) {
		    aData[n] = m[n];
		} else {
		    aData[n] -= min;
		}
	    }
	}
	printf("Case #%d: %d\n", d, result + 1);
    }
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
