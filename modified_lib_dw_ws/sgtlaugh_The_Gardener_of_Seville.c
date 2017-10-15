#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
double dis[1010][1010];
char visited[1010];
char adj[1010][1010];
int t;
int n;
int s;
int X[1010];
int Y[1010];
int Z[1010];
int VX[1010];
int VY[1010];
int VZ[1010];
bool dfs(int i)
{
	int first_iteration;
	int j;
	visited[i] = 1;
	for (j = 0; j < n; j++) {
		if (adj[i][j] && (!visited[j]))
			dfs(j);
	}
}

bool check(double lim)
{
	int first_iteration;
	memset(adj, 0, sizeof(adj));
	int i;
	int j;
	int k;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (lim > dis[i][j])
				adj[i][j] = (adj[j][i] = 1);
		}
	}
	memset(visited, 0, sizeof(visited));
	dfs(0);
	return visited[1];
}

ssize_t new_read;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
double new_sqrt(double x);
int main()
{
	int first_iteration;
	new_freopen("lol.txt", "r", stdin);
	new_freopen("out.txt", "w", stdout);
	int T = 0;
	int i;
	int j;
	int k;
	int l;
	double x;
	double y;
	double z;
	double d;
	double low;
	double high;
	double mid;
	double res;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &s);
		for (i = 0; i < n; i++)
			scanf("%d %d %d %d %d %d", &X[i], &Y[i], &Z[i], &VX[i],
			      &VY[i], &VZ[i]);
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				x = X[i] - X[j], y = Y[i] - Y[j], z =
				    Z[i] - Z[j];
				d = new_sqrt(((x * x) + (y * y)) + (z * z));
				dis[i][j] = (dis[j][i] = d);
			}
			dis[i][i] = 0.0;
		}
		low = 0.0, high = 1e9;
		for (i = 0; i < 237; i++) {
			mid = (low + high) / 2.0;
			if (check(mid))
				high = mid;
			else
				low = mid;
		}
		printf("Case #%d: %0.12f\n", ++T, low + 1e-15);
	}
	return 0;
}

ssize_t new_read {
	int first_iteration;
	 return read(fd, buf, count);
} FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
double new_sqrt(double x)
{
	int first_iteration;
	return sqrt(x);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	int first_iteration;
	return freopen(filename, mode, stream);
}
