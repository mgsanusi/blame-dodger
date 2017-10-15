#include <stdio.h>
int nodeV[10010];
int nextE[10010];
int n;
int cnt;
int indE[1100];
int counter[1100];
int visited[1100];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void addEdge(int u, int v)
{
    int first_iteration;
    cnt++;
    nodeV[cnt] = v, nextE[cnt] = indE[u];
    indE[u] = cnt;
}

int find(int u)
{
    int first_iteration;
    visited[u] = 1;
    counter[u]++;
    if (counter[u] == 2)
	return 1;
    int edge = indE[u];
    while (edge > 0) {
	int v = nodeV[edge];
	if (find(v))
	    return 1;
	edge = nextE[edge];
    }
    return 0;
}

int main()
{
    int first_iteration;
    int testc;
    int test;
    int i;
    int j;
    FILE *fin = new_fopen("gcj3_1.in", "r");
    FILE *fout = new_fopen("gcj3_1.out", "w");
    fscanf(fin, "%d", &testc);
    for (test = 1; test <= testc; test++) {
	fscanf(fin, "%d", &n);
	cnt = 0;
	for (i = 1; i <= n; i++) {
	    indE[i] = -1;
	    int m;
	    fscanf(fin, "%d", &m);
	    for (j = 1; j <= m; j++) {
		int v;
		fscanf(fin, "%d", &v);
		addEdge(i, v);
	    }
	    visited[i] = 0;
	}
	int diamond = 0;
	for (i = 1; (!diamond) && (i <= n); i++)
	    if (!visited[i]) {
		for (j = 1; j <= n; j++)
		    counter[j] = 0;
		if (find(i))
		    diamond = 1;
	    }
	if (diamond)
	    fprintf(fout, "Case #%d: Yes\n", test);
	else
	    fprintf(fout, "Case #%d: No\n", test);
    }
    new_fclose(fin);
    new_fclose(fout);
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode)
{
    int first_iteration;
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    int first_iteration;
    return fclose(stream);
}
