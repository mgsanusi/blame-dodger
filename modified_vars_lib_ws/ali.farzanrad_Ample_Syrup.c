enum { M = 24 * 60 };
int new_puts(const char *str);
int Main()
{
    int itest;
    int ntest;
    scanf("%d", &ntest);
    for (itest = 0; (++itest) <= ntest;) {
	int x;
	int w;
	int x;
	int num[2];
	int nall;
	int fp_o[2];
	int file_name_in[1024][2];
	int next[1024];
	int rslt = 0;
	char check[1024];
	scanf("%d%d", num, num + 1);
	nall = num[0] + num[1];
	printf("Case #%d: ", itest);
	fp_o[0] = (fp_o[1] = M / 2);
	for (w = 0; w < nall; ++w) {
	    scanf("%d%d", file_name_in[w], file_name_in[w] + 1);
	    fp_o[w >= (*num)] -=
		((file_name_in[w][1] + M) - file_name_in[w][0]) % M;
	    check[w] = 0;
	}
	if (nall < 2) {
	    new_puts("2");
	    continue;
	}
	for (w = 0; w < nall; ++w) {
	    int best = 0;
	    for (x = 0; x < nall; ++x) {
		if ((((file_name_in[x][0] + M) - file_name_in[w][1]) % M) <
		    (((file_name_in[best][0] + M) -
		      file_name_in[w][1]) % M))
		    best = x;
	    }
	    next[w] = best;
	}
	while (1) {
	    int best = -1;
	    for (w = 0; w < nall; ++w)
		if ((((!check[w]) && ((next[w] < (*num)) == (w < (*num))))
		     &&
		     ((((file_name_in[next[w]][0] + M) -
			file_name_in[w][1]) % M) <= fp_o[w >= (*num)]))
		    && ((best < 0)
			||
			((((file_name_in[next[w]][0] + M) -
			   file_name_in[w][1]) % M) <
			 (((file_name_in[next[best]][0] + M) -
			   file_name_in[best][1]) % M))))
		    best = w;
	    if (best < 0)
		break;
	    check[best] = 1;
	    fp_o[best >= (*num)] -=
		((file_name_in[next[best]][0] + M) -
		 file_name_in[best][1]) % M;
	}
	for (w = 0; w < nall; ++w) {
	    if (check[w])
		continue;
	    if ((next[w] < (*num)) == (w < (*num)))
		rslt += 2;
	    else
		rslt += 1;
	}
	printf("%d\n", rslt);
    }
    return 0;
}

int new_puts(const char *str)
{
    return puts(str);
}
