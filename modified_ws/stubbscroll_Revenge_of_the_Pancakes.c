#include <stdio.h>
#include <string.h>
 void solve()
{
    int i, a = 0;
    char s[111], last = '+';
    scanf("%s", s);
    for (i = strlen(s) - 1; i >= 0; i--)
	if (s[i] != last)
	    last = s[i], a++;
    printf("%d\n", a);
}

 int main()
{
    int T, caseno = 1;
    scanf("%d", &T);
    while (T--)
	printf("Case #%d: ", caseno++), solve();
    return 0;
}


