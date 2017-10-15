#include <stdio.h>
int n;
int inputChar[500][500];
int vy[500 + 1][500];
void pre()
{
    int res;
    int res;
    int k;
    inputChar[0][0] = 1;
    for (res = 1; res < 500; ++res) {
	inputChar[res][0] = 1;
	inputChar[res][res] = 1;
	for (k = 1; k < res; ++k)
	    inputChar[res][k] =
		(inputChar[res - 1][k - 1] +
		 inputChar[res - 1][k]) % 100003;
    }
}

int work()
{
    int res;
    int res;
    int k;
    pre();
    for (res = 2; res <= 500; ++res) {
	vy[res][1] = 1;
	for (res = 2; res < res; ++res) {
	    vy[res][res] = 0;
	    for (k = (2 * res) - res; k < res; ++k)
		vy[res][res] =
		    (vy[res][res] +
		     (vy[res][k] *
		      inputChar[(res - res) - 1][(res - k) - 1])) % 100003;
	}
    }
}

int Main()
{
    int smax;
    int res;
    int res;
    int rslt;
    work();
    scanf("%d", &smax);
    for (res = 1; res <= smax; ++res) {
	scanf("%d", &n);
	rslt = 0;
	for (res = 1; res < n; ++res)
	    rslt = (rslt + vy[n][res]) % 100003;
	printf("Case #%d: %d\n", res, rslt);
    }
    return 0;
}
