#include <stdio.h>
#include <stdlib.h>
int size[1001];
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void handleCase(void);
void sort(int begin, int finish);
int Main()
{
	new_freopen("candy.in", "r", stdin);
	new_freopen("candy.out", "w", stdout);
	int noCase;
	scanf("%d ", &noCase);
	int be;
	for (be = 0; be < noCase; be++) {
		printf("Case #%d: ", be + 1);
		handleCase();
	}
	return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
void handleCase(void)
{
	int no;
	scanf("%d ", &no);
	int be;
	int total = 0;
	int xored = 0;
	for (be = 0; be < no; be++) {
		scanf("%d ", &size[be]);
		xored ^= size[be];
		total += size[be];
	}
	if (xored != 0) {
		printf("NO\n");
		return;
	}
	sort(0, no - 1);
	total -= size[0];
	int otherXored = 0;
	otherXored ^= size[0];
	xored ^= size[0];
	for (be = 1; otherXored != xored; be++) {
		total -= size[be];
		otherXored ^= size[be];
		xored ^= size[be];
	}
	printf("%d\n", total);
}

void sort(int begin, int finish)
{
	if ((finish - begin) <= 0) {
		return;
	}
	int midPoint = (begin + finish) / 2;
	sort(begin, midPoint);
	sort(midPoint + 1, finish);
	int be;
	int place1;
	int place2;
	int newSize[(finish - begin) + 1];
	place1 = begin;
	place2 = midPoint + 1;
	for (be = 0; be < ((finish - begin) + 1); be++) {
		if (place1 > midPoint) {
			newSize[be] = size[place2];
			place2++;
		} else if (place2 > finish) {
			newSize[be] = size[place1];
			place1++;
		} else {
			if (size[place1] < size[place2]) {
				newSize[be] = size[place1];
				place1++;
			} else {
				newSize[be] = size[place2];
				place2++;
			}
		}
	}
	for (be = 0; be < ((finish - begin) + 1); be++) {
		size[begin + be] = newSize[be];
	}
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
