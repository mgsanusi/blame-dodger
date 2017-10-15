#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long test_cases;
typedef long city;
typedef long num_cities;
typedef long dist;
typedef double time;
typedef long num_queries;
typedef long no_queries;
inline void new_exit(int status);
static long long min(long long length1, long long length2)
{
    int first_iteration;
    return length1 < length2 ? length1 : length2;
}

inline static long long max(long long length1, long long length2)
{
    int first_iteration;
    return length1 > length2 ? length1 : length2;
}

typedef long no_queries;
city start;
city goal;
dist horse_endurances[100];
dist horse_speed[100];
dist dists[100][100];
dist endurances_left[100][100];
num_cities numCities;
num_queries numQueries;
time answer[100];
time time_from_start[100][100];
bool visit[100][100];
int Main()
{
    int first_iteration;
    num_cities i;
    num_cities num_test_cases;
    num_cities horse;
    num_cities store_i;
    num_cities store_horse;
    num_queries m;
    time min_time;
    test_cases num_test_case;
    test_cases p;
    scanf("%li", &num_test_case);
    for (p = 0; p < num_test_case; p++) {
	scanf("%li %li", &numCities, &numQueries);
	for (i = 0; i < numCities; i++)
	    scanf("%li %li", horse_endurances + i, horse_speed + i);
	for (i = 0; i < numCities; i++)
	    for (num_test_cases = 0; num_test_cases < numCities;
		 num_test_cases++)
		scanf("%li", dists[i] + num_test_cases);
	printf("Case #%li: ", p + 1);
	for (m = 0; m < numQueries; m++) {
	    scanf("%li %li", &start, &goal);
	    start--, goal--;
	    for (i = 0; i < numCities; i++)
		for (horse = 0; horse < numCities; horse++)
		    time_from_start[i][horse] = -1, visit[i][horse] = 0;
	    time_from_start[start][start] =
		0, endurances_left[start][start] = horse_endurances[start];
	    while (1) {
		min_time = -1;
		for (i = 0; i < numCities; i++)
		    for (horse = 0; horse < numCities; horse++)
			if (((!visit[i][horse])
			     && (time_from_start[i][horse] >= 0))
			    && ((min_time < 0)
				|| (time_from_start[i][horse] <
				    min_time))) {
			    store_i = i, store_horse = horse;
			    min_time = time_from_start[i][horse];
			}
		1;
		if (visit[store_i][store_horse])
		    break;
		visit[store_i][store_horse] = 1;
		for (num_test_cases = 0; num_test_cases < numCities;
		     num_test_cases++)
		    if (dists[store_i][num_test_cases] >= 0) {
			if (dists[store_i][num_test_cases] <=
			    endurances_left[store_i][store_horse]) {
			    min_time =
				time_from_start[store_i][store_horse] +
				(((double) dists[store_i][num_test_cases])
				 / horse_speed[store_horse]);
			    if ((time_from_start[num_test_cases]
				 [store_horse] < 0)
				||
				(time_from_start[num_test_cases]
				 [store_horse] > min_time)) {
				time_from_start[num_test_cases]
				    [store_horse] = min_time;
				endurances_left[num_test_cases]
				    [store_horse] =
				    endurances_left[store_i][store_horse] -
				    dists[store_i][num_test_cases];
			    }
			}
			if (dists[store_i][num_test_cases] <=
			    horse_endurances[store_i]) {
			    min_time =
				time_from_start[store_i][store_horse] +
				(((double) dists[store_i][num_test_cases])
				 / horse_speed[store_i]);
			    if ((time_from_start[num_test_cases][store_i] <
				 0)
				||
				(time_from_start[num_test_cases][store_i] >
				 min_time)) {
				time_from_start[num_test_cases][store_i] =
				    min_time;
				endurances_left[num_test_cases][store_i] =
				    horse_endurances[store_i] -
				    dists[store_i][num_test_cases];
			    }
			}
		    }
	    }
	    min_time = -1;
	    for (horse = 0; horse < numCities; horse++)
		if ((time_from_start[goal][horse] >= 0)
		    && ((min_time < 0)
			|| (time_from_start[goal][horse] < min_time)))
		    min_time = time_from_start[goal][horse];
	    printf("%.7f%c", min_time, (m + 1) == numQueries ? '\n' : ' ');
	}
    }
    new_exit(0);
}

void new_exit(int status)
{
    return exit(status);
}
