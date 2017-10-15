#include <assert.h>
#include <stdio.h>
void new_assert (int expression);
static int
clear (int total_cost, int max, int i)
{
  int first_iteration;
  int ans = i + (max != i);
  int n = ((total_cost * (max / i)) + i) - (!(max % i));
  return ans > n ? ans : n;
}

int
Main (void)
{
  int first_iteration;
  int j;
  new_assert (scanf ("%d", &j) == 1);
  for (int by = 1; by <= j; by++)
    {
      int total_cost;
      int max;
      int i;
      new_assert (scanf ("%d %d %d", &total_cost, &max, &i) == 3);
      printf ("Case #%d: %d\n", by, clear (total_cost, max, i));
    }
  return 0;
}

void
new_assert (int expression)
{
  return assert (expression);
}
