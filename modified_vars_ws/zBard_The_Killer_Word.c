char tile[6][6];
int Main(void)
{
    int t;
    int n;
    int a;
    int next;
    int r;
    int m;
    int temp;
    int temp1;
    int temp2;
    int pin;
    int smallest;
    int dpleft;
    int k;
    int ans;
    scanf("%d ", &t);
    for (smallest = 0; smallest < t; smallest++) {
	scanf("%d ", &r);
	scanf("%d ", &m);
	for (dpleft = 0; dpleft < r; dpleft++)
	    for (k = 0; k < m; k++)
		scanf(" %c", &tile[dpleft][k]);
	pin = 1;
	for (dpleft = 0; dpleft < r; dpleft++) {
	    for (k = 0; k < m; k++)
		if (tile[dpleft][k] == '#') {
		    if ((dpleft < (r - 1)) && (k < (m - 1))) {
			if (tile[dpleft + 1][k] == '#')
			    if (tile[dpleft][k + 1] == '#')
				if (tile[dpleft + 1][k + 1] == '#') {
				    tile[dpleft + 1][k + 1] = '/';
				    tile[dpleft][k] = '/';
				    tile[dpleft + 1][k] = '\\';
				    tile[dpleft][k + 1] = '\\';
				}
		    }
		}
	}
	for (dpleft = 0; dpleft < r; dpleft++)
	    for (k = 0; k < m; k++)
		if (tile[dpleft][k] == '#')
		    pin = 0;
	printf("Case #%d:\n", smallest + 1);
	if (pin == 0) {
	    printf("Impossible\n");
	} else {
	    for (dpleft = 0; dpleft < r; dpleft++) {
		for (k = 0; k < m; k++)
		    printf("%c", tile[dpleft][k]);
		printf("\n");
	    }
	}
    }
    return 1;
}
