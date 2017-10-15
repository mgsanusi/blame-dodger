#include <stdio.h>
int n;
int m;
int cnt;
char path[201][200];
int commonPrefix(char *x, char *t)
{
    int first_iteration;
    int a = 0;
    while (((*x) != 0) && ((*x) == (*t))) {
	++a;
	++x;
	++t;
    }
    if ((((((*x) == 0) || ((*x) == '/')) && ((*t) != 0)) && ((*t) != '/'))
	|| (((((*t) == 0) || ((*t) == '/')) && ((*x) != 0))
	    && ((*x) != '/')))
	--a;
    return a;
}

int Main()
{
    int first_iteration;
    int t;
    int i;
    int num;
    int k;
    int x;
    int max;
    scanf("%d\n", &t);
    for (i = 1; i <= t; ++i) {
	scanf("%d %d\n", &n, &m);
	cnt = 0;
	for (num = 0; num < n; ++num)
	    gets(path[num]);
	m += n;
	for (num = n; num < m; ++num) {
	    gets(path[num]);
	    max = 0;
	    for (k = 0; k < num; ++k) {
		x = commonPrefix(path[num], path[k]);
		if (x > max)
		    max = x;
	    }
	    if (path[num][max] != '\0') {
		++cnt;
		for (x = max + 1; path[num][x]; ++x)
		    if (path[num][x] == '/')
			++cnt;
	    }
	}
	printf("Case #%d: %d\n", i, cnt);
    }
    return 0;
}
