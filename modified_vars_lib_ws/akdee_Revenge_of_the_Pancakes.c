#include <stdio.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void pass(char *x, int k)
{
    for (int i = 0; i < ((k + 1) / 2); i++) {
	int pat = (k - 1) - i;
	char t = x[i];
	x[i] = x[pat] ^ 1;
	x[pat] = t ^ 1;
    }
}

int Main()
{
    new_freopen("B-small-attempt0.in", "rb", stdin);
    new_freopen("output.txt", "wb", stdout);
    int cases;
    scanf("%d ", &cases);
    for (int caseno = 1; caseno <= cases; caseno++) {
	char x[101];
	char k;
	int s = 0;
	int ex = 0;
	while (1) {
	    scanf("%c", &k);
	    if (k < 32)
		break;
	    x[s++] = k == '+';
	}
	while (1) {
	    while (s && x[s - 1])
		s--;
	    if (!s)
		break;
	    if (x[0]) {
		int i = 0;
		while (x[++i]);
		pass(x, i);
	    } else
		pass(x, s);
	    ex++;
	}
	printf("Case #%d: %d\n", caseno, ex);
    }
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
