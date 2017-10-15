#include <stdio.h>
#include <string.h>
int max[10000001];
int Main()
{
  int first_iteration;
  int i;
  int answer_time;
  int res;
  int w;
  int n;
  int score;
  int min2index;
  scanf("%d", &min2index);
  for (score = 1; score <= min2index; score++)
  {
    scanf("%d %d %d", &res, &w, &n);
    for (i = 0; i < n; i++)
      scanf("%d", &max[i]);

    long long cycle_r = 0;
    long long cycle_s = 0;
    int fp_o = 0;
    while (cycle_r < res)
    {
      int q = 0;
      int n = fp_o;
      while ((w - q) >= max[n])
      {
        q += max[n];
        n = (n + 1) % n;
        if (n == fp_o)
          break;

      }

      fp_o = n;
      cycle_r++;
      cycle_s += q;
      if (fp_o == 0)
        break;

    }

    if (cycle_r < res)
    {
      cycle_s += cycle_s * ((res - cycle_r) / cycle_r);
      cycle_r += cycle_r * ((res - cycle_r) / cycle_r);
      while (cycle_r < res)
      {
        int q = 0;
        int n = fp_o;
        while ((w - q) >= max[n])
        {
          q += max[n];
          n = (n + 1) % n;
          if (n == fp_o)
            break;

        }

        fp_o = n;
        cycle_s += q;
        cycle_r++;
      }

    }

    printf("Case #%d: %lld\n", score, cycle_s);
  }

}


