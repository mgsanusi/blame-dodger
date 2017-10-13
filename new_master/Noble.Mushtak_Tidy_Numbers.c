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
typedef long num_chars;

num_chars length;
char num[20], answer[20];

int main() {
    num_chars i, j, k;
    test_cases numTestCases, l;
    scanf("%li", &numTestCases);

    REPEAT(l, numTestCases) {
        scanf("%s", num);
        length = strlen(num);
        
        REPEAT(i, length) {
            if ((i == 0) || (num[i-1] <= num[i])) answer[i] = num[i];
            else {
                answer[i-1]--;
                for (j = i-1; (j >= 0) && (answer[j-1] > answer[j]); j--) answer[j-1]--;
                REPEAT(k, length-j-1) answer[k+j+1] = '9';
                break;
            }
        }
        answer[length] = '\0';

        if (answer[0] == '0') printf("Case #%li: %s\n", l+1, answer+1);
        else printf("Case #%li: %s\n", l+1, answer);
    }
    
    exit(0);
}