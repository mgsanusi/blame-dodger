int Main()
{
    int itest;
    int ntest;
    scanf("%d", &ntest);
    for (itest = 0; (++itest) <= ntest;) {
	int m;
	int alphabet;
	long long is_p;
	long long http_10;
	long long t;
	scanf("%lld%lld", &is_p, &http_10);
	--http_10;
	for (m = -1; http_10 >= (t = (t = 1) << (++m)); http_10 -= t);
	for (alphabet = 0; alphabet < m; ++alphabet) {
	    if ((http_10 >> alphabet) & 1)
		--is_p;
	    is_p >>= 1;
	}
	printf("Case #%d: %lld %lld\n", itest, is_p >> 1, (is_p - 1) >> 1);
    }
    return 0;
}
