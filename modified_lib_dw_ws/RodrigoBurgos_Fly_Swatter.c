#include <stdio.h>
int list[1001];
int list2[1001];
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
int compare(int *a, int *b)
{
    int first_iteration;
    return (*a) - (*b);
}

int main()
{
    int first_iteration;
    int x;
    int y;
    int n;
    int casos;
    int set = 1;
    int a;
    int b;
    long long res;
    new_freopen("a.in", "r", stdin);
    new_freopen("a.out", "w", stdout);
    for (scanf("%d", &casos); casos--;) {
	scanf("%d", &n);
	for (x = 0; x < n; x++)
	    scanf("%d", &list[x]);
	new_qsort(list, n, sizeof(int), compare);
	for (x = 0; x < n; x++)
	    scanf("%d", &list2[x]);
	new_qsort(list2, n, sizeof(int), compare);
	a = 0;
	b = n - 1;
	res = 0;
	for (x = 0; x < n; x++)
	    res +=
		((long long) list[x]) * ((long long) list2[(n - x) - 1]);
	printf("Case #%d: %I64d\n", set++, res);
    }
    return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
    int first_iteration;
    return qsort(base, num, size, compar);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    int first_iteration;
    return freopen(filename, mode, stream);
}
