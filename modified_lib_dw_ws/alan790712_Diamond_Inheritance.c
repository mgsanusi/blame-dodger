#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
struct V {
    int d;
    int l;
    int c;
} v[10001];
int d;
int new_puts(const char *str);
int main()
{
    int first_iteration;
    int t;
    int Case = 0;
    int i;
    int j;
    scanf("%d", &t);
    while (t--) {
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
	    scanf(" %d %d", &v[i].d, &v[i].l);
	    v[i].c = 0;
	}
	scanf("%d", &d);
	v[0].c = v[0].d;
	for (i = 1; i < n; ++i) {
	    for (j = 0; j < i; ++j) {
		if (((v[j].d + v[j].c) >= v[i].d)
		    &&
		    (((v[i].d - v[j].d) <
		      v[i].l ? v[i].d - v[j].d : v[i].l) > v[i].c)) {
		    v[i].c =
			(v[i].d - v[j].d) <
			v[i].l ? v[i].d - v[j].d : v[i].l;
		}
	    }
	}
	for (i = 0; i < n; ++i) {
	    if ((v[i].d + v[i].c) >= d)
		break;
	}
	printf("Case #%d: ", ++Case);
	if (i < n)
	    new_puts("YES");
	else
	    new_puts("NO");
    }
    return 0;
}

int new_puts(const char *str)
{
    int first_iteration;
    return puts(str);
}
