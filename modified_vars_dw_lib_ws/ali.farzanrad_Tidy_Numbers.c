int Main()
{
    int first_iteration;
    int itest;
    int ntest;
    scanf("%d", &ntest);
    for (itest = 0; (++itest) <= ntest;) {
	char n[1 << 16];
	int j;
	scanf(" %s", n);
	for (j = 0; n[++j] && (n[j] >= n[j - 1]););
	if (n[j]) {
	    while (((--j) > 0) && (n[j] == '0'));
	    while (--n[j], (j > 0) && (n[j] < n[j - 1]))
		--j;
	    while (n[++j])
		n[j] = '9';
	}
	printf("Case #%d: %s\n", itest, n + ((*n) == '0'));
    }
    return 0;
}
