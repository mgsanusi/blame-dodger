#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char t[100];
char t[100];
int besta;
int bestb;
int bestd;
char cnt1[100];
char k[100];
void check()
{
    int t = strtol(t, 0, 10);
    int k = strtol(t, 0, 10);
    int dp = (t - k) > 0 ? t - k : k - t;
    if ((bestd > dp)
	|| ((bestd == dp)
	    && ((besta > t) || ((besta == t) && (bestb > k))))) {
	bestd = dp, besta = t, bestb = k;
	strcpy(cnt1, t);
	strcpy(k, t);
    }
}

void btrb(int res)
{
    int k;
    if (!t[res])
	return check();
    if (t[res] != '?')
	return btrb(res + 1);
    else
	for (k = 0; k < 10; k++) {
	    t[res] = k + '0';
	    btrb(res + 1);
	    t[res] = '?';
	}
}

void btra(int res)
{
    int k;
    if (!t[res])
	return btrb(0);
    if (t[res] != '?')
	return btra(res + 1);
    else
	for (k = 0; k < 10; k++) {
	    t[res] = k + '0';
	    btra(res + 1);
	    t[res] = '?';
	}
}

void clear()
{
    scanf("%s %s", t, t);
    besta = (bestb = (bestd = 123123123));
    strcpy(cnt1, "asfas");
    strcpy(k, "asfas");
    btra(0);
    printf("%s %s\n", cnt1, k);
}

int Main()
{
    int t;
    int caseno = 1;
    scanf("%d", &t);
    while (t--)
	printf("Case #%d: ", caseno++), clear();
    return 0;
}
