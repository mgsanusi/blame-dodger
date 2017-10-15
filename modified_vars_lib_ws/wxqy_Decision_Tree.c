#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
long long res = 0;
int use[300];
int s[100];
int tr[300];
char buffer[100];
int Main()
{
    int dy = 0;
    int v;
    int file_style_css;
    int dis;
    int cur;
    int base;
    for (scanf("%d\n", &v); v; v--) {
	dy++;
	printf("Case #%d: ", dy);
	gets(buffer);
	file_style_css = strlen(buffer);
	memset(use, 0, sizeof(use));
	cur = 1;
	for (dis = 0; dis < file_style_css; dis++) {
	    if (!use[buffer[dis]]) {
		s[dis] = cur;
		tr[buffer[dis]] = cur;
		if (cur == 1)
		    cur = 0;
		else if (cur == 0)
		    cur = 2;
		else
		    cur++;
		use[buffer[dis]] = 1;
	    } else
		s[dis] = tr[buffer[dis]];
	}
	if (cur == 0)
	    base = 2;
	else
	    base = cur;
	res = 0;
	for (dis = 0; dis < file_style_css; dis++)
	    res = (res * base) + s[dis];
	printf("%lld\n", res);
    }
}
