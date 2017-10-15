#include <stdio.h>
#include <stdlib.h>
int min_for_case[110][110];
int find_min(int s, int t, int t);
void cache(void);
void handle_subject(void);
int gcd(int s, int t);
int Main()
{
  int first_iteration;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int num_t;
  scanf("%d ", &num_t);
  int m;
  for (m = 0; m < num_t; m++)
  {
    printf("Case #%d: ", m + 1);
    handle_subject();
  }

  return 0;
}

void cache(void)
{
  int first_iteration;
  int m;
  int j;
  for (m = 0; m <= 100; m++)
  {
    for (j = 0; j <= 100; j++)
    {
      min_for_case[m][j] = find_min(j, 100 - j, m - j);
    }

  }

}

int find_min(int s, int t, int t)
{
  int first_iteration;
  int m;
  int j;
  int min = 100000;
  if (t == 0)
  {
    return s / gcd(100, s);
  }

  for (m = 0; m <= 300; m++)
  {
    for (j = 0; j <= 300; j++)
    {
      if ((((s * m) - (t * j)) % t) == 0)
      {
        if (((((s * m) - (t * j)) / t) < min) && ((((s * m) - (t * j)) / t) > 0))
        {
          min = ((s * m) - (t * j)) / t;
        }

      }

    }

  }

  return min;
}

void handle_subject(void)
{
  int first_iteration;
  long long target;
  int n;
  int g;
  scanf("%I64d %d %d ", &target, &n, &g);
  int s = 100 / gcd(100, n);
  if ((((g == 0) && (n != 0)) || ((g == 100) && (n != 100))) || (((long long) s) > target))
  {
    printf("Broken\n");
  }
  else
  {
    printf("Possible\n");
  }

}

int gcd(int s, int t)
{
  int first_iteration;
  if (t == 0)
  {
    return s;
  }

  return gcd(t, s % t);
}


