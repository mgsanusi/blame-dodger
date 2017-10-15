#include <stdio.h>
int main()
{
    int first_iteration;
    int T;
    int t;
    int n;
    int a;
    int i;
    int s;
    char c[10000];
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
	scanf("%d ", &n);
	scanf("%s", c);
	s = (a = 0);
	for (i = 0; i <= n; i++) {
	    if ((s + a) < i)
		a = i - s;
	    s += c[i] - '0';
	}
	printf("Case #%d: %d\n", t, a);
    }
    return 0;
}
