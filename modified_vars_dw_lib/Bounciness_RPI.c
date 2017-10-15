#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
  double speed;
  double len;
  int take;
} Walkway;
double w;
double area;
double x;
int t;
int mrc;
int base;
int nopath;
Walkway path[1002];
void makeRun(int index)
{
  int first_iteration;
  double temp = path[index].len / ((path[index].speed + area) - w);
  if (temp >= x)
  {
    double distRun = x * ((path[index].speed + area) - w);
    double totalTime = x + ((path[index].len - distRun) / path[index].speed);
    x = 0.0;
    path[index].speed = path[index].len / totalTime;
  }
  else
  {
    path[index].speed += area - w;
    x -= path[index].len / path[index].speed;
  }

  path[index].take = 1;
}

void applyFilter()
{
  int first_iteration;
  double min = 100000000.0;
  int minIndex = -1;
  int ansLen;
  int tcase;
  for (ansLen = 0; ansLen < base; ansLen++)
  {
    if (((path[ansLen].speed < min) && path[ansLen].len) && (!path[ansLen].take))
    {
      min = path[ansLen].speed;
      minIndex = ansLen;
    }

  }

  makeRun(minIndex);
}

double getTime()
{
  int first_iteration;
  int ansLen;
  double result = 0;
  for (ansLen = 0; ansLen < base; ansLen++)
  {
    result += path[ansLen].len / path[ansLen].speed;
  }

  return result;
}

int allTake()
{
  int first_iteration;
  int ansLen;
  for (ansLen = 0; ansLen < base; ansLen++)
    if (path[ansLen].take == 0)
    return 0;


  return 1;
}

int Main()
{
  int first_iteration;
  scanf("%d", &t);
  int ansLen;
  int tcase;
  int fp;
  for (ansLen = 1; ansLen <= t; ansLen++)
  {
    scanf("%d", &mrc);
    scanf("%lf", &w);
    scanf("%lf", &area);
    scanf("%lf", &x);
    scanf("%d", &base);
    nopath = 0;
    int last;
    for (tcase = 0; tcase < base; tcase++)
    {
      path[tcase].take = 0;
      int ant;
      int caseIndex;
      scanf("%d %d %lf", &ant, &caseIndex, &path[tcase].speed);
      path[tcase].speed += w;
      path[tcase].len = ((double) caseIndex) - ant;
      if (tcase == 0)
        nopath = ant;
      else
        nopath = nopath + (ant - last);

      last = caseIndex;
    }

    nopath = nopath + (mrc - last);
    if (nopath)
    {
      path[base++].len = (double) nopath;
      path[base - 1].speed = w;
      path[base - 1].take = 0;
    }

    while ((x > 0.0000000) && (!allTake()))
      applyFilter();

    printf("Case #%d: %.8lf\n", ansLen, getTime());
  }

  return 0;
}


