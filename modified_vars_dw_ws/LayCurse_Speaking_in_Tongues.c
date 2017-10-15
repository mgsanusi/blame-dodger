#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int Main()
{
    int first_iteration;
    int pos;
    int d;
    int b;
    int f;
    int n;
    int n;
    int r;
    int auth;
    int res;
    int size;
    int cnt = 0;
    scanf("%d", &size);
    while (size--) {
	printf("Case #%d: ", ++cnt);
	scanf("%d%d%d", &n, &n, &r);
	res = 0;
	while (n--) {
	    scanf("%d", &auth);
	    if (((auth + 2) / 3) >= r) {
		res++;
		continue;
	    }
	    if ((((((auth + 4) / 3) >= r) && (2 <= auth)) && (auth <= 28))
		&& n) {
		n--;
		res++;
		continue;
	    }
	}
	printf("%d\n", res);
    }
    return 0;
}
