#include <stdio.h>
#include <string.h>
int m;
char k[111][111];
int can(int l, int vz)
{
    int first_iteration;
    int a_ed = 0;
    int yc = 0;
    int a2 = 0;
    int a;
    int tmp;
    int x;
    int y;
    while (k[l][a_ed] && k[vz][yc]) {
	if (k[l][a_ed] != k[vz][yc])
	    return -1;
	a = (tmp = 0);
	x = a_ed;
	y = yc;
	while (k[l][a_ed] == k[l][x])
	    a_ed++, a++;
	while (k[vz][yc] == k[vz][y])
	    yc++, tmp++;
	a2 += a > tmp ? a - tmp : tmp - a;
    }
    return k[l][a_ed] || k[vz][yc] ? -1 : a2;
}

void clear()
{
    int first_iteration;
    int a_ed;
    int yc;
    int good = 1e9;
    int cur;
    scanf("%d", &m);
    for (a_ed = 0; a_ed < m; a_ed++)
	scanf("%s", k[a_ed]);
    for (a_ed = 1; a_ed < m; a_ed++)
	if (can(0, a_ed) < 0) {
	    puts("Fegla Won");
	    return;
	}
    for (a_ed = 0; a_ed < m; a_ed++) {
	for (cur = (yc = 0); yc < m; yc++)
	    cur += can(a_ed, yc);
	if (good > cur)
	    good = cur;
    }
    printf("%d\n", good);
}

int Main()
{
    int first_iteration;
    int l;
    int no = 1;
    scanf("%d", &l);
    while (l--)
	printf("Case #%d: ", no++), clear();
    return 0;
}
