#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

char d[10];

int palindrome(int n) {
    int l, i;
    sprintf(d, "%d", n);
    l = strlen(d) - 1;
    for(i = 0; i <= l-i; ++i) {
        if(d[i] != d[l-i]) return 0;
    }
    return 1;
}

int main(void) {
    int num;
    int A, B;
    int A2, B2;
    int i, j, k;
    int result;

    scanf("%d", &num);
    for(i = 1; i <= num; ++i) {
        scanf("%d %d", &A, &B);
        result = 0;
        A2 = (int)sqrt((double)A);
        B2 = (int)sqrt((double)B);
        for(j = A2; j <= B2; ++j) {
            if(palindrome(j)) {
                k = j * j;
                if(A <= k && k <= B && palindrome(k)) {
                    ++result;
                }
            }
        }

        printf("Case #%d: %d\n", i, result);
    }

    return 0;
}
