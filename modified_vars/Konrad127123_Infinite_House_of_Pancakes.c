#include<stdio.h>
int m;
int s;
int s;
int i;
int target;
int answer;
int good;
int p[1024];
int Main()
{
  scanf("%d", &s);
  for (m = 1; m <= s; m++)
  {
    scanf("%d", &i);
    for (s = 0; s < i; s++)
    {
      scanf("%d", &p[s]);
    }

    good = 0;
    for (s = 0; s < i; s++)
      if (p[s] > good)
    {
      good = p[s];
    }


    for (target = good - 1; target > 0; target--)
    {
      answer = target;
      for (s = 0; s < i; s++)
        answer += (p[s] - 1) / target;

      if (good > answer)
        good = answer;

    }

    printf("Case #%d: %d\n", m, good);
  }

  return 0;
}


