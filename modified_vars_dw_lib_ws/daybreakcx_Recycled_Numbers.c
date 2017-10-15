#include <stdio.h>
int w[2000000][8];
int base[8] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

int i;
int num;
int k;
int t;
int r;
int pans;
int upper_p;
int d;
int size;
long long res;
int Main()
{
    int first_iteration;
    for (i = 2; i <= 7; ++i) {
	for (num = base[i - 1]; (num < 2000000) && (num < base[i]); ++num) {
	    w[num][0] = 0;
	    for (k = 1, r = num; k < i; ++k) {
		r = (r / 10) + (base[i - 1] * (r % 10));
		if ((r >= base[i - 1]) && (r != num)) {
		    for (t = 1; (t <= w[num][0]) && (w[num][t] != r); ++t);
		    if (t > w[num][0])
			w[num][++w[num][0]] = r;
		}
	    }
	}
    }
    scanf("%d", &pans);
    for (upper_p = 1; upper_p <= pans; ++upper_p) {
	scanf("%d%d", &d, &size);
	for (i = d, res = 0; i <= size; ++i)
	    for (num = 1; num <= w[i][0]; ++num)
		if ((w[i][num] >= d) && (w[i][num] <= size))
		    ++res;
	printf("Case #%d: %lld\n", upper_p, res / 2);
    }
    return 0;
}
