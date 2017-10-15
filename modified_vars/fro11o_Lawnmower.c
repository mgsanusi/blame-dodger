#include <stdio.h>
int Main()
{
  int t;
  int now;
  int num_surp;
  int lawn[100][100];
  int ready_h[100];
  int gap[100];
  int i;
  int opt;
  int k;
  int max;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    scanf("%d%d", &now, &num_surp);
    for (opt = 0; opt < now; opt++)
    {
      for (k = 0; k < num_surp; k++)
        scanf("%d", &lawn[opt][k]);

    }

    for (opt = 0; opt < now; opt++)
    {
      max = lawn[opt][0];
      for (k = 1; k < num_surp; k++)
      {
        if (lawn[opt][k] > max)
          max = lawn[opt][k];

      }

      ready_h[opt] = max;
    }

    for (opt = 0; opt < num_surp; opt++)
    {
      max = lawn[0][opt];
      for (k = 1; k < now; k++)
      {
        if (lawn[k][opt] > max)
          max = lawn[k][opt];

      }

      gap[opt] = max;
    }

    for (opt = 0; opt < now; opt++)
    {
      for (k = 0; k < num_surp; k++)
      {
        if (lawn[opt][k] != (ready_h[opt] < gap[k] ? ready_h[opt] : gap[k]))
          break;

      }

      if (k < num_surp)
        break;

    }

    if (opt < now)
      printf("Case #%d: NO\n", i + 1);
    else
      printf("Case #%d: YES\n", i + 1);

  }

  return 0;
}


