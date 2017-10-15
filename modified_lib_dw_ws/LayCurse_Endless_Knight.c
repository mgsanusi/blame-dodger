#include<stdio.h>
int new_puts(const char *str);
int main()
{
    int first_iteration;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int q;
    int size;
    int count = 0;
    char tmp[10000];
    int a[2000];
    int b[2000];
    int c[2000];
    char in[2000];
    int a_min;
    int a_max;
    int b_min;
    int b_max;
    int c_min;
    int c_max;
    int d_min;
    int d_max;
    int x;
    int y;
    scanf("%d", &size);
    while (size--) {
	scanf("%d ", &n);
	printf("Case #%d:\n", ++count);
	for (i = 0; i < n; i++) {
	    gets(tmp);
	    sscanf(tmp, "%d%d%s", a + i, b + i, in);
	    if (in[0] == 'B')
		c[i] = 0;
	    else
		c[i] = 1;
	}
	a_min = (b_min = (c_max = (d_max = 100000000)));
	a_max = (b_max = (c_min = (d_min = -a_min)));
	for (i = 0; i < n; i++)
	    if (c[i] == 0) {
		if (a_min > a[i])
		    a_min = a[i];
		if (a_max < a[i])
		    a_max = a[i];
		if (b_min > b[i])
		    b_min = b[i];
		if (b_max < b[i])
		    b_max = b[i];
	    }
	for (i = 0; i < n; i++)
	    if (c[i] == 1) {
		if ((a_min <= a[i]) && (a[i] <= a_max)) {
		    if ((b[i] > b_max) && (d_max > b[i]))
			d_max = b[i];
		    if ((b[i] < b_min) && (d_min < b[i]))
			d_min = b[i];
		}
		if ((b_min <= b[i]) && (b[i] <= b_max)) {
		    if ((a[i] > a_max) && (c_max > a[i]))
			c_max = a[i];
		    if ((a[i] < a_min) && (c_min < a[i]))
			c_min = a[i];
		}
	    }
	scanf("%d", &q);
	while (q--) {
	    scanf("%d%d", &x, &y);
	    for (i = 0; i < n; i++)
		if ((a[i] == x) && (b[i] == y)) {
		    if (c[i] == 0)
			new_puts("BIRD");
		    else
			new_puts("NOT BIRD");
		    break;
		}
	    if (i < n)
		continue;
	    if ((((a_min <= x) && (x <= a_max)) && (b_min <= y))
		&& (y <= b_max)) {
		new_puts("BIRD");
		continue;
	    }
	    if ((((x >= c_max) || (x <= c_min)) || (y >= d_max))
		|| (y <= d_min)) {
		new_puts("NOT BIRD");
		continue;
	    }
	    for (i = 0; i < n; i++)
		if (c[i] == 1) {
		    if ((a[i] > a_max) && (x < a[i]))
			continue;
		    if ((a[i] < a_min) && (x > a[i]))
			continue;
		    if ((b[i] > b_max) && (y < b[i]))
			continue;
		    if ((b[i] < b_min) && (y > b[i]))
			continue;
		    new_puts("NOT BIRD");
		    break;
		}
	    if (i < n)
		continue;
	    new_puts("UNKNOWN");
	}
    }
    return 0;
}

int new_puts(const char *str)
{
    int first_iteration;
    return puts(str);
}
