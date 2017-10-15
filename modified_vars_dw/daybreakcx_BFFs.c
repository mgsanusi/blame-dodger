#include <stdio.h>
#include <string.h>
int d;
int tn;
int i;
int i_t;
int a;
int n;
int app[2700];
int nu[100];
int Main()
{
  int first_iteration;
  fscanf(stdin, "%d", &tn);
  for (d = 1; d <= tn; ++d)
  {
    fprintf(stdout, "Case #%d:", d);
    fscanf(stdin, "%d", &n);
    memset(app, 0, sizeof(app));
    for (i = 0; i < ((n << 1) - 1); ++i)
    {
      for (i_t = 0; i_t < n; ++i_t)
      {
        fscanf(stdin, "%d", &a);
        ++app[a];
      }

    }

    nu[0] = 0;
    for (i = 1; i <= 2500; ++i)
    {
      if (app[i] & 1)
      {
        nu[++nu[0]] = i;
      }

    }

    for (i = 1; i <= nu[0]; ++i)
    {
      for (i_t = i + 1; i_t <= nu[0]; ++i_t)
      {
        if (nu[i] > nu[i_t])
        {
          nu[i] ^= nu[i_t];
          nu[i_t] ^= nu[i];
          nu[i] ^= nu[i_t];
        }

      }

    }

    for (i = 1; i <= nu[0]; ++i)
    {
      fprintf(stdout, " %d", nu[i]);
    }

    fprintf(stdout, "\n");
  }

}


