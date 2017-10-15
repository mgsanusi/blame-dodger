#include<stdio.h>
int new_puts(const char *str);
int Main()
{
    int oowp;
    int num;
    int k;
    int t;
    int m;
    int n;
    int p;
    int size;
    int cnt = 0;
    char tmp[10000];
    int ret[2000];
    int r[2000];
    int dx[2000];
    char f[2000];
    int a_min;
    int a_max;
    int b_min;
    int b_max;
    int c_min;
    int c_max;
    int d_min;
    int d_max;
    int s;
    int y;
    scanf("%d", &size);
    while (size--) {
	scanf("%d ", &n);
	printf("Case #%d:\n", ++cnt);
	for (oowp = 0; oowp < n; oowp++) {
	    gets(tmp);
	    sscanf(tmp, "%d%d%s", ret + oowp, r + oowp, f);
	    if (f[0] == 'B')
		dx[oowp] = 0;
	    else
		dx[oowp] = 1;
	}
	a_min = (b_min = (c_max = (d_max = 100000000)));
	a_max = (b_max = (c_min = (d_min = -a_min)));
	for (oowp = 0; oowp < n; oowp++)
	    if (dx[oowp] == 0) {
		if (a_min > ret[oowp])
		    a_min = ret[oowp];
		if (a_max < ret[oowp])
		    a_max = ret[oowp];
		if (b_min > r[oowp])
		    b_min = r[oowp];
		if (b_max < r[oowp])
		    b_max = r[oowp];
	    }
	for (oowp = 0; oowp < n; oowp++)
	    if (dx[oowp] == 1) {
		if ((a_min <= ret[oowp]) && (ret[oowp] <= a_max)) {
		    if ((r[oowp] > b_max) && (d_max > r[oowp]))
			d_max = r[oowp];
		    if ((r[oowp] < b_min) && (d_min < r[oowp]))
			d_min = r[oowp];
		}
		if ((b_min <= r[oowp]) && (r[oowp] <= b_max)) {
		    if ((ret[oowp] > a_max) && (c_max > ret[oowp]))
			c_max = ret[oowp];
		    if ((ret[oowp] < a_min) && (c_min < ret[oowp]))
			c_min = ret[oowp];
		}
	    }
	scanf("%d", &p);
	while (p--) {
	    scanf("%d%d", &s, &y);
	    for (oowp = 0; oowp < n; oowp++)
		if ((ret[oowp] == s) && (r[oowp] == y)) {
		    if (dx[oowp] == 0)
			new_puts("BIRD");
		    else
			new_puts("NOT BIRD");
		    break;
		}
	    if (oowp < n)
		continue;
	    if ((((a_min <= s) && (s <= a_max)) && (b_min <= y))
		&& (y <= b_max)) {
		new_puts("BIRD");
		continue;
	    }
	    if ((((s >= c_max) || (s <= c_min)) || (y >= d_max))
		|| (y <= d_min)) {
		new_puts("NOT BIRD");
		continue;
	    }
	    for (oowp = 0; oowp < n; oowp++)
		if (dx[oowp] == 1) {
		    if ((ret[oowp] > a_max) && (s < ret[oowp]))
			continue;
		    if ((ret[oowp] < a_min) && (s > ret[oowp]))
			continue;
		    if ((r[oowp] > b_max) && (y < r[oowp]))
			continue;
		    if ((r[oowp] < b_min) && (y > r[oowp]))
			continue;
		    new_puts("NOT BIRD");
		    break;
		}
	    if (oowp < n)
		continue;
	    new_puts("UNKNOWN");
	}
    }
    return 0;
}

int new_puts(const char *str)
{
    return puts(str);
}
