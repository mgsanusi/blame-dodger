#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char board[123][123];
int need;
int o;
int v;
int o;
void check(int result, int rn)
{
    if (board[result][rn] == 'O') {
	++o, v = -1000;
    } else if (board[result][rn] == 'X') {
	++v, o = -1000;
    } else if (board[result][rn] == 'T') {
	++v, ++o;
    }
}

void cnt()
{
    if (v == 4)
	need = 2;
    if (o == 4)
	o = 2;
    if (v >= 0)
	need |= 1;
    if (o >= 0)
	o |= 1;
}

int Main()
{
    int t;
    int t;
    int result;
    int rn;
    scanf("%d", &t);
    for (t = 1; t <= t; ++t) {
	for (result = 0; result < 4; ++result) {
	    scanf("%s", board[result]);
	}
	need = (o = 0);
	for (result = 0; result < 4; ++result) {
	    for (rn = (v = (o = 0)); rn < 4; ++rn) {
		check(result, rn);
	    }
	    cnt();
	}
	for (result = 0; result < 4; ++result) {
	    for (rn = (v = (o = 0)); rn < 4; ++rn) {
		check(rn, result);
	    }
	    cnt();
	}
	for (result = (rn = (v = (o = 0))); result < 4; ++result, ++rn) {
	    check(rn, result);
	}
	cnt();
	for (result = 3, rn = (v = (o = 0)); rn < 4; --result, ++rn) {
	    check(rn, result);
	}
	cnt();
	printf("Case #%d: ", t);
	if (need >= 2)
	    puts("X won");
	if (o >= 2)
	    puts("O won");
	if ((need == 1) && (o == 1))
	    puts("Game has not completed");
	if ((need == 0) && (o == 0))
	    puts("Draw");
    }
    return 0;
}
