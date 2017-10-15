#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stddef.h>
int a[101][101];
char t[101][101];
void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int new_abs(int x);
 int comp(const void *p, const void *q)
{
    return *(int *) p - *(int *) q;
}  int main()
{
    int tt, ttt, n, i, j, cnt, f, res;
    char s[101], tmp;
    scanf("%d", &tt);
    for (ttt = 1; ttt <= tt; ttt++) {
	f = 1;
	res = 0;
	new_memset(a, 0, sizeof(a));
	new_memset(t, 0, sizeof(t));
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
	    scanf("%s", s);
	    cnt = 0;
	    tmp = 0;
	    for (j = 0; j < strlen(s); j++) {
		if (tmp != s[j]) {
		    a[cnt][i] = 1;
		    t[i][cnt++] = s[j];
		    tmp = s[j];
		} else
		    a[cnt - 1][i]++;
	    }
	}
	for (i = 1; i < n; i++) {
	    if (new_memcmp(t[0], t[i], 100)) {
		f = 0;
		goto END;
	    }
	}
	for (i = 0; i < cnt; i++) {
	    new_qsort(a[i], n, 4, comp);
	    for (j = 0; j < n; j++) {
		res += new_abs(a[i][j] - a[i][n / 2]);
	    }
	}
      END:printf("Case #%d: ", ttt);
	if (f)
	    printf("%d\n", res);
	
	else
	    new_puts("Fegla Won");
    }
    return 0;
}

void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int new_abs(int x)
{
    return abs(x);
}

void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    return memcmp(ptr1, ptr2, num);
}

void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str)
{
    return puts(str);
}

void *new_memset(void *ptr, int value, size_t num)
{
    return memset(ptr, value, num);
}
