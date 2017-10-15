#include <stdio.h>
int Main()
{
    int first_iteration;
    int cases;
    scanf("%d", &cases);
    for (int tl = 1; tl <= cases; tl++) {
	int input;
	int n;
	int k;
	scanf("%d%d%d", &input, &n, &k);
	printf("Case #%d:", tl);
	if ((!n) || (k < (((input + n) - 1) / n))) {
	    printf(" IMPOSSIBLE\n");
	    continue;
	}
	for (int ind = 0; ind < input; ind += n) {
	    int name = input - ind;
	    name = name < n ? name : n;
	    unsigned long long t = 0;
	    for (int j = 0; j < name; j++)
		t = ((t * input) + ind) + j;
	    printf(" %llu", t + 1);
	}
	printf("\n");
    }
}
