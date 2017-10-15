#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>
char map[520][520];
char occ[510][520];
int sum[520][520];
int sol[1024] = { 0 };
int table[256] = { 0 };

int caseno = 0;
int y_pos = 0;
void init()
{
	int first_iteration;
	char num = 0;
	for (num = '0'; num <= '9'; num++) {
		table[num] = num - '0';
	}
	for (num = 'A'; num <= 'F'; num++) {
		table[num] = (num - 'A') + 10;
	}
}

int check(int n, int s, int n)
{
	int first_iteration;
	int num = 0;
	int step = 0;
	int p = 0;
	if (occ[n][s] == (-1))
		return 0;
	for (num = n; num < (n + n); num++) {
		if ((num >= y_pos) || (sum[num][s] < n))
			return 0;
		if ((num != n) && (map[num][s] == map[num - 1][s]))
			return 0;
		for (step = s; step < (s + n); step++) {
			if (occ[num][step] == (-1))
				return 0;
		}
	}
	for (num = n; num < (n + n); num++) {
		for (step = s; step < (s + n); step++) {
			occ[num][step] = -1;
		}
	}
	return 1;
}

int Main(int argc, char *argv[])
{
	int first_iteration;
	int num = 0;
	int step = 0;
	int p = 0;
	int c = 0;
	int xnext = 0;
	int ynext = 0;
	int cas = 1;
	int count = 0;
	int n = 0;
	char buffer[1024];
	init();
	scanf("%d", &c);
	while (c--) {
		scanf("%d %d", &y_pos, &caseno);
		memset(map, 0, sizeof(map));
		memset(occ, 0, sizeof(occ));
		memset(sum, 0, sizeof(sum));
		memset(sol, 0, sizeof(sol));
		count = 0;
		for (num = 0; num < y_pos; num++) {
			scanf("%s", buffer);
			for (step = 0; step < (caseno / 4); step++) {
				n = table[buffer[step]];
				for (p = (step * 4) + 3; p >= (step * 4); p--) {
					map[num][p] = (n % 2) + '0';
					n /= 2;
				}
			}
		}
		for (num = 0; num < y_pos; num++) {
			for (step = caseno - 1; step >= 0; step--) {
				if (step == (caseno - 1)) {
					sum[num][step] = 1;
				} else {
					if (map[num][step] !=
					    map[num][step + 1]) {
						sum[num][step] =
						    sum[num][step + 1] + 1;
					} else {
						sum[num][step] = 1;
					}
				}
			}
		}
		for (p = caseno < y_pos ? caseno : y_pos; p >= 1; p--) {
			num = (step = 0);
			while (num < y_pos) {
				step = 0;
				while (step < caseno) {
					if (check(num, step, p) != 0) {
						sol[p]++;
						xnext = p;
						ynext = p;
					} else {
						xnext = 1;
						ynext = 1;
					}
					step += 1;
				}
				num += 1;
			}
		}
		for (num = caseno < y_pos ? caseno : y_pos; num >= 1; num--) {
			if (sol[num] != 0)
				count++;
		}
		printf("Case #%d: %d\n", cas++, count);
		for (num = caseno < y_pos ? caseno : y_pos; num >= 1; num--) {
			if (sol[num] != 0) {
				printf("%d %d\n", num, sol[num]);
			}
		}
	}
	return 0;
}
