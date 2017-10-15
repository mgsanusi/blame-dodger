#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdint.h"

#include <stddef.h>
int64_t min(int64_t c, int64_t p)
{
  return c < p ? c : p;
}

int64_t max(int64_t c, int64_t p)
{
  return c > p ? c : p;
}

int64_t sight;
int64_t usi;
int64_t t;
void* new_calloc(size_t num, size_t size);

int Main(int argc, char **argv)
{
  uint64_t t;
  scanf(" %llu", &t);
  uint64_t testCase;
  for (testCase = 0; testCase < t; testCase++)
  {
    printf("Case #%llu: ", testCase + 1);
    int64_t n;
    int64_t used;
    int64_t t1;
    int64_t y;
    int64_t g;
    int64_t p;
    int64_t source;
    scanf(" %lli %lli %lli %lli %lli %lli %lli", &n, &used, &t1, &y, &g, &p, &source);
    int64_t big = max(max(used, y), p);
    int64_t small = min(min(used, y), p);
    int64_t middle = (((used + y) + p) - big) - small;
    if (big > (n / 2))
    {
      printf("IMPOSSIBLE\n");
      continue;
    }

    char *ans = new_calloc(n + 1, 1);
    ans[n] = 0;
    char bigCharacter;
    char littleCharacter;
    char middleCharacter;
    if (big == small)
    {
      if (used == big)
      {
        bigCharacter = 'Y';
        littleCharacter = 'B';
      }
      else
        if (y == big)
      {
        bigCharacter = 'R';
        littleCharacter = 'B';
      }
      else
        if (p == big)
      {
        bigCharacter = 'R';
        littleCharacter = 'Y';
      }



    }
    else
    {
      if (big == used)
      {
        bigCharacter = 'R';
      }
      else
        if (big == y)
      {
        bigCharacter = 'Y';
      }
      else
        if (big == p)
      {
        bigCharacter = 'B';
      }



      if (small == used)
      {
        littleCharacter = 'R';
      }
      else
        if (small == y)
      {
        littleCharacter = 'Y';
      }
      else
        if (small == p)
      {
        littleCharacter = 'B';
      }



    }

    middleCharacter = ((('R' + 'Y') + 'B') - bigCharacter) - littleCharacter;
    char last = middleCharacter;
    for (sight = 0; sight < big; sight++)
    {
      ans[2 * sight] = bigCharacter;
      ans[(2 * sight) + 1] = middleCharacter;
      last = middleCharacter;
      middle--;
      if (small > middle)
      {
        int64_t tmp = small;
        small = middle;
        middle = tmp;
        char tmpchar = littleCharacter;
        littleCharacter = middleCharacter;
        middleCharacter = tmpchar;
      }

    }

    sight *= 2;
    if ((middle - small) >= 2)
    {
      printf("IMPOSSIBLE\n");
      continue;
    }

    while (sight < n)
    {
      ans[sight] = (littleCharacter + middleCharacter) - last;
      last = ans[sight];
      sight++;
    }

    printf("%s\n", ans);
    free(ans);
  }

  return 0;
}



void* new_calloc(size_t num, size_t size) {
  return calloc(num, size);
}