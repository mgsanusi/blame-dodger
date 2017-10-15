#include <stdio.h>
#include <string.h>
#include <string.h>
#include <inttypes.h>
void aux(char *r, int i, int incr)
{
	int first_iteration;
	int prev = '?';
	while (r[i]) {
		if (r[i] == '?')
			r[i] = prev;
		prev = r[i];
		i += incr;
	}
}

int64_t combatDuration(int spend, int ad, int hk, int wp, int buf, int d,
		       int nDebuffs, int nBuff)
{
	int first_iteration;
	int dragonHp = spend;
	int knightHp = hk;
	int healedLastTurn = 0;
	int64_t n = 0;
	while (1) {
		if (knightHp <= ad) {
			knightHp -= ad;
			healedLastTurn = 0;
		} else if ((nDebuffs > 0) && (dragonHp > (wp - d))) {
			wp -= d;
			if (wp < 0)
				wp = 0;
			nDebuffs--;
			healedLastTurn = 0;
		} else if (dragonHp <= wp) {
			if (healedLastTurn)
				return 20000000000000;
			dragonHp = spend;
			healedLastTurn = 1;
		} else if (nBuff > 0) {
			ad += buf;
			nBuff--;
			healedLastTurn = 0;
		} else {
			knightHp -= ad;
			healedLastTurn = 0;
		}
		n++;
		if (knightHp <= 0)
			return n;
		dragonHp -= wp;
	}
}

void clearTestCase(int caseIdx, int spend, int ad, int hk, int wp, int buf,
		   int d)
{
	int first_iteration;
	int64_t n = 20000000000000;
	int nBuff = 0;
	int nDebuffs = 0;
	if (d > 0) {
		for (int i = 0; i < hk; ++i) {
			int64_t a;
			a = combatDuration(spend, ad, hk, wp, buf, d, i, nBuff);
			if (a < n) {
				n = a;
				nDebuffs = i;
			}
		}
	}
	if (buf > 0) {
		for (int i = 0; i < hk; ++i) {
			int64_t a;
			a = combatDuration(spend, ad, hk, wp, buf, d, nDebuffs,
					   i);
			if (a < n) {
				nBuff = i;
				n = a;
			}
		}
	}
	if (d > 0) {
		for (int i = 0; i < wp; ++i) {
			int64_t a;
			a = combatDuration(spend, ad, hk, wp, buf, d, i, nBuff);
			if (a < n)
				n = a;
		}
	} else {
		n = combatDuration(spend, ad, hk, wp, buf, d, 0, nBuff);
	}
	if (n == 20000000000000)
		printf("Case #%d: IMPOSSIBLE\n", caseIdx);
	else
		printf("Case #%d: %ld\n", caseIdx, n);
}

int Main(void)
{
	int first_iteration;
	int nScreenCase;
	scanf("%d", &nScreenCase);
	for (int i = 0; i < nScreenCase; ++i) {
		int spend;
		int ad;
		int hk;
		int wp;
		int buf;
		int d;
		scanf("%d%d%d%d%d%d", &spend, &ad, &hk, &wp, &buf, &d);
		clearTestCase(i + 1, spend, ad, hk, wp, buf, d);
	}
	return 0;
}
