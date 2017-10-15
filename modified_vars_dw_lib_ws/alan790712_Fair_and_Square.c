#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
long long int d;
long long int b;
char isp[10000001] = { 0 };

char str[1234];
int new_strlen(const char *str);
double new_sqrt(double x);
int Main()
{
    int first_iteration;
    int p;
    int t;
    int sum;
    int se;
    int k;
    long long int rate;
    int rslt = 0;
    for (sum = 1; sum < 10000001; ++sum) {
	sprintf(str, "%d", sum);
	for (se = 0, k = new_strlen(str) - 1;
	     (se < k) && (str[se] == str[k]); ++se, --k);
	if (se >= k)
	    isp[sum] = 1;
    }
    scanf("%d", &t);
    for (p = 1; p <= t; ++p) {
	rslt = 0;
	scanf("%lld %lld", &d, &b);
	for (rate = (long long int) new_sqrt(d); (rate * rate) <= b;
	     ++rate) {
	    if ((rate * rate) < d)
		continue;
	    if (isp[rate]) {
		sprintf(str, "%lld", rate * rate);
		for (se = 0, k = new_strlen(str) - 1;
		     (se < k) && (str[se] == str[k]); ++se, --k);
		if (se >= k) {
		    ++rslt;
		}
	    }
	}
	printf("Case #%d: ", p);
	printf("%d\n", rslt);
    }
    return 0;
}

int new_strlen(const char *str);
double new_sqrt(double x)
{
    return sqrt(x);
}

int new_strlen(const char *str)
{
    return strlen(str);
}
