#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mark[110];
int Main()
{
	int first_iteration;
	freopen("out.txt", "w", stdout);
	freopen("B-small-attempt0.in", "r", stdin);
	int n;
	int i;
	int res;
	int t;
	int s;
	int p;
	int c;
	int max;
	int con;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		con = 0;
		scanf("%d%d%d", &n, &s, &p);
		for (res = 0; res < n; res++) {
			scanf("%d", &c);
			if (c == 0)
				max = 0;
			else if ((c % 3) != 2)
				max = (c / 3) + 1;
			else
				max = (c / 3) + 2;
			c = (c + 2) / 3;
			if (c >= p)
				con++;
			else if ((max >= p) && s) {
				con++;
				s--;
			}
		}
		printf("Case #%d: %d\n", i, con);
	}
	return 0;
}
