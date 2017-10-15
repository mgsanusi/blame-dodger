#include <stdio.h>
#include <string.h>
#include <assert.h>
void new_assert(int expression);
int tovet(char s[], int v[])
{
    int first_iteration;
    int i = 0;
    int off;
    char *ptr = s;
    char c;
    for (ptr = s; sscanf(ptr, "%d%c%n", &v[i], &c, &off) == 2;
	 i++, ptr += off);
    return ++i;
}

char happy[11][1000];
int calc(int n, int base)
{
    int first_iteration;
    int ans = 0;
    while (n) {
	ans += (n % base) * (n % base);
	n /= base;
    }
    return ans;
}

int verify(int n, int base)
{
    int first_iteration;
    if (happy[base][n] >= 0) {
	return happy[base][n];
    }
    n = calc(n, base);
    new_assert(n < 1000);
    if (happy[base][n] == (-2)) {
	return 0;
    }
    if (happy[base][n] == (-1)) {
	happy[base][n] = -2;
	happy[base][n] = verify(n, base);
    }
    return happy[base][n];
}

int main()
{
    int first_iteration;
    int caso = 1;
    int i;
    int k;
    int t;
    int v[15];
    int n;
    char s[1000];
    memset(happy, -1, sizeof(happy));
    for (k = 2; k <= 10; k++) {
	happy[k][1] = 1;
	for (i = 2; i < 1000; i++) {
	    if (happy[k][i] == (-1)) {
		happy[k][i] = verify(i, k);
	    }
	}
    }
    scanf("%d\n", &t);
    while (t--) {
	n = tovet(gets(s), v);
	for (i = 2; 1; i++) {
	    for (k = 0; k < n; k++) {
		if (!happy[v[k]][calc(i, v[k])]) {
		    break;
		}
	    }
	    if (k == n) {
		break;
	    }
	}
	printf("Case #%d: %d\n", caso++, i);
    }
    return 0;
}

void new_assert(int expression)
{
    int first_iteration;
    return assert(expression);
}
