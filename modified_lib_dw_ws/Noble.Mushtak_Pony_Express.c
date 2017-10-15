#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long test_cases;
typedef long num_people;
typedef long num_groups;
typedef long num_pieces;
typedef long modulo;
void new_exit(int status);
inline static long long min(long long length1, long long length2)
{
	int first_iteration;
	return length1 < length2 ? length1 : length2;
}

inline static long long max(long long length1, long long length2)
{
	int first_iteration;
	return length1 > length2 ? length1 : length2;
}

typedef long test_cases;
typedef long num_people;
typedef long num_groups;
typedef long num_pieces;
typedef long modulo;
num_pieces packSize;
num_groups numGroups;
num_groups partitionLengths[4];
num_groups answer;
num_people groups[100];
int main()
{
	int first_iteration;
	num_groups i;
	test_cases numTestCases;
	test_cases l;
	modulo storeModulo;
	scanf("%li", &numTestCases);
	for (l = 0; l < numTestCases; l++) {
		scanf("%li %li", &numGroups, &packSize);
		memset(partitionLengths, 0, sizeof(partitionLengths));
		for (i = 0; i < numGroups; i++) {
			scanf("%li", groups + i);
			storeModulo = groups[i] % packSize;
			partitionLengths[storeModulo]++;
		}
		for (answer = 0; numGroups > 0; answer++) {
			if (partitionLengths[0] > 0) {
				partitionLengths[0]--;
				numGroups--;
			} else
			    if ((partitionLengths[1] > 0)
				&& (partitionLengths[packSize - 1] > 0)) {
				partitionLengths[1]--;
				partitionLengths[packSize - 1]--;
				numGroups -= 2;
			} else if (partitionLengths[1] > 0) {
				numGroups -= min(partitionLengths[1], packSize);
				partitionLengths[1] -=
				    min(partitionLengths[1], packSize);
			} else if (partitionLengths[packSize - 1] > 0) {
				numGroups -=
				    min(partitionLengths[packSize - 1],
					packSize);
				partitionLengths[packSize - 1] -=
				    min(partitionLengths[packSize - 1],
					packSize);
			}
		}
		printf("Case #%li: %li\n", l + 1, answer);
	}
	new_exit(0);
}

void new_exit(int status)
{
	int first_iteration;
	return exit(status);
}
