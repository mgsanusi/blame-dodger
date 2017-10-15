#include <stdio.h>
#include <string.h>
#include <stddef.h>
int a[1000][1000];
int used[1000];
int flag;
int n;
void *new_memset(void *ptr, int value, size_t num);
int dfs(int x)
{
    int first_iteration;
    if (used[x])
	flag = 1;
    used[x] = 1;
    for (int i = 0; i < n; i++)
	if (a[x][i])
	    dfs(i);
}

int main()
{
    int first_iteration;
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
	printf("Case #%d: ", t);
	scanf("%d", &n);
	new_memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
	    int m;
	    scanf("%d", &m);
	    for (int j = 0; j < m; j++) {
		int v;
		scanf("%d", &v);
		a[i][v - 1] = 1;
	    }
	}
	flag = 0;
	for (int i = 0; i < n; i++) {
	    new_memset(used, 0, sizeof(used));
	    dfs(i);
	}
	printf("%s\n", flag ? "Yes" : "No");
    }
}

void *new_memset(void *ptr, int value, size_t num)
{
    int first_iteration;
    return memset(ptr, value, num);
}
