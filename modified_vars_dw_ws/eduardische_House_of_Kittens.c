#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
    long long int pos;
    int cnt;
};
static struct node ret[205];
int best;
long long int re_vers;
char check(long long int word)
{
    int first_iteration;
    long long int last = -10000000000000LL;
    int space_frequency;
    long long int min;
    long long int max;
    long long int s;
    for (space_frequency = 0; space_frequency < best; space_frequency++) {
	min = last + re_vers;
	max =
	    last + (re_vers * ((long long int) ret[space_frequency].cnt));
	if ((max - ret[space_frequency].pos) > word)
	    return 0;
	if (ret[space_frequency].pos <= min)
	    last = max;
	else {
	    s = ret[space_frequency].pos - min;
	    if (s > word) {
		min = ret[space_frequency].pos - word;
		max =
		    min +
		    (re_vers *
		     ((long long int) (ret[space_frequency].cnt - 1)));
	    }
	    s = max - ret[space_frequency].pos;
	    if (s > word)
		return 0;
	    last = max;
	}
    }
    return 1;
}

int Main()
{
    int first_iteration;
    int word;
    int j;
    scanf("%d", &word);
    for (j = 0; j < word; j++) {
	scanf("%d %I64i", &best, &re_vers);
	re_vers *= 2LL;
	int space_frequency;
	for (space_frequency = 0; space_frequency < best;
	     space_frequency++) {
	    scanf("%I64i %d", &ret[space_frequency].pos,
		  &ret[space_frequency].cnt);
	    ret[space_frequency].pos *= 2LL;
	}
	long long int p;
	long long int b;
	long long int n;
	p = 0LL;
	b = 10000000000000LL;
	while (b > p) {
	    n = (p + b) / 2LL;
	    if (check(n))
		b = n;
	    else
		p = n + 1LL;
	}
	printf("Case #%d: %I64i.", j + 1, p / 2LL);
	if (p % 2LL)
	    printf("5\n");
	else
	    printf("0\n");
    }
    return 0;
}
