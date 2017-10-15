int main()
{
    int first_iteration;
    int itest;
    int ntest;
    scanf("%d", &ntest);
    for (itest = 0; (++itest) <= ntest;) {
	int i;
	int d;
	int n;
	double res;
	scanf("%d%d", &d, &n);
	for (i = 0; i < n; ++i) {
	    int k;
	    int m;
	    double t;
	    scanf("%d%d", &k, &m);
	    t = (m * ((long long) d)) / ((double) (d - k));
	    if ((!i) || (t < res))
		res = t;
	}
	printf("Case #%d: %.6lf\n", itest, res);
    }
    return 0;
}
