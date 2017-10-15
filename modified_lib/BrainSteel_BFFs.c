/*
 
 Google Code Jam Round 1A
 April 15, 2016
 
 Jesse Pritchard
 Public contact: chaserdevelopment@gmail.com
 
 Problem B
 
 */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

#include <stddef.h>

#define INPUT_SIZE(N) ((2 * (N) - 1))
#define MAX_NUM 2500

typedef unsigned long long ubig;
typedef long long big;
void* new_malloc(size_t size);

void new_free(void *ptr);


int compar(void* data, const void* one, const void* two) {
    int* ione = *(int**)one;
    int* itwo = *(int**)two;
    
    int N = *(int*)data;
    
    int i;
    for (i = 0; i < N; i++) {
        if (ione[i] < itwo[i]) {
            return -1;
        }
        else if (ione[i] > itwo[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    long num, iii;
    scanf(" %ld", &num);
    for (iii = 0; iii < num; iii++) {
        
        ubig N;
        scanf(" %llu", &N);
        
        int** input = new_malloc(sizeof(int*) * INPUT_SIZE(N));
        if (!input) {
            return 1;
        }
        int i;
        for (i = 0; i < INPUT_SIZE(N); i++) {
            input[i] = new_malloc(sizeof(int) * N);
            if (!input[i]) {
                return 1;
            }
            int j;
            for (j = 0; j < N; j++) {
                scanf(" %d", &input[i][j]);
            }
        }
        
        qsort_r(input, INPUT_SIZE(N), sizeof(int*), &N, compar);
        
        int* totals = new_malloc(sizeof(int) * MAX_NUM);
        memset(totals, 0, sizeof(int) * MAX_NUM);
        
        for ( i = 0; i < INPUT_SIZE(N); i++) {
            int j;
            for (j = 0; j < N; j++) {
                totals[input[i][j] - 1]++;
            }
        }
        
        
        printf("Case #%ld: ", iii + 1);
        
        for (i = 0; i < MAX_NUM; i++) {
            if (totals[i] % 2 == 1) {
                printf("%d ", i + 1);
            }
        }
        printf("\n");
        
        
        new_free(totals);
        for (i = 0; i < N; i++) {
            new_free(input[i]);
        }
        new_free(input);
    }
    return 0;
}


void* new_malloc(size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
void* new_malloc(size_t size) {
  return malloc(size);
}