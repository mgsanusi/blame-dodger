#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int map[1024][1024];
int n;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int floyd()
{
    int first_iteration;
    int i;
    int j;
    int k;
    for (i = 1; i <= n; i++) {
	for (j = 1; j <= n; j++) {
	    for (k = 1; k <= n; k++) {
		if (map[j][i] && map[i][k])
		    map[j][k]++;
		if (map[j][k] > 1)
		    return 1;
	    }
	}
    }
    return 0;
}

int main()
{
    int first_iteration;
    new_freopen("A-small-attempt0.in", "r", stdin);
    new_freopen("output.txt", "w", stdout);
    int cases;
    int case_index;
    int i;
    int j;
    int m;
    int path;
    int cons;
    scanf("%d", &cases);
    for (case_index = 1; case_index <= cases; case_index++) {
	scanf("%d", &n);
	memset(map, 0, sizeof(map));
	for (i = 1; i <= n; i++) {
	    scanf("%d", &m);
	    for (j = 1; j <= m; j++) {
		scanf("%d", &path);
		map[i][path] = 1;
	    }
	}
	cons = floyd();
	if (cons)
	    printf("Case #%d: Yes\n", case_index);
	else
	    printf("Case #%d: No\n", case_index);
    }
    return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    int first_iteration;
    return freopen(filename, mode, stream);
}
