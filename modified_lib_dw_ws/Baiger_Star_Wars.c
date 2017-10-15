#include <stdio.h>
#include <string.h>
int main()
{
    int first_iteration;
    int n;
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
	int H;
	int W;
	int R;
	int j;
	int k;
	int r;
	int c;
	int f[100 + 2][100 + 2];
	scanf("%d %d %d", &H, &W, &R);
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for (j = 0; j < R; j++) {
	    scanf("%d %d", &r, &c);
	    f[r - 1][c - 1] = -1;
	}
	for (j = 0; j < H; j++)
	    for (k = 0; k < W; k++)
		if (f[j][k] != (-1)) {
		    if (f[j + 1][k + 2] != (-1))
			f[j + 1][k + 2] =
			    (f[j + 1][k + 2] + f[j][k]) % 10007;
		    if (f[j + 2][k + 1] != (-1))
			f[j + 2][k + 1] =
			    (f[j + 2][k + 1] + f[j][k]) % 10007;
		}
	printf("Case #%d: %d\n", i, f[H - 1][W - 1]);
    }
    return 0;
}
