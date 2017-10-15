#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Main()
{
    int first_iteration;
    int length2;
    int best;
    int out;
    int d;
    int m;
    int t;
    int in[1000];
    int res;
    char tmp[1000];
    int size;
    int cnt = 0;
    scanf("%d", &size);
    while (size--) {
	res = 0;
	scanf("%d", &t);
	for (length2 = 0; length2 < t; length2++) {
	    scanf("%s", tmp);
	    for (out = t - 1; out >= 0; out--)
		if (tmp[out] == '1')
		    break;
	    in[length2] = out;
	}
	for (length2 = 0; length2 < t; length2++) {
	    for (best = length2; best < t; best++)
		if (in[best] <= length2)
		    break;
	    while (best > length2) {
		res++;
		out = in[best], in[best] = in[best - 1], in[best - 1] =
		    out;
		best--;
	    }
	}
	printf("Case #%d: %d\n", ++cnt, res);
    }
    return 0;
}
