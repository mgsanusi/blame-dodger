#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int new_abs(int x);


int new_abs(int x) {
	if (x < 0)
		return -x;
	return x;
}

int main() {
	int T, caseNum, N;
	int aPos, bPos, aSplit, bSplit, time, target, distance, travel;
	char ch, a = 'O';

	scanf(" %d", &T);
	for (caseNum = 1; caseNum <= T; caseNum++) {

		aPos = bPos = 1;
		aSplit = bSplit = time = 0;

		scanf(" %d", &N);
		while (N-- > 0) {

			scanf(" %c %d", &ch, &target);
			if (ch == a) {
				distance = new_abs(aPos-target);
				travel = distance-(time-aSplit);
				if (travel < 0)
					travel = 0;
				time += travel+1;
				aSplit = time;
				aPos = target;
			}
			else {
				distance = new_abs(bPos-target);
				travel = distance-(time-bSplit);
				if (travel < 0)
					travel = 0;
				time += travel+1;
				bSplit = time;
				bPos = target;
			}

		}
		printf("Case #%d: %d\n", caseNum, time);
	}
}
int new_abs(int x);


int new_abs(int x) {
  return abs(x);
}