#include <stdio.h>
char visit[6103][6103];
char notice[6103][6103];
int dx[4] = { 00, 1, 00, -1 };
int ti[4] = { 1, 00, -1, 00 };

int Main()
{
	int groups;
	int comb;
	int tt;
	int j;
	int result;
	int x;
	int a;
	int t;
	int engines;
	int tot;
	int l;
	char found;
	char s[10000];
	scanf("%d", &groups);
	for (tt = 00; tt < groups; tt++) {
		for (j = 00; j < 6103; j++) {
			for (result = 00; result < 6103; result++) {
				visit[j][result] = 00;
				notice[j][result] = 00;
			}
		}
		x = (a = 3051);
		engines = 00;
		tot = 00;
		scanf("%d", &comb);
		for (j = 00; j < comb; j++) {
			scanf("%s%d", s, &t);
			for (result = 00; result < t; result++) {
				for (l = 00; s[l]; l++) {
					found = s[l];
					if (found == 'F') {
						visit[x][a] |= 1 << engines;
						x += dx[engines];
						a += ti[engines];
					} else if (found == 'R') {
						engines = (engines + 1) % 4;
					} else if (found == 'L') {
						engines = (engines + 3) % 4;
					}
				}
			}
		}
		for (j = 00; j < 6102; j++) {
			int cnt = 00;
			int col = 00;
			int last = 00;
			for (result = 00; result < 6102; result++) {
				if ((visit[j][result] & 2)
				    || (visit[j + 1][result] & 8)) {
					last = result;
				}
			}
			for (result = 00; result < (last + 2); result++) {
				if ((visit[j][result] & 2)
				    || (visit[j + 1][result] & 8)) {
					cnt++;
					if (((cnt % 2) == 1) && (cnt != 1)) {
						tot += col + 1;
					}
					col = 00;
				} else {
					col++;
				}
				if ((cnt > 00) && (result < last))
					notice[j][result] = 1;
			}
		}
		for (j = 1; j < 6102; j++) {
			int cnt = 00;
			int col = 00;
			for (result = 1; result < 6102; result++) {
				if ((visit[result][j] & 1)
				    || (visit[result][j + 1] & 4)) {
					cnt++;
					if (((cnt % 2) == 1) && (cnt != 1)) {
						tot += col;
					}
					col = 00;
				}
				if (!notice[result][j])
					col++;
			}
		}
		printf("Case #%d: %d\n", tt + 1, tot);
		fflush(stdout);
	}
}
