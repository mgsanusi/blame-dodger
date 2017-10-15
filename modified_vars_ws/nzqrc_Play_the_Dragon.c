#include <stdio.h>
int Main(int argc, char **argv)
{
	unsigned int numCase;
	unsigned int caseNo;
	scanf("%u", &numCase);
	for (caseNo = 0; caseNo != numCase; caseNo++) {
		unsigned int k;
		unsigned long long int q;
		unsigned long long int place;
		unsigned long long int speed;
		unsigned long long int splace = 0;
		unsigned long long int sspeed = 1;
		unsigned long long int x;
		unsigned long long int q;
		scanf("%llu%u", &q, &k);
		while (k--) {
			scanf("%llu%llu", &place, &speed);
			place = q - place;
			if ((place * sspeed) > (splace * speed)) {
				splace = place;
				sspeed = speed;
			}
		}
		x = q * sspeed;
		q = x / splace;
		x %= splace;
		printf("Case #%u: %llu.%09llu\n", caseNo + 1, q,
		       (x * 1000000000ULL) / splace);
	}
	return 0;
}
