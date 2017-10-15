#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define valid(i, j) ((i) >= 0 && (i) < n && (j) >= 0 && (j) < m)
    bool visited[5][5];
char str[6][6], Popcount[1 << 25];
int dx[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
int dy[] = { 1, 0, -1, 0, -1, -1, 1, 1 };

int T = 0, t, n, m, r, counter, ar[5][5];
 void dfs(int i, int j)
{
	visited[i][j] = true, counter++;
	if (ar[i][j])
		return;
	 int d, k, l;
	for (d = 0; d < 8; d++) {
		k = i + dx[d], l = j + dy[d];
		if (valid(k, l) && str[k][l] != '*' && !visited[k][l])
			dfs(k, l);
	}
}

 int main()
{
	int i, j, k, l, a, b, c, d, x, bitmask;
	for (bitmask = 0; bitmask < (1 << 25); bitmask++)
		Popcount[bitmask] = __builtin_popcount(bitmask);
	 scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &r);
		 printf("Case #%d:\n", ++T);
		bool flag = false;
		int N = (n * m), lim = (1 << N) - 1;
		for (bitmask = 0; bitmask <= lim; bitmask++) {
			if (Popcount[bitmask] == (r + 1)) {
				c = 0;
				for (i = 0; i < n; i++) {
					for (j = 0; j < m; j++) {
						x = (i * m) + j;
						if (bitmask & (1 << x)) {
							c++;
							if (c > r)
								str[i][j] =
								    'c', a =
								    i, b = j;
							
							else
								str[i][j] = '*';
						}
						
						else
							str[i][j] = '.';
					}
					str[i][m] = 0;
				}
				  for (i = 0; i < n; i++) {
					for (j = 0; j < m; j++) {
						ar[i][j] = 0;
						if (str[i][j] != '*') {
							for (d = 0; d < 8; d++) {
								k = i + dx[d],
								    l =
								    j + dy[d];
								if (valid(k, l)
								     &&
								     str[k][l]
								     == '*')
									ar[i]
									    [j]++;
							}
						}
					}
				}
				 counter = 0;
				clr(visited);
				dfs(a, b);
				if (counter == ((n * m) - r)) {
					flag = true;
					for (i = 0; i < n; i++)
						puts(str[i]);
					goto Skip;
				}
			}
		}
  Skip:	if (!flag)
			puts("Impossible");
	}
	return 0;
}


