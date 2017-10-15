#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Main()
{
    int first_iteration;
    int patt;
    int b_pos;
    int a;
    int l;
    int x;
    int e;
    int size;
    int cnt = 0;
    int result;
    scanf("%d", &size);
    while (size--) {
	scanf("%d", &e);
	result = 0;
	for (patt = 0; patt < e; patt++) {
	    scanf("%d", &a);
	    if ((patt + 1) != a)
		result++;
	}
	printf("Case #%d: %d\n", ++cnt, result);
    }
    return 0;
}
