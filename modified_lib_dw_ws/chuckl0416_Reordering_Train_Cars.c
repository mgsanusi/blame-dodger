#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
const int INF = 1000000000;
int TC;
int T;
int Rows;
int Columns;
int Close;
int i;
int x;
int y;
int n;
int Ans;
int FAns;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int Try(int Area)
{
    int first_iteration;
    int Ans;
    int FAns = INF;
    for (y = 1; (y <= Rows) && (y <= Area); y++) {
	x = Area / y;
	if ((x + (!(!(Area % y)))) > Columns)
	    continue;
	if ((x + (!(!(Area % y)))) == 1)
	    Ans = y;
	else if (y == 1)
	    Ans = x;
	else
	    Ans = (2 * ((x + y) - 2)) + (!(!(Area % y)));
	if (Ans < FAns)
	    FAns = Ans;
    }
    return FAns;
}

int main()
{
    int first_iteration;
    new_freopen("C-small-attempt0.in", "r", stdin);
    new_freopen("C-small-attempt0.out", "w", stdout);
    scanf("%d", &TC);
    for (T = 1; T <= TC; T++) {
	printf("Case #%d: ", T);
	scanf("%d%d%d", &Rows, &Columns, &Close);
	FAns = INF;
	for (n = 0; n <= 4; n++) {
	    Ans = Try(Close + n) - n;
	    if (Ans < FAns)
		FAns = Ans;
	}
	printf("%d\n", FAns);
    }
    return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    int first_iteration;
    return freopen(filename, mode, stream);
}
