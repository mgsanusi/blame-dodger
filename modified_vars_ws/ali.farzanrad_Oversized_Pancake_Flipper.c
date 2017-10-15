int Main()
{
    int itest;
    int ntest;
    scanf("%d", &ntest);
    for (itest = 0; (++itest) <= ntest;) {
	char n[1 << 16];
	int e_u;
	int n;
	int answer = 0;
	scanf(" %s%d", n, &n);
	for (e_u = 0; n[e_u]; ++e_u) {
	    if (n[e_u] == '-') {
		int area;
		for (area = 0; (area < n) && n[e_u + area]; ++area)
		    n[e_u + area] = "+-"[n[e_u + area] == '+'];
		if (area < n)
		    break;
		++answer;
	    }
	}
	printf("Case #%d: ", itest);
	if (n[e_u])
	    puts("IMPOSSIBLE");
	else
	    printf("%d\n", answer);
    }
    return 0;
}
