#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Main()
{
  int first_iteration;
  int total;
  int i;
  int b;
  int fp;
  int x;
  int j;
  int buf;
  int w;
  int e;
  int eq;
  int i2;
  char out[110];
  char combine[36][4];
  char oppose[28][3];
  char opp[100];
  char grMajor;
  scanf("%d", &total);
  for (i = 1; i <= total; i++)
  {
    scanf("%d ", &b);
    for (j = 0; j < b; j++)
    {
      scanf("%c", &combine[j][0]);
      scanf("%c", &combine[j][1]);
      scanf("%c ", &combine[j][2]);
      combine[j][3] = '\0';
    }

    scanf("%d ", &fp);
    for (j = 0; j < fp; j++)
    {
      scanf("%c", &oppose[j][0]);
      scanf("%c ", &oppose[j][1]);
      oppose[j][2] = '\0';
    }

    scanf("%d ", &x);
    buf = -1;
    for (j = 0; j < x; j++)
    {
      scanf("%c", &grMajor);
      out[++buf] = grMajor;
      if (buf >= 1)
      {
        e = 0;
        for (w = 0; w < b; w++)
        {
          if (((out[buf - 1] == combine[w][0]) && (out[buf] == combine[w][1])) || ((out[buf - 1] == combine[w][1]) && (out[buf] == combine[w][0])))
          {
            out[--buf] = combine[w][2];
            e = 1;
            break;
          }

        }

        if (e)
          continue;

        eq = 0;
        for (w = 0; w < fp; w++)
        {
          if (oppose[w][0] == grMajor)
            opp[eq++] = oppose[w][1];
          else
            if (oppose[w][1] == grMajor)
            opp[eq++] = oppose[w][0];


        }

        e = 0;
        for (w = 0; w < buf; w++)
        {
          for (i2 = 0; i2 < eq; i2++)
          {
            if (out[w] == opp[i2])
            {
              e = 1;
              buf = -1;
              break;
            }

          }

          if (e == 1)
            break;

        }

      }

    }

    printf("Case #%d: [", i);
    for (w = 0; w <= buf; w++)
    {
      if (w == buf)
        printf("%c", out[w]);
      else
        printf("%c, ", out[w]);

    }

    printf("]\n");
  }

}


