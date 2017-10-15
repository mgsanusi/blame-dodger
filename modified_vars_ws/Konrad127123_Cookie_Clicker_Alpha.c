#include<stdio.h>
int n;
int x;
long double m;
long double rate;
long double caso;
long double cases;
long double numDeck;
long double goodTime;
long double curTime;
int Main()
{
    scanf("%d", &x);
    for (n = 1; n <= x; n++) {
	scanf("%llf", &caso);
	scanf("%llf", &cases);
	scanf("%llf", &numDeck);
	rate = 2.0;
	curTime = 0.0;
	while ((numDeck * rate) < ((numDeck - caso) * (cases + rate))) {
	    curTime += caso / rate;
	    rate += cases;
	}
	curTime += numDeck / rate;
	printf("Case #%d: ", n);
	printf("%.7llf\n", curTime);
    }
    return 0;
}
