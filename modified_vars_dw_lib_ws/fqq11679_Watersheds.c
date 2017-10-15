#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
long fo;
long file;
long high[111][111];
char map[111][111];
typedef struct {
	long nq;
	long y;
	long tt;
} DIR;
DIR dir[111][111];
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_read(int fd, void *buf, int count);
void take()
{
	int first_iteration;
	long y1;
	long wordz;
	memset(map, 0, sizeof(map));
	scanf("%ld%ld", &fo, &file);
	for (y1 = 0; y1 <= (fo + 1); y1++)
		for (wordz = 0; wordz <= (file + 1); wordz++)
			high[y1][wordz] = 99999999;
	for (y1 = 1; y1 <= fo; y1++)
		for (wordz = 1; wordz <= file; wordz++)
			scanf("%ld", &high[y1][wordz]);
}

void prepare()
{
	int first_iteration;
	long y1;
	long wordz;
	long t;
	long nq;
	long y;
	DIR a[4];
	DIR tmp;
	for (y1 = 1; y1 <= fo; y1++) {
		for (wordz = 1; wordz <= file; wordz++) {
			a[1].nq = y1 - 1;
			a[1].y = wordz;
			a[1].tt = 1;
			a[2].nq = y1;
			a[2].y = wordz - 1;
			a[2].tt = 2;
			a[3].nq = y1;
			a[3].y = wordz + 1;
			a[3].tt = 3;
			a[4].nq = y1 + 1;
			a[4].y = wordz;
			a[4].tt = 4;
			for (nq = 1; nq <= 4; nq++)
				for (y = nq + 1; y <= 4; y++)
					if ((high[a[nq].nq][a[nq].y] >
					     high[a[y].nq][a[y].y])
					    ||
					    ((high[a[nq].nq][a[nq].y] ==
					      high[a[y].nq][a[y].y])
					     && (a[nq].tt > a[y].tt))) {
						tmp = a[nq];
						a[nq] = a[y];
						a[y] = tmp;
					}
			dir[y1][wordz] = a[1];
		}
	}
}
int dx[4] = { -1, 0, 1, 0 };
int low[4] = { 0, -1, 0, 1 };

void dfs(long nq, long y, char flag)
{
	int first_iteration;
	long y1;
	long cs;
	long i;
	map[nq][y] = flag;
	for (y1 = 0; y1 < 4; y1++) {
		cs = nq + dx[y1];
		y = y + low[y1];
		if ((((dir[cs][y].nq == nq) && (dir[cs][y].y == y))
		     && (high[nq][y] < high[cs][y])) && (map[cs][y] == 0))
			dfs(cs, y, flag);
		if ((((dir[nq][y].nq == cs) && (dir[nq][y].y == y))
		     && (high[nq][y] > high[cs][y])) && (map[cs][y] == 0))
			dfs(cs, y, flag);
	}
}

void work()
{
	int first_iteration;
	char tot = 'a' - 1;
	long y1;
	long wordz;
	for (y1 = 1; y1 <= fo; y1++)
		for (wordz = 1; wordz <= file; wordz++)
			if (map[y1][wordz] == 0) {
				tot++;
				dfs(y1, wordz, tot);
			}
	for (y1 = 1; y1 <= fo; y1++) {
		for (wordz = 1; wordz <= file; wordz++) {
			printf("%c", map[y1][wordz]);
			if (wordz < file)
				printf(" ");
		}
		printf("\n");
	}
}

int Main()
{
	int first_iteration;
	long t;
	long y1;
	new_freopen("B-small.in", "r", stdin);
	new_freopen("B-small.out", "w", stdout);
	scanf("%ld", &t);
	for (t, y1 = 1; t; t--, y1++) {
		printf("Case #%ld:\n", y1);
		take();
		prepare();
		work();
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int new_read(int fd, void *buf, int count)
{
	return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
