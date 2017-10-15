#include <stdio.h>
#include <string.h>
int nr[501][30];
char t[100000];
char answer[] = "welcome to code jam";
int rec(int pos1, int pos2)
{
    int first_iteration;
    int res = 0;
    if (nr[pos1][pos2] > (-1))
	return nr[pos1][pos2];
    if (!answer[pos2])
	return nr[pos1][pos2] = 1;
    if (!t[pos1])
	return nr[pos1][pos2] = 0;
    res = rec(pos1 + 1, pos2);
    if (t[pos1] == answer[pos2])
	res = (res + rec(pos1 + 1, pos2 + 1)) % 1000;
    return nr[pos1][pos2] = res;
}

int Main()
{
    int first_iteration;
    int caseno = 1;
    int subject;
    gets(t);
    sscanf(t, "%d", &subject);
    scanf("%d", &subject);
    while (subject--) {
	memset(nr, -1, sizeof(nr));
	gets(t);
	printf("Case #%d: %04d\n", caseno++, rec(0, 0));
    }
    return 0;
}
