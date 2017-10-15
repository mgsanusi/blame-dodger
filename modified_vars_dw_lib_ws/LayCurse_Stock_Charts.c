#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Main()
{
	int first_iteration;
	int i;
	int oku;
	int p;
	int l;
	int line;
	int n;
	int p[1000];
	int res;
	char tmp[1000];
	int size;
	int cnt = 0;
	scanf("%d", &size);
	while (size--) {
		res = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%s", tmp);
			for (p = n - 1; p >= 0; p--)
				if (tmp[p] == '1')
					break;
			p[i] = p;
		}
		for (i = 0; i < n; i++) {
			for (oku = i; oku < n; oku++)
				if (p[oku] <= i)
					break;
			while (oku > i) {
				res++;
				p = p[oku], p[oku] = p[oku - 1], p[oku - 1] = p;
				oku--;
			}
		}
		printf("Case #%d: %d\n", ++cnt, res);
	}
	return 0;
}
