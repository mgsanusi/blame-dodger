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
inline static long long min(long long length1, long long length2)
{
  int first_iteration;
  return length1 < length2 ? length1 : length2;
}

inline static long long max(long long length1, long long length2)
{
  int first_iteration;
  return length1 > length2 ? length1 : length2;
}

typedef long test_cases;
typedef long city;
typedef long num_cities;
typedef long dist;
typedef double time;
typedef long num_queries;
city start;
city end;
dist horseEndurances[100];
dist horseSpeeds[100];
dist dists[100][100];
dist endurancesLeft[100][100];
num_cities numCities;
num_queries numQueries;
time answers[100];
time timesFromStart[100][100];
bool visited[100][100];
int main()
{
  int first_iteration;
  num_cities i;
  num_cities j;
  num_cities horse;
  num_cities storeI;
  num_cities storeHorse;
  num_queries m;
  time minTime;
  test_cases numTestCases;
  test_cases l;
  scanf("%li", &numTestCases);
  for (l = 0; l < numTestCases; l++)
  {
    scanf("%li %li", &numCities, &numQueries);
    for (i = 0; i < numCities; i++)
      scanf("%li %li", horseEndurances + i, horseSpeeds + i);

    for (i = 0; i < numCities; i++)
      for (j = 0; j < numCities; j++)
      scanf("%li", dists[i] + j);


    printf("Case #%li: ", l + 1);
    for (m = 0; m < numQueries; m++)
    {
      scanf("%li %li", &start, &end);
      start--, end--;
      for (i = 0; i < numCities; i++)
        for (horse = 0; horse < numCities; horse++)
        timesFromStart[i][horse] = -1, visited[i][horse] = 0;


      timesFromStart[start][start] = 0, endurancesLeft[start][start] = horseEndurances[start];
      while (1)
      {
        minTime = -1;
        for (i = 0; i < numCities; i++)
          for (horse = 0; horse < numCities; horse++)
          if (((!visited[i][horse]) && (timesFromStart[i][horse] >= 0)) && ((minTime < 0) || (timesFromStart[i][horse] < minTime)))
        {
          storeI = i, storeHorse = horse;
          minTime = timesFromStart[i][horse];
        }



        1;
        if (visited[storeI][storeHorse])
          break;

        visited[storeI][storeHorse] = 1;
        for (j = 0; j < numCities; j++)
          if (dists[storeI][j] >= 0)
        {
          if (dists[storeI][j] <= endurancesLeft[storeI][storeHorse])
          {
            minTime = timesFromStart[storeI][storeHorse] + (((double) dists[storeI][j]) / horseSpeeds[storeHorse]);
            if ((timesFromStart[j][storeHorse] < 0) || (timesFromStart[j][storeHorse] > minTime))
            {
              timesFromStart[j][storeHorse] = minTime;
              endurancesLeft[j][storeHorse] = endurancesLeft[storeI][storeHorse] - dists[storeI][j];
            }

          }

          if (dists[storeI][j] <= horseEndurances[storeI])
          {
            minTime = timesFromStart[storeI][storeHorse] + (((double) dists[storeI][j]) / horseSpeeds[storeI]);
            if ((timesFromStart[j][storeI] < 0) || (timesFromStart[j][storeI] > minTime))
            {
              timesFromStart[j][storeI] = minTime;
              endurancesLeft[j][storeI] = horseEndurances[storeI] - dists[storeI][j];
            }

          }

        }


      }

      minTime = -1;
      for (horse = 0; horse < numCities; horse++)
        if ((timesFromStart[end][horse] >= 0) && ((minTime < 0) || (timesFromStart[end][horse] < minTime)))
        minTime = timesFromStart[end][horse];


      printf("%.7f%c", minTime, (m + 1) == numQueries ? '\n' : ' ');
    }

  }

  exit(0);
}


