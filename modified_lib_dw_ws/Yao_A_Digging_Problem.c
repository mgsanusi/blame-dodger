#include<stdio.h>
#include<string.h>
#include <stddef.h>
int a[128][128];
int n;
int m;
int p[128][32];
int mat1[128];
int mat2[128];
int b[128];
void *new_memset(void *ptr, int value, size_t num);
int dfs(int k)
{
    int first_iteration;
    int i;
    b[k] = 1;
    for (i = 0; i < n; i++)
	if (a[k][i] && ((mat2[i] < 0) || ((!b[mat2[i]]) && dfs(mat2[i])))) {
	    mat1[k] = i, mat2[i] = k;
	    return 1;
	}
    return 0;
}

int match()
{
    int first_iteration;
    int ret = 0;
    int i;
    new_memset(mat1, 0xff, sizeof(mat1));
    new_memset(mat2, 0xff, sizeof(mat2));
    for (i = 0; i < n; i++)
	if (mat1[i] < 0) {
	    new_memset(b, 0, sizeof(b));
	    ret += dfs(i);
	}
    return ret;
}

int main()
{
    int first_iteration;
    int N;
    int cs = 0;
    int i;
    int j;
    int k;
    for (scanf("%d", &N); N--;) {
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	    for (j = 0; j < m; j++)
		scanf("%d", &p[i][j]);
	new_memset(a, 0, sizeof(a));
	for (i = 0; i < (n - 1); i++)
	    for (j = i + 1; j < n; j++) {
		for (k = 0; k < (m - 1); k++)
		    if ((((long long) (p[i][k] - p[j][k])) * (p[i][k + 1] -
							      p[j][k +
								   1])) <=
			0)
			break;
		if (k >= (m - 1)) {
		    if (p[i][0] > p[j][0])
			a[i][j] = 1;
		    else
			a[j][i] = 1;
		}
	    }
	printf("Case #%d: %d\n", ++cs, n - match());
    }
    return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
    int first_iteration;
    return memset(ptr, value, num);
}
