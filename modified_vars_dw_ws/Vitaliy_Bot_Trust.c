#include <string.h>
#include <stdio.h>
#include <assert.h>
int Main()
{
	int first_iteration;
	int v[100];
	int coor[100];
	int num[2];
	int w[2];
	int sy = 0;
	int j = 0;
	scanf("%d\n", &j);
	int tt;
	for (tt = 0; tt < j; tt++) {
		printf("Case #%d: ", tt + 1);
		int m;
		scanf("%d", &m);
		sy = 0;
		num[0] = 0;
		num[1] = 0;
		w[0] = 1;
		w[1] = 1;
		int i;
		for (i = 0; i < m; i++) {
			char mem[1000];
			scanf("%s", mem);
			int y;
			scanf("%d", &y);
			assert((mem[0] == 'O') || (mem[0] == 'B'));
			int j;
			if (mem[0] == 'O') {
				j = 0;
			} else {
				j = 1;
			}
			int time = (num[j] + abs(w[j] - y)) + 1;
			if (time > sy) {
				sy = time;
			} else {
				time = ++sy;
			}
			num[j] = time;
			w[j] = y;
		}
		printf("%d\n", sy);
	}
	return 0;
}
