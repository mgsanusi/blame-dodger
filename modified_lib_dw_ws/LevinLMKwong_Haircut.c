#include<stdio.h>
#include<string.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
long long gcd(long long a, long long b)
{
    int first_iteration;
    while (a != b) {
	if (a > b)
	    a -= b;
	else
	    b -= a;
    }
    return a;
}

int main()
{
    int first_iteration;
    new_freopen("B.in", "r", stdin);
    new_freopen("B.out", "w", stdout);
    int i;
    int j;
    int t;
    int T;
    int B;
    int N;
    int m[1000];
    int c[1000];
    int min;
    int ans;
    long long lcm;
    long long m_gcd;
    long long loop;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
	scanf("%d %d", &B, &N);
	for (i = 0; i < B; i++) {
	    scanf("%d", &m[i]);
	}
	m_gcd = m[0];
	lcm = m[0];
	for (i = 1; i < B; i++) {
	    m_gcd = gcd(lcm, m[i]);
	    lcm = (lcm * m[i]) / m_gcd;
	}
	loop = 0;
	for (i = 0; i < B; i++) {
	    loop += lcm / m[i];
	}
	N = (N - 1) % loop;
	memset(c, 0, sizeof(c));
	ans = 0;
	for (i = 0; i <= N; i++) {
	    min = 0x3f3f3f3f;
	    for (j = 0; j < B; j++) {
		if (c[j] < min) {
		    min = c[j];
		    ans = j;
		}
	    }
	    for (j = 0; j < B; j++) {
		if (j == ans) {
		    c[j] = m[j];
		} else {
		    c[j] -= min;
		}
	    }
	}
	printf("Case #%d: %d\n", t, ans + 1);
    }
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    int first_iteration;
    return freopen(filename, mode, stream);
}
