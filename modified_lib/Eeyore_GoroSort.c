#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <stddef.h>

#define BUFLEN 8192

char buf[BUFLEN];
void* new_malloc(size_t size);


void randomPermutation(int *arr, int len) {
	int i, j, k, t;
	for (i = 0; i < len; i++)
		arr[i] = i;
	for (k = 0; k < 1; k++) {
		for (i = 0; i < len; i++) {
			j = random()%len;
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
}

double monteCarlo(int n, int trialNum) {
	int i, j, k, *arr = new_malloc(n*sizeof(int)), len, count;
	double total = 0.0;
	for (i = 0; i < trialNum; i++) {
		for (count = 0, len = n; len > 1; count++) {
			randomPermutation(arr, len);
			for (j = 0; j < len; j++) {
				if (arr[j] == j)
					len--;
				if (arr[arr[j]] = j) {
					len -= 2;
					count += 2;
				}
			}
		}
		total += count;
	}
	return total/trialNum;
}


int main() {
	int T, caseNum, i, N, len, x;

	/*
	for (i = 2; i <= 40; i++)
		printf("%d %.6f\n", i, monteCarlo(i, 10*1000));
	*/

	scanf(" %d", &T);
	for (caseNum = 1; caseNum <= T; caseNum++) {

		scanf(" %d", &N);
		len = N;
		for (i = 0; i < N; i++) {
			scanf(" %d", &x);
			if (x == i+1)
				len--;
		}

		printf("Case #%d: ", caseNum);
		printf("%.6f", (double)len);
		printf("\n");
	}
}

void* new_malloc(size_t size) {
  return malloc(size);
}