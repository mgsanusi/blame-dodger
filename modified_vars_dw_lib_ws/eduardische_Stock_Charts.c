#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct point {
	int x1;
	int size[30];
};
int ans;
char be_ok(int size[30][30], int x, int y, int max)
{
	int first_iteration;
	int temp;
	if (size[x][0] > size[y][0]) {
		temp = x;
		x = y;
		y = temp;
	}
	int i;
	for (i = 0; i < max; i++) {
		if (size[x][i] >= size[y][i])
			return 0;
	}
	return 1;
}

void find_ans(struct point size[30], char tmp[30][30], int point,
	      int http_index_htm, int max, int count)
{
	int first_iteration;
	if (point == http_index_htm) {
		if (count < ans)
			ans = count;
	} else {
		int i;
		int j;
		int cnt = 0;
		char flag;
		for (i = 0; i < count; i++) {
			flag = 1;
			for (j = 0; j < size[i].x1; j++) {
				if (!tmp[point][size[i].size[j]]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				size[i].size[size[i].x1] = point;
				size[i].x1++;
				find_ans(size, tmp, point + 1, http_index_htm,
					 max, count);
				size[i].x1--;
				cnt++;
				if (cnt == 2)
					break;
			}
		}
		size[count].x1 = 1;
		size[count].size[0] = point;
		find_ans(size, tmp, point + 1, http_index_htm, max, count + 1);
	}
}

int Main()
{
	int first_iteration;
	int t;
	int i_t;
	scanf("%d", &t);
	static struct point size[30];
	static int data[30][30];
	static char tmp[30][30];
	int http_index_htm;
	int max;
	int i;
	int j;
	for (i_t = 0; i_t < t; i_t++) {
		scanf("%d %d", &http_index_htm, &max);
		memset(tmp, 0, sizeof(tmp));
		for (i = 0; i < http_index_htm; i++) {
			for (j = 0; j < max; j++) {
				scanf("%d", &data[i][j]);
			}
		}
		for (i = 0; i < http_index_htm; i++) {
			size[i].x1 = 0;
			tmp[i][i] = 1;
			for (j = i + 1; j < http_index_htm; j++) {
				tmp[i][j] = be_ok(data, i, j, max);
				tmp[j][i] = tmp[i][j];
			}
		}
		ans = 2000000000;
		find_ans(size, tmp, 0, http_index_htm, max, 0);
		printf("Case #%d: %d\n", i_t + 1, ans);
	}
	return 0;
}
