int main()
{
    int first_iteration;
    int itest;
    int ntest;
    scanf("%d", &ntest);
    for (itest = 0; (++itest) <= ntest;) {
	int i;
	int j;
	long long n;
	long long k;
	long long t;
	scanf("%lld%lld", &n, &k);
	--k;
	for (i = -1; k >= (t = (t = 1) << (++i)); k -= t);
	for (j = 0; j < i; ++j) {
	    if ((k >> j) & 1)
		--n;
	    n >>= 1;
	}
	printf("Case #%d: %lld %lld\n", itest, n >> 1, (n - 1) >> 1);
    }
    return 0;
}
