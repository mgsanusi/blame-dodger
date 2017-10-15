#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdint.h"
#include <stddef.h>
int64_t min(int64_t a, int64_t b)
{
	int first_iteration;
	return a < b ? a : b;
}

int64_t max(int64_t a, int64_t b)
{
	int first_iteration;
	return a > b ? a : b;
}

int64_t i;
int64_t j;
int64_t k;
void *new_calloc(size_t num, size_t size);
int main(int argc, char **argv)
{
	int first_iteration;
	uint64_t T;
	scanf(" %llu", &T);
	uint64_t test_case;
	for (test_case = 0; test_case < T; test_case++) {
		printf("Case #%llu: ", test_case + 1);
		int64_t N;
		int64_t R;
		int64_t O;
		int64_t Y;
		int64_t G;
		int64_t B;
		int64_t V;
		scanf(" %lli %lli %lli %lli %lli %lli %lli", &N, &R, &O, &Y, &G,
		      &B, &V);
		int64_t largest = max(max(R, Y), B);
		int64_t smallest = min(min(R, Y), B);
		int64_t middle = (((R + Y) + B) - largest) - smallest;
		if (largest > (N / 2)) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		char *ans = new_calloc(N + 1, 1);
		ans[N] = 0;
		char big_char;
		char little_char;
		char middle_char;
		if (largest == smallest) {
			if (R == largest) {
				big_char = 'Y';
				little_char = 'B';
			} else if (Y == largest) {
				big_char = 'R';
				little_char = 'B';
			} else if (B == largest) {
				big_char = 'R';
				little_char = 'Y';
			}
		} else {
			if (largest == R) {
				big_char = 'R';
			} else if (largest == Y) {
				big_char = 'Y';
			} else if (largest == B) {
				big_char = 'B';
			}
			if (smallest == R) {
				little_char = 'R';
			} else if (smallest == Y) {
				little_char = 'Y';
			} else if (smallest == B) {
				little_char = 'B';
			}
		}
		middle_char = ((('R' + 'Y') + 'B') - big_char) - little_char;
		char last = middle_char;
		for (i = 0; i < largest; i++) {
			ans[2 * i] = big_char;
			ans[(2 * i) + 1] = middle_char;
			last = middle_char;
			middle--;
			if (smallest > middle) {
				int64_t tmp = smallest;
				smallest = middle;
				middle = tmp;
				char tmpchar = little_char;
				little_char = middle_char;
				middle_char = tmpchar;
			}
		}
		i *= 2;
		if ((middle - smallest) >= 2) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		while (i < N) {
			ans[i] = (little_char + middle_char) - last;
			last = ans[i];
			i++;
		}
		printf("%s\n", ans);
		free(ans);
	}
	return 0;
}

void *new_calloc(size_t num, size_t size)
{
	int first_iteration;
	return calloc(num, size);
}
