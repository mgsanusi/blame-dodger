#include <stdio.h>
#include <stdlib.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void handleCase();
int h;
int xHandy;
int file;
int pos;
int cache[6][6][6][126];
double chance[126][6][6][6];
int Main()
{
	new_freopen("c.in", "r", stdin);
	new_freopen("c.out", "w", stdout);
	int reserve;
	int n;
	scanf("%d ", &n);
	for (reserve = 0; reserve < n; reserve++) {
		printf("Case #%d: ", reserve + 1);
		handleCase();
	}
	return 0;
}

void addToCache(int *x)
{
	int reserve;
	for (reserve = 0; reserve < 8; reserve++) {
		int pro = 1;
		int ed;
		for (ed = 0; ed < 3; ed++) {
			if (reserve & (1 << ed)) {
				pro *= x[ed];
			}
		}
		cache[x[0]][x[1]][x[2]][pro]++;
	}
}

int findNumber(int *pro)
{
	int reserve;
	int ed;
	int s;
	int t;
	double best = 0.0;
	int no = 222;
	for (reserve = 2; reserve <= 5; reserve++) {
		for (ed = reserve; ed <= 5; ed++) {
			for (s = ed; s <= 5; s++) {
				double probFor = 1.0;
				for (t = 0; t < 7; t++) {
					probFor *=
					    chance[pro[t]][reserve][ed][s];
				}
				if (probFor > best) {
					best = probFor;
					no = ((reserve * 100) + (ed * 10)) + s;
				}
			}
		}
	}
	return no;
}

void handleCase()
{
	scanf("%d %d %d %d ", &h, &xHandy, &file, &pos);
	int reserve;
	int ed;
	int s;
	int t;
	for (reserve = 2; reserve <= 5; reserve++) {
		for (ed = reserve; ed <= 5; ed++) {
			for (s = ed; s <= 5; s++) {
				int x[3];
				x[0] = reserve;
				x[1] = ed;
				x[2] = s;
				addToCache(x);
			}
		}
	}
	for (t = 0; t <= 125; t++) {
		int count = 0;
		for (reserve = 2; reserve <= 5; reserve++) {
			for (ed = reserve; ed <= 5; ed++) {
				for (s = ed; s <= 5; s++) {
					count += cache[reserve][ed][s][t];
				}
			}
		}
		if (count > 0) {
			for (reserve = 2; reserve <= 5; reserve++) {
				for (ed = reserve; ed <= 5; ed++) {
					for (s = ed; s <= 5; s++) {
						chance[t][reserve][ed][s] =
						    ((double)
						     cache[reserve][ed][s][t]) /
						    ((double)count);
					}
				}
			}
		}
	}
	printf("\n");
	int sum[7];
	for (reserve = 0; reserve < h; reserve++) {
		for (ed = 0; ed < 7; ed++) {
			scanf("%d ", &sum[ed]);
		}
		printf("%d\n", findNumber(sum));
	}
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
