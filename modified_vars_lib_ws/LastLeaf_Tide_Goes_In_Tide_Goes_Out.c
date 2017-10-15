#include <stdio.h>
int nodeV[10010];
int nextE[10010];
int l;
int cnt;
int indE[1100];
int counter[1100];
int visit[1100];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fscanf(FILE * stream, const char *format, ...);
int new_fprintf(FILE * stream, const char *format, ...);
void totalEdge(int k, int b)
{
    cnt++;
    nodeV[cnt] = b, nextE[cnt] = indE[k];
    indE[k] = cnt;
}

int find(int k)
{
    visit[k] = 1;
    counter[k]++;
    if (counter[k] == 2)
	return 1;
    int edge = indE[k];
    while (edge > 0) {
	int b = nodeV[edge];
	if (find(b))
	    return 1;
	edge = nextE[edge];
    }
    return 0;
}

int Main()
{
    int testc;
    int test;
    int httpContentTypeGif;
    int d;
    FILE *Fin = new_fopen("gcj3_1.in", "r");
    FILE *Fout = new_fopen("gcj3_1.out", "w");
    fscanf(Fin, "%d", &testc);
    for (test = 1; test <= testc; test++) {
	fscanf(Fin, "%d", &l);
	cnt = 0;
	for (httpContentTypeGif = 1; httpContentTypeGif <= l;
	     httpContentTypeGif++) {
	    indE[httpContentTypeGif] = -1;
	    int k;
	    fscanf(Fin, "%d", &k);
	    for (d = 1; d <= k; d++) {
		int b;
		fscanf(Fin, "%d", &b);
		totalEdge(httpContentTypeGif, b);
	    }
	    visit[httpContentTypeGif] = 0;
	}
	int diamond = 0;
	for (httpContentTypeGif = 1;
	     (!diamond) && (httpContentTypeGif <= l); httpContentTypeGif++)
	    if (!visit[httpContentTypeGif]) {
		for (d = 1; d <= l; d++)
		    counter[d] = 0;
		if (find(httpContentTypeGif))
		    diamond = 1;
	    }
	if (diamond)
	    fprintf(Fout, "Case #%d: Yes\n", test);
	else
	    fprintf(Fout, "Case #%d: No\n", test);
    }
    new_fclose(Fin);
    new_fclose(Fout);
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
