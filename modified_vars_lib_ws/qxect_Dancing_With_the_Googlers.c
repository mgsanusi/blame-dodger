#include<stdio.h>
#include<string.h>
int nu[200];
int Main()
{
    int length;
    int dy;
    int _q;
    int answer;
    int n;
    int f;
    int t;
    scanf("%d", &length);
    for (_q = 1; _q <= length; _q++) {
	scanf("%d%d%d", &n, &f, &t);
	answer = 0;
	for (dy = 0; dy < n; dy++) {
	    scanf("%d", &nu[dy]);
	    if (nu[dy] >= ((((t - 1) + t) - 1) + t))
		answer++;
	    else if ((f && (nu[dy] >= ((((t + t) - 2) + t) - 2)))
		     && (nu[dy] >= 2)) {
		f--;
		answer++;
	    }
	}
	printf("Case #%d: %d\n", _q, answer);
    }
    return 0;
}
