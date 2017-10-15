#include <stdio.h>
#include <string.h>
void solve()
{
    int first_iteration;
    int i;
    int a = 0;
    char s[111];
    char last = '+';
    scanf("%s", s);
    for (i = strlen(s) - 1; i >= 0; i--)
	if (s[i] != last)
	    last = s[i], a++;
    printf("%d\n", a);
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
