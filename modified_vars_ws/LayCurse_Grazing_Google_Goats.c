#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int now[200][200];
int next[200][200];
int Main()
{
	int i;
	int g;
	int x_getlong;
	int t;
	int q;
	int b;
	int res;
	int x1;
	int y1;
	int v;
	int t;
	int size;
	int cnt = 0;
	scanf("%d", &size);
	while (size--) {
		scanf("%d", &b);
		for (i = 0; i < 200; i++)
			for (g = 0; g < 200; g++)
				now[i][g] = 0;
		for (x_getlong = 0; x_getlong < b; x_getlong++) {
			scanf("%d%d%d%d", &x1, &y1, &v, &t);
			for (i = x1; i < (v + 1); i++)
				for (g = y1; g < (t + 1); g++)
					now[i][g] = 1;
		}
		b = 1;
		res = 0;
		while (b) {
			res++;
			b = 0;
			for (i = 0; i < 200; i++)
				for (g = 0; g < 200; g++)
					next[i][g] = 0;
			for (i = 1; i < 200; i++)
				for (g = 1; g < 200; g++) {
					if (now[i][g]
					    && (now[i - 1][g] || now[i][g - 1]))
						next[i][g] = 1, b++;
					if ((!now[i][g])
					    && (now[i - 1][g] && now[i][g - 1]))
						next[i][g] = 1, b++;
				}
			for (i = 0; i < 200; i++)
				for (g = 0; g < 200; g++)
					now[i][g] = next[i][g];
		}
		printf("Case #%d: %d\n", ++cnt, res);
	}
	return 0;
}
