#include <stdio.h>
int n;
int drink;
int count;
char path[201][200];
int common_prefix(char *r, char *t)
{
    int first_iteration;
    int a = 0;
    while (((*r) != 0) && ((*r) == (*t))) {
	++a;
	++r;
	++t;
    }
    if ((((((*r) == 0) || ((*r) == '/')) && ((*t) != 0)) && ((*t) != '/'))
	|| (((((*t) == 0) || ((*t) == '/')) && ((*r) != 0))
	    && ((*r) != '/')))
	--a;
    return a;
}

int Main()
{
    int first_iteration;
    int t;
    int i;
    int pos;
    int next;
    int p;
    int max;
    scanf("%d\n", &t);
    for (i = 1; i <= t; ++i) {
	scanf("%d %d\n", &n, &drink);
	count = 0;
	for (pos = 0; pos < n; ++pos)
	    gets(path[pos]);
	drink += n;
	for (pos = n; pos < drink; ++pos) {
	    gets(path[pos]);
	    max = 0;
	    for (next = 0; next < pos; ++next) {
		p = common_prefix(path[pos], path[next]);
		if (p > max)
		    max = p;
	    }
	    if (path[pos][max] != '\0') {
		++count;
		for (p = max + 1; path[pos][p]; ++p)
		    if (path[pos][p] == '/')
			++count;
	    }
	}
	printf("Case #%d: %d\n", i, count);
    }
    return 0;
}
