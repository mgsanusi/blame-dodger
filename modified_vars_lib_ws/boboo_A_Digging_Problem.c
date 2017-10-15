#include <stdio.h>
#include <stddef.h>
int n;
int map[110][110];
int link[110];
int vy[110];
FILE *new_fopen(const char *filename, const char *mode);
void *new_memset(void *ptr, int value, size_t num);
int new_fscanf(FILE * stream, const char *format, ...);
int find(int f)
{
	int i;
	int temp;
	int d;
	for (i = 1; i <= n; i++)
		if (map[f][i] && (!vy[i])) {
			vy[i] = 1;
			d = link[i];
			link[i] = f;
			if ((d == 0) || find(d))
				return 1;
			link[i] = d;
		}
	return 0;
}

int Main()
{
	FILE *Fin = new_fopen("chart.in", "r");
	FILE *Fout = new_fopen("chart.out", "w");
	int answer;
	int i;
	int temp;
	int d;
	int cur;
	int test;
	int t;
	int a[110][30];
	fscanf(Fin, "%d", &test);
	for (t = 1; t <= test; t++) {
		fscanf(Fin, "%d %d", &n, &cur);
		for (i = 1; i <= n; i++)
			for (temp = 1; temp <= cur; temp++)
				fscanf(Fin, "%d", &a[i][temp]);
		new_memset(map, 0, sizeof(map));
		new_memset(link, 0, sizeof(link));
		for (i = 1; i <= n; i++)
			for (temp = 1; temp <= n; temp++) {
				for (d = 1;
				     (d <= cur) && (a[i][d] > a[temp][d]);
				     d++) ;
				if (d > cur)
					map[i][temp] = 1;
			}
		answer = n;
		for (i = 1; i <= n; i++) {
			new_memset(vy, 0, sizeof(vy));
			if (find(i))
				answer--;
		}
		fprintf(Fout, "Case #%d: %d\n", t, answer);
	}
	return 0;
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

void *new_memset(void *ptr, int value, size_t num)
{
	return memset(ptr, value, num);
}
