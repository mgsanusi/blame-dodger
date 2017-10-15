#include <stdio.h>
char t[64][64];
char pd[64][64];
int n;
int k;
void rot()
{
	int i;
	int j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			pd[(n - j) - 1][i] = t[i][j];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			t[i][j] = pd[i][j];
}

void fall()
{
	int i;
	int j;
	int r;
	for (i = 0; i < n; i++) {
		j = n - 1;
		for (r = n - 1; r >= 0; r--)
			if (t[r][i] != '.')
				t[j--][i] = t[r][i];
		while (j >= 0)
			t[j--][i] = '.';
	}
}
int dx[] = { 1, 1, 0, -1 };
int t[] = { 0, 1, 1, 1 };

int check(char p)
{
	int i;
	int j;
	int r;
	int a;
	int b;
	int y;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (t[i][j] == p) {
				for (r = 0; r < 4; r++) {
					for (a = 1; a < k; a++) {
						b = i + (dx[r] * a);
						y = j + (t[r] * a);
						if ((((b < 0) || (y < 0))
						     || (b >= n)) || (y >= n))
							break;
						if (t[b][y] != p)
							break;
					}
					if (a == k)
						return 1;
				}
			}
	return 0;
}

int Main()
{
	int cases;
	int caseno = 1;
	int i;
	int result;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d %d", &n, &k);
		for (i = 0; i < n; i++)
			scanf("%s", t[i]);
		rot();
		rot();
		rot();
		fall();
		result = check('R') + (2 * check('B'));
		printf("Case #%d: %s\n", caseno++,
		       result < 2 ? result ? "Red" : "Neither" : result >
		       2 ? "Both" : "Blue");
	}
	return 0;
}
