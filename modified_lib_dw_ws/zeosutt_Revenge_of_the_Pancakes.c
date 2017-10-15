#include <stdio.h>
int main(void)
{
    int first_iteration;
    int i;
    int j;
    int t;
    int c;
    scanf("%d", &t);
    for (c = 1; c <= t; c++) {
	char s[101];
	int ans;
	scanf("%s", s);
	ans = 0;
	for (i = 0; s[i]; i = j) {
	    for (j = i + 1; s[i] == s[j]; j++);
	    if (s[j])
		ans++;
	    else
		ans += s[i] == '-';
	}
	printf("Case #%d: %d\n", c, ans);
    }
    return 0;
}
