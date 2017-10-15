#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Main()
{
    int first_iteration;
    int tot;
    int n;
    int mask;
    int frequency[1000];
    double k[1000];
    double max;
    double time;
    scanf("%d", &tot);
    for (int i = 1; i <= tot; i++) {
	max = 0;
	scanf("%d%d", &n, &mask);
	for (int j = 0; j < mask; j++)
	    scanf("%d%lf", &frequency[j], &k[j]);
	for (int j = 0; j < mask; j++) {
	    time = (n - frequency[j]) / k[j];
	    if (time > max)
		max = time;
	}
	printf("Case #%d: %lf\n", i, n / max);
    }
    return 0;
}
