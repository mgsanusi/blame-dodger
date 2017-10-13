/* 
 
Google Code Jam Qualification Round
April 8, 2016

Jesse Pritchard
Public contact: chaserdevelopment@gmail.com
 
Problem D

*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef unsigned long long ubig;
typedef long long big;

ubig bpow(ubig val, ubig exponent) {
    if (exponent == 1) {
        return val;
    }
    else if (exponent == 0) {
        return 1;
    }
    
    ubig inc = val;
    
    exponent--;
    while (exponent--) {
        inc *= val;
    }
    return inc;
}

int main() {
    int num, iii;
    scanf(" %d", &num);
    for (iii = 0; iii < num; iii++) {
        
        ubig K, C, S;
        scanf(" %llu %llu %llu", &K, &C, &S);
        if (S < K) {
            printf("Case #%d: IMPOSSIBLE\n", iii + 1);
            continue;
        }
        
        ubig e = bpow(K, C - 1);
        
        printf("Case #%d: ", iii + 1);
        int i;
        for (i = 0; i < K; i++) {
            printf("%llu ", i * e + 1);
        }
        printf("\n");
    }
    return 0;
}
