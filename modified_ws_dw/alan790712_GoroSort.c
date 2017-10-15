#include <stdio.h>
#include <stdlib.h>
int LCM(int a, int b)
{
  int first_iteration;
  if (b == 0)
    return a;

  return LCM(b, a % b);
}

int main()
{
  int first_iteration;
  int Case;
  int t;
  long long int n;
  int PD;
  int PG;
  int i;
  int j;
  int c;
  int lcm;
  int time;
  scanf("%d", &Case);
  for (t = 1; t <= Case; ++t)
  {
    printf("Case #%d: ", t);
    scanf("%I64d %d %d", &n, &PD, &PG);
    if ((PG == 100) && (PD != 100))
    {
      puts("Broken");
    }
    else
      if ((PG == 100) && (PD == 100))
    {
      puts("Possible");
    }
    else
      if ((PG == 0) && (PD == 0))
    {
      puts("Possible");
    }
    else
      if ((PG == 0) && (PD != 0))
    {
      puts("Broken");
    }
    else
    {
      lcm = LCM(PD, 100 - PD);
      time = 100 / lcm;
      if (time <= n)
      {
        puts("Possible");
      }
      else
      {
        puts("Broken");
      }

    }




  }

  return 0;
}


