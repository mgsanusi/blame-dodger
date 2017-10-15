#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    int first_iteration;
    int i;
    int j;
    int k;
    int l;
    int N;
    int S;
    int p;
    int t;
    int res;
    int size;
    int count = 0;
    scanf("%d", &size);
    while (size--) {
	printf("Case #%d: ", ++count);
	scanf("%d%d%d", &N, &S, &p);
	res = 0;
	while (N--) {
	    scanf("%d", &t);
	    if (((t + 2) / 3) >= p) {
		res++;
		continue;
	    }
	    if ((((((t + 4) / 3) >= p) && (2 <= t)) && (t <= 28)) && S) {
		S--;
		res++;
		continue;
	    }
	}
	printf("%d\n", res);
    }
    return 0;
}
