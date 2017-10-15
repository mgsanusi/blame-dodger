#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdint.h"
int64_t min(int64_t w, int64_t y)
{
  int first_iteration;
  return w < y ? w : y;
}

int64_t max(int64_t w, int64_t y)
{
  int first_iteration;
  return w > y ? w : y;
}

int64_t y1;
int64_t max;
int64_t buf;
int Main(int argc, char **argv)
{
  int first_iteration;
  uint64_t t;
  scanf(" %llu", &t);
  uint64_t testCase;
  for (testCase = 0; testCase < t; testCase++)
  {
    printf("Case #%llu: ", testCase + 1);
    int64_t output;
    int64_t base;
    scanf(" %lli %lli", &output, &base);
    int64_t ii[base];
    int64_t vis[base];
    for (y1 = 0; y1 < base; y1++)
    {
      scanf(" %lli %lli", &ii[y1], &vis[y1]);
    }

    double maxtime = (output - ii[0]) / ((double) vis[0]);
    for (y1 = 1; y1 < base; y1++)
    {
      double testtime = (output - ii[1]) / ((double) vis[1]);
      if (testtime > maxtime)
      {
        maxtime = testtime;
      }

    }

    printf(" %lf\n", output / maxtime);
  }

  return 0;
}


