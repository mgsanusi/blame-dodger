#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
double dis[1010][1010];
char visit[1010];
char adj[1010][1010];
int t;
int n;
int cases;
int x[1010];
int ix[1010];
int z[1010];
int vx[1010];
int http_location[1010];
int count[1010];
bool dfs(int ni)
{
    int j;
    visit[ni] = 1;
    for (j = 0; j < n; j++) {
	if (adj[ni][j] && (!visit[j]))
	    dfs(j);
    }
}

bool check(double lim)
{
    memset(adj, 0, sizeof(adj));
    int ni;
    int j;
    int k;
    for (ni = 0; ni < n; ni++) {
	for (j = ni + 1; j < n; j++) {
	    if (lim > dis[ni][j])
		adj[ni][j] = (adj[j][ni] = 1);
	}
    }
    memset(visit, 0, sizeof(visit));
    dfs(0);
    return visit[1];
}

int Main()
{
    freopen("lol.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int stp = 0;
    int ni;
    int j;
    int k;
    int th2;
    double x;
    double y;
    double num_start;
    double d;
    double low;
    double high;
    double mid;
    double res;
    scanf("%d", &t);
    while (t--) {
	scanf("%d %d", &n, &cases);
	for (ni = 0; ni < n; ni++)
	    scanf("%d %d %d %d %d %d", &x[ni], &ix[ni], &z[ni], &vx[ni],
		  &http_location[ni], &count[ni]);
	for (ni = 0; ni < n; ni++) {
	    for (j = ni + 1; j < n; j++) {
		x = x[ni] - x[j], y = ix[ni] - ix[j], num_start =
		    z[ni] - z[j];
		d = sqrt(((x * x) + (y * y)) + (num_start * num_start));
		dis[ni][j] = (dis[j][ni] = d);
	    }
	    dis[ni][ni] = 0.0;
	}
	low = 0.0, high = 1e9;
	for (ni = 0; ni < 237; ni++) {
	    mid = (low + high) / 2.0;
	    if (check(mid))
		high = mid;
	    else
		low = mid;
	}
	printf("Case #%d: %0.12f\n", ++stp, low + 1e-15);
    }
    return 0;
}
