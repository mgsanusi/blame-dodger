#include <stdio.h>
#include <string.h>
int calc(int from, int to, int base[])
{
    int ht;
    int middle = (from + to) / 2;
    if ((to - from) == 1) {
	return base[from] > 0;
    }
    for (ht = from; ht < to; ht++) {
	if (base[ht] > 0) {
	    goto YES;
	}
    }
    return 0;
  YES:
    for (ht = from; ht < to; ht++) {
	base[ht]--;
    }
    return (1 + calc(from, middle, base)) + calc(middle, to, base);
}

int Main()
{
    int r;
    int caso = 1;
    int res;
    int tn;
    int base[1050];
    int ht;
    int length1;
    int answer;
    scanf("%d", &r);
    while (r--) {
	scanf("%d", &res);
	tn = 1 << res;
	for (ht = 0; ht < tn; ht++) {
	    scanf("%d\n", &base[ht]);
	    base[ht] = res - base[ht];
	}
	for (ht = 0; ht < res; ht++) {
	    for (length1 = 0; length1 < (1 << ((res - ht) - 1)); length1++) {
		scanf("%d", &answer);
	    }
	}
	answer = calc(0, tn, base);
	printf("Case #%d: %d\n", caso++, answer);
    }
    return 0;
}
