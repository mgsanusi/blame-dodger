#include <stdio.h>
int ti;
int bluePos;
int j;
int s;
int v;
int t;
int t[4];
int ans;
int Main()
{
  fscanf(stdin, "%d", &bluePos);
  for (ti = 1; ti <= bluePos; ++ti)
  {
    fprintf(stdout, "Case #%d: ", ti);
    fscanf(stdin, "%d%d", &s, &v);
    for (j = (ans = (t[1] = (t[2] = (t[3] = 0)))); j < s; ++j)
    {
      fscanf(stdin, "%d", &t);
      if ((t % v) == 0)
        ++ans;
      else
        ++t[t % v];

    }

    if (v == 2)
      ans += (t[1] + 1) / 2;
    else
      if (v == 3)
    {
      if (t[1] > t[2])
      {
        t[1] ^= t[2];
        t[2] ^= t[1];
        t[1] ^= t[2];
      }

      ans += t[1];
      t[2] -= t[1];
      ans += (t[2] + 2) / 3;
    }
    else
    {
      t = t[1] < t[3] ? t[1] : t[3];
      ans += t;
      t[1] -= t;
      t[3] -= t;
      ans += ((t[1] + t[3]) + 3) / 4;
      ans += (t[2] + 1) / 2;
    }


    fprintf(stdout, "%d\n", ans);
  }

  return 0;
}


