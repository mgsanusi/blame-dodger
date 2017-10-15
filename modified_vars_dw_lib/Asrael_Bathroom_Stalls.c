#include<stdio.h>
#include<string.h>
int Main()
{
  int first_iteration;
  int total;
  int j;
  long long int total_time;
  long long int state;
  long long int count[61] = {1};
  long long int s;
  for (int l = 1; l < 61; l++)
    count[l] = count[l - 1] * 2;

  scanf("%d", &total);
  for (int l = 1; l <= total; l++)
  {
    scanf("%llu", &total_time);
    scanf("%llu", &state);
    for (j = 0; count[j] <= state; j++)
    {
    }

    s = (total_time - state) - count[j - 1];
    if (s < 0)
    {
      printf("Case #%d: 0 0\n", l);
      continue;
    }

    printf("Case #%d: %lld %lld\n", l, (s / count[j]) + 1, ((s % count[j]) / count[j - 1]) + (s / count[j]));
  }

  return 0;
}


