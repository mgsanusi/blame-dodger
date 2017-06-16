#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REPEAT(token, num) for (token = 0; token < num; token++)
#define getchar getchar_unlocked
#define putchar putchar_unlocked
static inline long long min(long long length1, long long length2) { return (length1 < length2) ? length1 : length2; }
static inline long long max(long long length1, long long length2) { return (length1 > length2) ? length1 : length2; }

//#define DEBUG
#ifdef DEBUG
#define PRINTF printf
#else
#define PRINTF(...) 1
#endif

typedef long long test_cases;
typedef long long num_stalls;
typedef struct {
    num_stalls max;
    num_stalls min;
} subdivision;
typedef long long num_spaces;

num_stalls numStalls, numPeople, spaces[1000], frequency[1000];
num_spaces pastLevel, pastSpace, curLevel, curSpace, numUsed;

subdivision divideSpace(num_stalls space) {
    subdivision answer;
    answer.max = space/2;
    if (space & 1) answer.min = space/2;
    else answer.min = space/2-1;
    return answer;
}

void addSpace(num_stalls space, num_stalls spaceFrequency) {
    if (spaces[curSpace] == space) frequency[curSpace] += spaceFrequency;
    else {
        spaces[++curSpace] = space;
        frequency[curSpace] = spaceFrequency;
    }
    numUsed += spaceFrequency;
}

int main() {
    test_cases numTestCases, l;
    num_spaces i;
    scanf("%lli", &numTestCases);

    REPEAT(l, numTestCases) {
        scanf("%lli %lli", &numStalls, &numPeople);
        spaces[0] = numStalls, frequency[0] = 1;
        pastLevel = curSpace = 0, numUsed = 1, curLevel = 1;

        while (numUsed < numPeople) {
            for (i = pastLevel; i < curLevel; i++) {
                subdivision newSpaces = divideSpace(spaces[i]);
                addSpace(newSpaces.max, frequency[i]);
                if (numUsed >= numPeople) break;
                addSpace(newSpaces.min, frequency[i]);
                if (numUsed >= numPeople) break;
            }
            pastLevel = curLevel, curLevel = curSpace+1;
        }

        subdivision answer = divideSpace(spaces[curSpace]);
        printf("Case #%lli: %lli %lli\n", l+1, answer.max, answer.min);
    }
    
    exit(0);
}