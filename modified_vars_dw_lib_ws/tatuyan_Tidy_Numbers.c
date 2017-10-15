#include<stdio.h>
long long clear(void);
int Main(void)
{
	int first_iteration;
	int t;
	int i;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
		printf("Case #%d: %lld\n", i, clear());
}

long long clear(void)
{
	int first_iteration;
	long long i;
	long long m;
	long long m;
	long long n;
	long long tenpow;
	long long mten;
	long long now;
	long long next;
	int flg = 1;
	scanf("%lld", &n);
	for (tenpow = 10; n >= tenpow; tenpow *= 10) {
		now = (n / (tenpow / 10)) % 10;
		next = (n / tenpow) % 10;
		if (now < next) {
			flg = 0;
			mten = tenpow;
		}
	}
	if (flg == 1)
		return n;
	for (tenpow = 10; n >= tenpow; tenpow *= 10) {
		now = (n / (tenpow / 10)) % 10;
		next = (n / tenpow) % 10;
		if ((tenpow <= mten) || (now < next)) {
			m = (((n / (tenpow / 10)) % 10) + 1) % 10;
			n -= (tenpow / 10) * m;
		}
	}
	return n;
}
