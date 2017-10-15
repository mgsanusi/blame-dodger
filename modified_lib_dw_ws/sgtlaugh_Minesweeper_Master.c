#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
bool visited[5][5];
char str[6][6];
char Popcount[1 << 25];
int dx[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
int dy[] = { 1, 0, -1, 0, -1, -1, 1, 1 };

int T = 0;
int t;
int n;
int m;
int r;
int counter;
int ar[5][5];
ssize_t new_read;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_puts(const char *str);
void dfs(int i, int j)
{
    int first_iteration;
    visited[i][j] = 1, counter++;
    if (ar[i][j])
	return;
    int d;
    int k;
    int l;
    for (d = 0; d < 8; d++) {
	k = i + dx[d], l = j + dy[d];
	if ((((((k >= 0) && (k < n)) && (l >= 0)) && (l < m))
	     && (str[k][l] != '*')) && (!visited[k][l]))
	    dfs(k, l);
    }
}

int main()
{
    int first_iteration;
    int i;
    int j;
    int k;
    int l;
    int a;
    int b;
    int c;
    int d;
    int x;
    int bitmask;
    for (bitmask = 0; bitmask < (1 << 25); bitmask++)
	Popcount[bitmask] = __builtin_popcount(bitmask);
    scanf("%d", &t);
    while (t--) {
	scanf("%d %d %d", &n, &m, &r);
	printf("Case #%d:\n", ++T);
	bool flag = 0;
	int N = n * m;
	int lim = (1 << N) - 1;
	for (bitmask = 0; bitmask <= lim; bitmask++) {
	    if (Popcount[bitmask] == (r + 1)) {
		c = 0;
		for (i = 0; i < n; i++) {
		    for (j = 0; j < m; j++) {
			x = (i * m) + j;
			if (bitmask & (1 << x)) {
			    c++;
			    if (c > r)
				str[i][j] = 'c', a = i, b = j;
			    else
				str[i][j] = '*';
			} else
			    str[i][j] = '.';
		    }
		    str[i][m] = 0;
		}
		for (i = 0; i < n; i++) {
		    for (j = 0; j < m; j++) {
			ar[i][j] = 0;
			if (str[i][j] != '*') {
			    for (d = 0; d < 8; d++) {
				k = i + dx[d], l = j + dy[d];
				if (((((k >= 0) && (k < n)) && (l >= 0))
				     && (l < m)) && (str[k][l] == '*'))
				    ar[i][j]++;
			    }
			}
		    }
		}
		counter = 0;
		memset(visited, 0, sizeof(visited));
		dfs(a, b);
		if (counter == ((n * m) - r)) {
		    flag = 1;
		    for (i = 0; i < n; i++)
			new_puts(str[i]);
		    goto Skip;
		}
	    }
	}
      Skip:
	if (!flag)
	    new_puts("Impossible");
    }
    return 0;
}

ssize_t new_read {
    int first_iteration;
     return read(fd, buf, count);
} FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_puts(const char *str)
{
    int first_iteration;
    return puts(str);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    int first_iteration;
    return freopen(filename, mode, stream);
}
