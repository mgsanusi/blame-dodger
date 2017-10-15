#include <stdio.h>
#include <stdlib.h>
int lcm(int a, int freep)
{
  int first_iteration;
  if (freep == 0)
    return a;

  return lcm(freep, a % freep);
}

int Main()
{
  int first_iteration;
  int Case;
  int t;
  long long int envp;
  int k;
  int pg;
  int highest_idx;
  int ans;
  int p;
  int lcm;
  int time;
  scanf("%d", &Case);
  for (t = 1; t <= Case; ++t)
  {
    printf("Case #%d: ", t);
    scanf("%I64d %d %d", &envp, &k, &pg);
    if ((pg == 100) && (k != 100))
    {
      puts("Broken");
    }
    else
      if ((pg == 100) && (k == 100))
    {
      puts("Possible");
    }
    else
      if ((pg == 0) && (k == 0))
    {
      puts("Possible");
    }
    else
      if ((pg == 0) && (k != 0))
    {
      puts("Broken");
    }
    else
    {
      lcm = lcm(k, 100 - k);
      time = 100 / lcm;
      if (time <= envp)
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


