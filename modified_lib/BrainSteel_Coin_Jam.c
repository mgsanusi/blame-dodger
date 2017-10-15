/*
 
 Google Code Jam Qualification Round
 April 8, 2016
 
 Jesse Pritchard
 Public contact: chaserdevelopment@gmail.com
 
 Problem C
 
 */

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#include <stddef.h>

// Returns a nontrivial divisor of test or 0 if it is prime
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

double new_sqrt(double x);

double new_pow(double base, double exponent);

long isprime(long test) {
    long s = new_sqrt(test) + 1;
    long i;
    for (i = 2; i <= s; i++) {
        if (test % i == 0) {
            return i;
        }
    }
    return 0;
}

// Converts the jamcoin in jm to a given base
long baseconvert(char* jm, int base) {
    int i;
    size_t len = new_strlen(jm);
    long result = 0;
    for (i = 0; i < len; i++) {
        result += (jm[i] - 48) ? new_pow(base, len - i - 1) : 0;
    }
    return result;
}

void nextpotentialjamcoin(char* jm) {
    size_t len = new_strlen(jm);
    
    if (jm[0] != '1' || jm[len - 1] != '1') {
        printf("Error: argument not valid jam coin.\n");
    }
    
    size_t i;
    for (i = len - 2; i > 0; i--) {
        if (jm[i] == '1') {
            jm[i] = '0';
        }
        else {
            jm[i] = '1';
            break;
        }
    }
    
}

void nextjamcoin(char* jm, long* divisors) {
    nextpotentialjamcoin(jm);
    
    int ibase;
    for (ibase = 2; ibase <= 10; ibase++) {
        if ((divisors[ibase - 2] = isprime(baseconvert(jm, ibase))) == 0) {
            nextpotentialjamcoin(jm);
            ibase = 1;
        }
    }
}

int main() {
    int num, T;
    scanf(" %d", &num);
    for (T = 0; T < num; T++) {
        
        int N, J;
        scanf(" %d %d", &N, &J);
        
        long divisors[9];
        
        char* jm = new_malloc(N + 1);
        jm[N] = '\0';
        int i;
        for (i = 0; i < N; i++) {
            jm[i] = i == 0 || i == N - 1 ? '1' : '0';
        }
        
        printf("Case #%d: \n", T + 1);
        for (i = 0; i < J; i++) {
            nextjamcoin(jm, divisors);
            printf("%s ", jm);
            int i;
            for (i = 0; i < 9; i++) {
                printf("%ld ", divisors[i]);
            }
            printf("\n");
        }
        
    }
    return 0;
}

size_t new_strlen(const char *str);

void* new_malloc(size_t size);

double new_sqrt(double x);

double new_pow(double base, double exponent) {
  return pow(base, exponent);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

double new_sqrt(double x) {
  return sqrt(x);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size) {
  return malloc(size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}