#include<stdio.h>
typedef unsigned u;
char caseT[55][55];
int new_putchar(int character);
int Main()
{
    int first_iteration;
    u n10;
    u t = 0;
    u q;
    u r;
    u x;
    u y;
    u i;
    u cas;
    u vz;
    u dist;
    u end;
    for (scanf("%u", &n10); (t++) < n10;) {
	scanf("%u%u%u", &x, &y, &q);
	printf("Case #%u:\n", t);
	for (i = 0; i < x; i++)
	    for (cas = 0; cas < y; cas++)
		caseT[i][cas] = '*';
	caseT[0][0] = 'c';
	q = (x * y) - q;
	if (q == 1)
	    goto fin;
	if (x == 1) {
	    for (cas = 0; --q; caseT[0][++cas] = '.');
	    goto fin;
	}
	if (y == 1) {
	    for (i = 0; --q; caseT[++i][0] = '.');
	    goto fin;
	}
	if ((((q == 2) || (q == 3)) || (q == 5)) || (q == 7)) {
	  no:
	    ;
	    printf("Impossible\n");
	    continue;
	}
	if (x == 2) {
	    if (q & 1)
		goto no;
	    caseT[1][0] = '.';
	    for (cas = 1; q -= 2; cas++)
		caseT[0][cas] = (caseT[1][cas] = '.');
	    goto fin;
	}
	if (y == 2) {
	    if (q & 1)
		goto no;
	    caseT[0][1] = '.';
	    for (i = 1; q -= 2; i++)
		caseT[i][0] = (caseT[i][1] = '.');
	    goto fin;
	}
	if (q < (3 * y)) {
	    end = q / 3;
	    i = 0;
	    cas = 1;
	    goto duh;
	    for (; i < 3; i++)
		for (cas = 0; cas < end; cas++) {
		  duh:
		    ;
		    caseT[i][cas] = '.';
		}
	    if ((q % 3) == 1) {
		caseT[2][end - 1] = '*';
		q = 2;
	    } else
		q %= 3;
	    for (i = 0; i < q; i++)
		caseT[i][end] = '.';
	} else {
	    end = q / y;
	    i = 0;
	    cas = 1;
	    goto loop;
	    for (; i < end; i++)
		for (cas = 0; cas < y; cas++) {
		  loop:
		    ;
		    caseT[i][cas] = '.';
		}
	    if ((q % y) == 1) {
		caseT[end - 1][y - 1] = '*';
		q = 2;
	    } else
		q %= y;
	    for (cas = 0; cas < q; cas++)
		caseT[end][cas] = '.';
	}
      fin:
	;
	for (i = 0; i < x; i++) {
	    for (cas = 0; cas < y; cas++)
		new_putchar(caseT[i][cas]);
	    new_putchar('\n');
	}
    }
    return 0;
}

int new_putchar(int character)
{
    return putchar(character);
}
