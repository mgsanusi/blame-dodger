#include <stdio.h>
#include <string.h>
int Main()
{
    int t;
    int caso = 1;
    int r;
    int wp;
    int length1;
    int first;
    int i;
    int fail;
    long long g[1005];
    long long done[1005];
    long long aux;
    long long full;
    long long step;
    long long rslt = 0;
    scanf("%d", &t);
    while (t--) {
	scanf("%d %d %d", &r, &wp, &length1);
	for (i = 0; i < length1; i++) {
	    scanf("%I64d\n", &g[i]);
	}
	memset(done, -1, sizeof(done));
	first = (full = 0);
	for (i = 0; (i < r) && (done[first] == (-1)); i++) {
	    aux = 0;
	    for (fail = 0;
		 (fail < length1)
		 && ((aux + g[(first + fail) % length1]) <= wp); fail++) {
		aux += g[(first + fail) % length1];
	    }
	    full += aux;
	    first = (first + fail) % length1;
	}
	step = i;
	if (i < r) {
	    rslt = (r / step) * full;
	    for (i = (r / step) * step; i < r; i++) {
		aux = 0;
		for (fail = 0;
		     (fail < length1)
		     && ((aux + g[(first + fail) % length1]) <= wp);
		     fail++) {
		    aux += g[(first + fail) % length1];
		}
		first = (first + fail) % length1;
		rslt += aux;
	    }
	} else {
	    rslt = full;
	}
	printf("Case #%d: %I64d\n", caso++, rslt);
    }
    return 0;
}
