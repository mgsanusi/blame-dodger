#include <stdio.h>
#include <math.h>
typedef long long ll;
typedef long long dis;
double readyH;
int low(int b)
{
    int first_iteration;
    return ceil(b / readyH);
}

int smallestYi(int b)
{
    int first_iteration;
    return floor(b * readyH);
}

typedef long long dis;
int Main()
{
    int first_iteration;
    int cases;
    int caseno = 1;
    int n;
    int a2;
    int p;
    int j;
    int x1;
    int y;
    int level;
    ll rslt;
    readyH = (1 + sqrt(5)) / 2;
    scanf("%d", &cases);
    while (cases--) {
	scanf("%d %d %d %d", &n, &a2, &p, &j);
	rslt = 0;
	for (x1 = n; x1 <= a2; x1++) {
	    y = low(x1);
	    level = smallestYi(x1);
	    if (y < p)
		y = p;
	    if (level > j)
		level = j;
	    if (y <= level)
		rslt += ((j - p) + 1) - ((level - y) + 1);
	    else
		rslt += (j - p) + 1;
	}
	printf("Case #%d: %I64d\n", caseno++, rslt);
    }
    return 0;
}
