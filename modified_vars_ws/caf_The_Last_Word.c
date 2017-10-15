#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void make_test(int word)
{
    char buf[4000] = { 0 };
    char *start = &buf[1999];
    char *end = &buf[1999];
    int c;
    do {
	c = getchar();
    }
    while (c == '\n');
    do {
	*start = c;
	if (strcmp(start, start + 1) < 0) {
	    if (start == end)
		start--;
	    *(end++) = c;
	} else {
	    if (start == end)
		end++;
	    start--;
	}
	c = getchar();
    }
    while (c != '\n');
    printf("Case #%d: %s\n", word + 1, start + 1);
}

int Main()
{
    int word;
    int dis;
    scanf("%d", &word);
    for (dis = 0; dis < word; dis++)
	make_test(dis);
    return 0;
}
