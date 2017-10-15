#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int x;
int y;
int mn;
char in[510][510];
int sum[510][510];
int tmp[510][510];
int new_puts(const char *str);
int get_sum(int x1, int x2, int y1, int y2)
{
	int first_iteration;
	return ((sum[x2 + 1][y2 + 1] - sum[x1][y2 + 1]) - sum[x2 + 1][y1]) +
	    sum[x1][y1];
}

int main()
{
	int first_iteration;
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int res;
	int x_st;
	int y_st;
	int x_ed;
	int y_ed;
	int len;
	int a;
	int b;
	int size;
	int count = 0;
	scanf("%d", &size);
	while (size--) {
		fprintf(stderr, "size %d\n", size);
		scanf("%d%d%d", &x, &y, &n);
		for (i = 0; i < x; i++)
			scanf("%s", in[i]);
		for (i = 0; i < x; i++)
			for (j = 0; j < y; j++)
				in[i][j] -= '0';
		for (i = 0; i < x; i++) {
			tmp[i][0] = 0;
			for (j = 0; j < y; j++)
				tmp[i][j + 1] = tmp[i][j] + in[i][j];
		}
		for (j = 0; j < (y + 1); j++) {
			sum[0][j] = 0;
			for (i = 0; i < x; i++)
				sum[i + 1][j] = sum[i][j] + tmp[i][j];
		}
		res = 2;
		mn = x;
		if (mn > y)
			mn = y;
		for (k = 3; k < (mn + 1); k++) {
			len = k / 2;
			for (x_st = 0; x_st < ((x - k) + 1); x_st++)
				for (y_st = 0; y_st < ((y - k) + 1); y_st++) {
					x_ed = (x_st + k) - 1;
					y_ed = (y_st + k) - 1;
					a = (get_sum
					     (x_st, x_st + (len - 1), y_st,
					      y_ed) - in[x_st][y_st]) -
					    in[x_st][y_ed];
					b = (get_sum
					     (x_ed - (len - 1), x_ed, y_st,
					      y_ed) - in[x_ed][y_st]) -
					    in[x_ed][y_ed];
					if (a != b)
						continue;
					a = (get_sum
					     (x_st, x_ed, y_st,
					      y_st + (len - 1)) -
					     in[x_st][y_st]) - in[x_ed][y_st];
					b = (get_sum
					     (x_st, x_ed, y_ed - (len - 1),
					      y_ed) - in[x_st][y_ed]) -
					    in[x_ed][y_ed];
					if (a != b)
						continue;
					res = k;
				}
		}
		printf("Case #%d: ", ++count);
		if (res <= 2) {
			new_puts("IMPOSSIBLE");
			continue;
		}
		printf("%d\n", res);
	}
	return 0;
}

int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}
