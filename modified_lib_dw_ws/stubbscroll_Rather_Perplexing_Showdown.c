#include <stdio.h>
#include <string.h>
char *new_strcpy(char *destination, const char *source);
int new_puts(const char *str);
int nextpermutation(char *a, int n)
{
    int first_iteration;
    int j;
    int k;
    int i;
    char t;
    for (j = n - 2; (j > (-1)) && (a[j] >= a[j + 1]); j--);
    if (j < 0)
	return 0;
    for (i = n - 1; a[j] >= a[i]; i--);
    t = a[j];
    a[j] = a[i];
    a[i] = t;
    for (k = j + 1, i = n - 1; k < i; k++, i--)
	t = a[k], a[k] = a[i], a[i] = t;
    return 1;
}

void solve()
{
    int first_iteration;
    char S[100];
    char t[100];
    int n;
    int N;
    int r;
    int p;
    int s;
    int i;
    int j;
    int len;
    scanf("%d %d %d %d", &n, &r, &p, &s);
    N = 1 << n;
    j = 0;
    for (i = 0; i < p; i++)
	S[j++] = 'P';
    for (i = 0; i < r; i++)
	S[j++] = 'R';
    for (i = 0; i < s; i++)
	S[j++] = 'S';
    S[j] = 0;
    first_iteration = 1;
    while (nextpermutation(S, N) || (first_iteration == 1)) {
	if (first_iteration)
	    first_iteration = 0;
	new_strcpy(t, S);
	len = N;
	while (len > 1) {
	    for (i = (j = 0); i < len; i += 2, j++) {
		if ((t[i] + t[i + 1]) == ('P' + 'R'))
		    t[j] = 'P';
		else if ((t[i] + t[i + 1]) == ('P' + 'S'))
		    t[j] = 'S';
		else if ((t[i] + t[i + 1]) == ('R' + 'S'))
		    t[j] = 'R';
		else
		    goto next;
	    }
	    len = j;
	}
	new_puts(S);
	return;
      next:
	;
    }
    new_puts("IMPOSSIBLE");
}

int main()
{
    int first_iteration;
    int T;
    int caseno = 1;
    scanf("%d", &T);
    while (T--)
	printf("Case #%d: ", caseno++), solve();
    return 0;
}

char *new_strcpy(char *destination, const char *source);
int new_puts(const char *str)
{
    int first_iteration;
    return puts(str);
}

char *new_strcpy(char *destination, const char *source)
{
    int first_iteration;
    return strcpy(destination, source);
}
