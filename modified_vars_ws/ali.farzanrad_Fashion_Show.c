int Main()
{
	int itest;
	int ntest;
	scanf("%d", &ntest);
	for (itest = 0; (++itest) <= ntest;) {
		int i;
		int d;
		int b;
		double rslt;
		scanf("%d%d", &d, &b);
		for (i = 0; i < b; ++i) {
			int b;
			int v;
			double ans;
			scanf("%d%d", &b, &v);
			ans = (v * ((long long)d)) / ((double)(d - b));
			if ((!i) || (ans < rslt))
				rslt = ans;
		}
		printf("Case #%d: %.6lf\n", itest, rslt);
	}
	return 0;
}
