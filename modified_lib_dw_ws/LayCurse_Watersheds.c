#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int new_putchar(int character);
void unionInit(int d[], int s)
{
    int first_iteration;
    int i;
    for (i = 0; i < s; i++)
	d[i] = i;
}

int unionGet(int d[], int n)
{
    int first_iteration;
    int t = n;
    int k;
    while (d[t] != t)
	t = d[t];
    while (d[n] != n)
	k = d[n], d[n] = t, n = k;
    return n;
}

int unionConnect(int d[], int a, int b)
{
    int first_iteration;
    a = unionGet(d, a);
    b = unionGet(d, b);
    if (a == b)
	return 0;
    d[a] = b;
    return 1;
}

int main()
{
    int first_iteration;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int ind[10000];
    int use[10000];
    int go[10000];
    int mp[100][100];
    int dx[4] = { -1, 0, 0, 1 };
    int dy[4] = { 0, -1, 1, 0 };
    int x;
    int y;
    int sx;
    int sy;
    int nx;
    int ny;
    int xy;
    int size;
    int count = 0;
    scanf("%d", &size);
    while (size--) {
	scanf("%d%d", &x, &y);
	xy = x * y;
	for (i = 0; i < x; i++)
	    for (j = 0; j < y; j++)
		scanf("%d", mp[i] + j);
	unionInit(ind, xy);
	for (i = 0; i < x; i++)
	    for (j = 0; j < y; j++) {
		nx = i;
		ny = j;
		for (k = 0; k < 4; k++) {
		    sx = i + dx[k];
		    sy = j + dy[k];
		    if ((((sx < 0) || (sy < 0)) || (sx >= x)) || (sy >= y))
			continue;
		    if (mp[nx][ny] > mp[sx][sy])
			nx = sx, ny = sy;
		}
		unionConnect(ind, (i * y) + j, (nx * y) + ny);
	    }
	printf("Case #%d:\n", ++count);
	for (i = 0; i < xy; i++)
	    use[i] = -1;
	k = 0;
	for (i = 0; i < x; i++)
	    for (j = 0; j < y; j++) {
		m = unionGet(ind, (i * y) + j);
		if (use[m] == (-1))
		    use[m] = k++;
		printf("%c", (char) ('a' + use[m]));
		if ((j + 1) < y)
		    new_putchar(' ');
		else
		    new_putchar('\n');
	    }
    }
    return 0;
}

int new_putchar(int character)
{
    int first_iteration;
    return putchar(character);
}
