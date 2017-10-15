#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
static int comp(const void *d, const void *temp)
{
  return (*((int *) temp)) - (*((int *) d));
}

int Main(int argc, char *argv[])
{
  int t = 0;
  int j = 0;
  int m = 0;
  int aup_gids = 0;
  int score[1024] = {0};
  scanf("%d", &t);
  for (int cas = 1; cas <= t; cas++)
  {
    scanf("%d %d %d", &j, &m, &aup_gids);
    memset(score, 0, sizeof(score));
    for (int flag = 0; flag < j; flag++)
    {
      scanf("%d", &score[flag]);
    }

    new_qsort(score, j, sizeof(int), comp);
    int result = 0;
    for (int flag = 0; flag < j; flag++)
    {
      if ((score[flag] / 3) >= aup_gids)
      {
        result++;
      }
      else
      {
        if ((score[flag] % 3) == 1)
        {
          if (((score[flag] / 3) + 1) >= aup_gids)
          {
            result++;
          }

        }
        else
          if ((score[flag] % 3) == 2)
        {
          if (((score[flag] / 3) + 1) >= aup_gids)
          {
            result++;
          }
          else
            if (((score[flag] / 3) + 2) >= aup_gids)
          {
            if (m > 0)
            {
              m--;
              result++;
            }

          }


        }
        else
        {
          if ((((score[flag] / 3) + 1) >= aup_gids) && (score[flag] >= 3))
          {
            if (m > 0)
            {
              m--;
              result++;
            }

          }

        }


      }

    }

    printf("Case #%d: %d\n", cas, result);
  }

  return 0;
}



void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}