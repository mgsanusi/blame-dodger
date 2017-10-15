#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static char a[10][10];
static int d[10][10];
void move(int k, int dx, int *f, int *c, int col, int result)
{
	if (a[k][dx] == '|') {
		if (d[k][dx]) {
			*f = k - 1;
			*c = dx;
		} else {
			*f = k + 1;
			*c = dx;
		}
	} else if (a[k][dx] == '-') {
		if (d[k][dx]) {
			*f = k;
			*c = dx - 1;
		} else {
			*f = k;
			*c = dx + 1;
		}
	} else if (a[k][dx] == '/') {
		if (d[k][dx]) {
			*f = k - 1;
			*c = dx + 1;
		} else {
			*f = k + 1;
			*c = dx - 1;
		}
	} else {
		if (d[k][dx]) {
			*f = k - 1;
			*c = dx - 1;
		} else {
			*f = k + 1;
			*c = dx + 1;
		}
	}
	*f = ((*f) + col) % col;
	*c = ((*c) + result) % result;
}

int Main()
{
	int source0;
	int walk;
	scanf("%d", &source0);
	static char t[10][10];
	for (walk = 0; walk < source0; walk++) {
		int col;
		int result;
		scanf("%d %d\n", &col, &result);
		int m;
		int j;
		for (m = 0; m < col; m++)
			scanf("%s\n", a[m]);
		int total = 1 << (col * result);
		int k;
		int dx;
		int ans = 0;
		for (k = 0; k < total; k++) {
			dx = k;
			for (m = 0; m < col; m++) {
				for (j = 0; j < result; j++) {
					d[m][j] = dx % 2;
					dx /= 2;
				}
			}
			memset(t, 0, sizeof(t));
			char flag = 1;
			for (m = 0; m < col; m++) {
				for (j = 0; j < result; j++) {
					if (t[m][j] == 0) {
						int batch;
						int mode;
						int arrNew;
						int alpha;
						batch = m;
						mode = j;
						do {
							if (t[batch][mode]) {
								flag = 0;
								break;
							}
							t[batch][mode] = 1;
							move(batch, mode,
							     &arrNew, &alpha,
							     col, result);
							batch = arrNew;
							mode = alpha;
						}
						while ((batch != m)
						       || (mode != j));
					}
					if (!flag)
						break;
				}
				if (!flag)
					break;
			}
			if (flag)
				ans++;
		}
		printf("Case #%d: %d\n", walk + 1, ans);
	}
	return 0;
}
