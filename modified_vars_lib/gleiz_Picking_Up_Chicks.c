#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>
int m[1024];
int min[1024];
int Main(int argc, char *argv[])
{
  int casenum = 0;
  int time = 0;
  int b = 0;
  int n = 0;
  int n1 = 0;
  int cas = 1;
  int answer = 0;
  int high[2];
  int low[2];
  scanf("%d", &n);
  while (n--)
  {
    scanf("%d", &n1);
    for (casenum = 0; casenum < n1; casenum++)
    {
      scanf("%d %d", &m[casenum], &min[casenum]);
    }

    answer = 0;
    for (casenum = 0; casenum < n1; casenum++)
    {
      for (time = casenum + 1; time < n1; time++)
      {
        if (m[casenum] > m[time])
        {
          high[0] = m[casenum];
          high[1] = min[casenum];
          low[0] = m[time];
          low[1] = min[time];
        }
        else
        {
          high[0] = m[time];
          high[1] = min[time];
          low[0] = m[casenum];
          low[1] = min[casenum];
        }

        if (high[1] <= low[1])
        {
          answer++;
        }

      }

    }

    printf("Case #%d: %d\n", cas++, answer);
  }

  return 0;
}


