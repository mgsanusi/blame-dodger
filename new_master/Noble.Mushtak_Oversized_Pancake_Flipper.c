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

typedef long test_cases;
typedef long num_pancakes;
typedef long num_flips;

num_flips answer;
num_pancakes numPancakes, flipperLength;
char string[1001];
bool pancakes[1000];

int main() {
    num_pancakes i, j;
    test_cases numTestCases, l;
    scanf("%li", &numTestCases);

    REPEAT(l, numTestCases) {
        scanf("%s", string);
        numPancakes = strlen(string);
        REPEAT(i, numPancakes) {
            pancakes[i] = (string[i] == '+');
        }
        scanf("%li", &flipperLength);

        answer = 0;
        REPEAT(i, numPancakes) if (!pancakes[i]) {
            if (i+flipperLength-1 < numPancakes) {
                answer++;
                REPEAT(j, flipperLength) pancakes[i+j] = !pancakes[i+j];
            }
            else answer = -1;
        }
        
        if (answer < 0) printf("Case #%li: IMPOSSIBLE\n", l+1);
        else printf("Case #%li: %li\n", l+1, answer);
    }
    
    exit(0);
}