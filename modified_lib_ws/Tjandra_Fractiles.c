#include<stdio.h>
typedef unsigned u;
int main() 
{
    u t = 0, T, i, k, c, s;
    for (scanf("%u", &T); t++ < T;)
	 {
	scanf("%u%u%u", &k, &c, &s);
	printf("Case #%u: ", t);
	if ((c == 1 && k > s) || k > s + 1) {
	    printf("IMPOSSIBLE\n");
	    continue;
	}
	if (c == 1 || k == 1)
	    printf("%u%c", 1, 1 == k ? '\n' : ' ');
	for (i = 1; ++i <= k;)
	    printf("%u%c", i, i == k ? '\n' : ' ');
	}
    return 0;
}


