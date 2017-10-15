#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long dist;
typedef long time;
typedef long num_horses;
typedef long test_cases;
inline void new_exit(int status);
static long long min(long long length1, long long length2)
{
    return length1 < length2 ? length1 : length2;
}

inline static long long max(long long length1, long long length2)
{
    return length1 > length2 ? length1 : length2;
}

typedef long dist;
typedef long time;
typedef long num_knight;
typedef long test_case;
dist destination;
dist begin_point;
dist speed;
num_horses no_others;
double ans_time;
inline static double divide(int int1, int int2)
{
    return ((double) int1) / ((double) int2);
}

int Main()
{
    num_horses m2;
    test_cases no_test_case;
    test_cases b;
    double store_time;
    scanf("%li", &no_test_case);
    for (b = 0; b < no_test_case; b++) {
	scanf("%li %li", &destination, &no_others);
	for (m2 = 0; m2 < no_others; m2++) {
	    scanf("%li %li", &begin_point, &speed);
	    store_time = divide(destination - begin_point, speed);
	    if ((!m2) || (store_time > ans_time))
		ans_time = store_time;
	}
	printf("Case #%li: %.7f\n", b + 1,
	       ((double) destination) / ans_time);
    }
    new_exit(0);
}

void new_exit(int status)
{
    return exit(status);
}
