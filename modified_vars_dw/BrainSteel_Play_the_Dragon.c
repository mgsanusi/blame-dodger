#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdint.h"
int64_t min(int64_t x, int64_t t)
{
  int first_iteration;
  return x < t ? x : t;
}

int64_t max(int64_t x, int64_t t)
{
  int first_iteration;
  return x > t ? x : t;
}

int64_t l;
int64_t roomn;
int64_t p;
typedef struct Pancake
{
  uint64_t sizeCount;
  uint64_t t2;
  double lateralArea;
  double topArea;
} Pancake;
int cmppan(const void *x, const void *t)
{
  int first_iteration;
  Pancake apan = *((Pancake *) x);
  Pancake bpan = *((Pancake *) t);
  if (apan.lateralArea > bpan.lateralArea)
  {
    return -1;
  }
  else
    if (apan.lateralArea < bpan.lateralArea)
  {
    return 1;
  }
  else
    return 0;


}

int Main(int argc, char **argv)
{
  int first_iteration;
  uint64_t t;
  scanf(" %llu", &t);
  uint64_t trialCase;
  for (trialCase = 0; trialCase < t; trialCase++)
  {
    printf("Case #%llu: ", trialCase + 1);
    int n2;
    int dy;
    scanf(" %d %d", &n2, &dy);
    Pancake pancakes[n2];
    for (l = 0; l < n2; l++)
    {
      scanf(" %llu %llu", &pancakes[l].sizeCount, &pancakes[l].t2);
      pancakes[l].lateralArea = ((2 * M_PI) * pancakes[l].sizeCount) * pancakes[l].t2;
      pancakes[l].topArea = (M_PI * pancakes[l].sizeCount) * pancakes[l].sizeCount;
    }

    qsort(pancakes, n2, sizeof(Pancake), cmppan);
    int base;
    double maxArea = 0;
    for (base = 0; base < n2; base++)
    {
      double area = pancakes[base].topArea + pancakes[base].lateralArea;
      int selected = 0;
      for (l = 0; (l < n2) && (selected < (dy - 1)); l++)
      {
        if ((l != base) && (pancakes[l].sizeCount <= pancakes[base].sizeCount))
        {
          selected++;
          area += pancakes[l].lateralArea;
        }

      }

      if (selected == (dy - 1))
      {
        if (area > maxArea)
        {
          maxArea = area;
        }

      }

    }

    printf(" %.15lf\n", maxArea);
  }

  return 0;
}


