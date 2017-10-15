#include <stdio.h>
#include <stdlib.h>
int cmp(const int *x, const int *node)
{
  return (*x) - (*node);
}

int rp[100][100];
int irp[100][100];
char c[100][100];
int len[100];
int Main()
{
  int subject;
  int prev;
  scanf("%d", &subject);
  for (prev = 1; prev <= subject; prev++)
  {
    int z;
    scanf("%d", &z);
    int time;
    for (time = 0; time < z; time++)
    {
      scanf("%c", c[time]);
      while ((c[time][0] > 'z') || (c[time][0] < 'a'))
        scanf("%c", c[time]);

      rp[time][0] = 1;
      char tmp;
      int head = 1;
      while (1)
      {
        scanf("%c", &tmp);
        if ((tmp > 'z') || (tmp < 'a'))
          break;

        if (tmp == c[time][head - 1])
          rp[time][head - 1]++;
        else
        {
          c[time][head] = tmp;
          rp[time][head++] = 1;
        }

      }

      len[time] = head;
    }

    int lose = 0;
    for (time = 0; time < z; time++)
    {
      int j;
      for (j = 0; j < time; j++)
      {
        if (len[time] != len[j])
        {
          lose = 1;
          goto out;
        }

        int k;
        for (k = 0; k < len[time]; k++)
          if (c[time][k] != c[j][k])
        {
          lose = 1;
          goto out;
        }


      }

      for (j = 0; j < len[time]; j++)
        irp[j][time] = rp[time][j];

    }

    for (time = 0; time < len[0]; time++)
      qsort(irp[time], z, sizeof(int), cmp);

    int best = 0;
    for (time = 0; time < len[0]; time++)
    {
      int j;
      for (j = 0; j < z; j++)
      {
        if (j < (z / 2))
          best += irp[time][z / 2] - irp[time][j];
        else
          best += irp[time][j] - irp[time][z / 2];

      }

    }

    out:
    printf("Case #%d: ", prev);

    if (lose)
      printf("Fegla Won\n");
    else
      printf("%d\n", best);

  }

}


