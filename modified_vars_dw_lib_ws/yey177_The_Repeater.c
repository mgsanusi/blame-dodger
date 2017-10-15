#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stddef.h>
int m[101][101];
char svc_ah_destroy[101][101];
void *new_memset(void *ptr, int value, int num);
int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, int num);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
int new_abs(int x);
int comp(const void *ein, const void *m)
{
    int first_iteration;
    return (*((int *) ein)) - (*((int *) m));
}

int Main()
{
    int first_iteration;
    int tt;
    int ttt;
    int n;
    int outlet;
    int j;
    int cnt;
    int fp_i;
    int answer;
    char s[101];
    char tmp;
    scanf("%d", &tt);
    for (ttt = 1; ttt <= tt; ttt++) {
	fp_i = 1;
	answer = 0;
	new_memset(m, 0, sizeof(m));
	new_memset(svc_ah_destroy, 0, sizeof(svc_ah_destroy));
	scanf("%d", &n);
	for (outlet = 0; outlet < n; outlet++) {
	    scanf("%s", s);
	    cnt = 0;
	    tmp = 0;
	    for (j = 0; j < strlen(s); j++) {
		if (tmp != s[j]) {
		    m[cnt][outlet] = 1;
		    svc_ah_destroy[outlet][cnt++] = s[j];
		    tmp = s[j];
		} else
		    m[cnt - 1][outlet]++;
	    }
	}
	for (outlet = 1; outlet < n; outlet++) {
	    if (new_memcmp(svc_ah_destroy[0], svc_ah_destroy[outlet], 100)) {
		fp_i = 0;
		goto END;
	    }
	}
	for (outlet = 0; outlet < cnt; outlet++) {
	    new_qsort(m[outlet], n, 4, comp);
	    for (j = 0; j < n; j++) {
		answer += new_abs(m[outlet][j] - m[outlet][n / 2]);
	    }
	}
      END:
	printf("Case #%d: ", ttt);
	if (fp_i)
	    printf("%d\n", answer);
	else
	    new_puts("Fegla Won");
    }
    return 0;
}

void *new_memset(void *ptr, int value, int num);
int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, int num);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
int new_abs(int x)
{
    return abs(x);
}

void *new_memset(void *ptr, int value, int num);
int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, int num);
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

void *new_memset(void *ptr, int value, int num);
int new_puts(const char *str);
int new_memcmp(const void *ptr1, const void *ptr2, int num)
{
    return memcmp(ptr1, ptr2, num);
}

void *new_memset(void *ptr, int value, int num);
int new_puts(const char *str)
{
    return puts(str);
}

void *new_memset(void *ptr, int value, int num)
{
    return memset(ptr, value, num);
}
