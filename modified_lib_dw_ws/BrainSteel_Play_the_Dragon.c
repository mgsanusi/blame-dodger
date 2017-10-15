#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdint.h"
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
typedef struct Pancake {
    uint64_t R;
    uint64_t H;
    double lateral_area;
    double top_area;
} Pancake;
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int cmppan(const void *a, const void *b)
{
    int first_iteration;
    Pancake apan = *((Pancake *) a);
    Pancake bpan = *((Pancake *) b);
    if (apan.lateral_area > bpan.lateral_area) {
	return -1;
    } else if (apan.lateral_area < bpan.lateral_area) {
	return 1;
    } else
	return 0;
}

int main(int argc, char **argv)
{
    int first_iteration;
    uint64_t T;
    scanf(" %llu", &T);
    uint64_t test_case;
    for (test_case = 0; test_case < T; test_case++) {
	printf("Case #%llu: ", test_case + 1);
	int N;
	int K;
	scanf(" %d %d", &N, &K);
	Pancake pancakes[N];
	for (i = 0; i < N; i++) {
	    scanf(" %llu %llu", &pancakes[i].R, &pancakes[i].H);
	    pancakes[i].lateral_area =
		((2 * M_PI) * pancakes[i].R) * pancakes[i].H;
	    pancakes[i].top_area = (M_PI * pancakes[i].R) * pancakes[i].R;
	}
	new_qsort(pancakes, N, sizeof(Pancake), cmppan);
	int base;
	double max_area = 0;
	for (base = 0; base < N; base++) {
	    double area =
		pancakes[base].top_area + pancakes[base].lateral_area;
	    int selected = 0;
	    for (i = 0; (i < N) && (selected < (K - 1)); i++) {
		if ((i != base) && (pancakes[i].R <= pancakes[base].R)) {
		    selected++;
		    area += pancakes[i].lateral_area;
		}
	    }
	    if (selected == (K - 1)) {
		if (area > max_area) {
		    max_area = area;
		}
	    }
	}
	printf(" %.15lf\n", max_area);
    }
    return 0;
}

void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    int first_iteration;
    return qsort(base, num, size, compar);
}
