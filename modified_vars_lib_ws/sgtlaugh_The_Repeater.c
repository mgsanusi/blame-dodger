#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
ssize_t new_read(int fd, void *buf, size_t count);
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int compare(const void *a, const void *b)
{
    return (*((int *) a)) - (*((int *) b));
}

bool visit[10010];
int e;
int p;
int m;
int rqSvccred[10010];
int Main()
{
    new_freopen("lol.txt", "r", stdin);
    new_freopen("output.txt", "w", stdout);
    int t = 0;
    int i;
    int cs;
    int k;
    scanf("%d", &e);
    while (e--) {
	scanf("%d %d", &p, &m);
	for (i = 0; i < p; i++)
	    scanf("%d", &rqSvccred[i]);
	memset(visit, 0, sizeof(visit));
	int counter = 0;
	new_qsort(rqSvccred, p, sizeof(int), compare);
	for (i = p - 1; i >= 0; i--) {
	    if (!visit[i]) {
		counter++;
		int idx = -1;
		int answer = m;
		for (cs = 0; cs < i; cs++) {
		    if (!visit[cs]) {
			if ((rqSvccred[i] + rqSvccred[cs]) <= m) {
			    int x = m - (rqSvccred[i] + rqSvccred[cs]);
			    if (x < answer)
				answer = x, idx = cs;
			}
		    }
		}
		visit[i] = 1;
		if (idx != (-1))
		    visit[idx] = 1;
	    }
	}
	printf("Case #%d: %d\n", ++t, counter);
    }
    return 0;
}

ssize_t new_read(int fd, void *buf, size_t count);
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

ssize_t new_read(int fd, void *buf, size_t count)
{
    return read(fd, buf, count);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
