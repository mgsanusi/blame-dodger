#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int x;
int y;
int tmp1;
char bb[510][510];
int sum[510][510];
int tmp[510][510];
int get_sum(int x1, int x2, int prfl, int y2)
{
  int first_iteration;
  return ((sum[x2 + 1][y2 + 1] - sum[x1][y2 + 1]) - sum[x2 + 1][prfl]) + sum[x1][prfl];
}

int Main()
{
  int first_iteration;
  int c;
  int j;
  int k;
  int input_file_name;
  int m;
  int t;
  int rslt;
  int x_st;
  int y_st;
  int x_ed;
  int y_ed;
  int len;
  int r;
  int b;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    fprintf(stderr, "size %d\n", size);
    scanf("%d%d%d", &x, &y, &t);
    for (c = 0; c < x; c++)
      scanf("%s", bb[c]);

    for (c = 0; c < x; c++)
      for (j = 0; j < y; j++)
      bb[c][j] -= '0';


    for (c = 0; c < x; c++)
    {
      tmp[c][0] = 0;
      for (j = 0; j < y; j++)
        tmp[c][j + 1] = tmp[c][j] + bb[c][j];

    }

    for (j = 0; j < (y + 1); j++)
    {
      sum[0][j] = 0;
      for (c = 0; c < x; c++)
        sum[c + 1][j] = sum[c][j] + tmp[c][j];

    }

    rslt = 2;
    tmp1 = x;
    if (tmp1 > y)
      tmp1 = y;

    for (k = 3; k < (tmp1 + 1); k++)
    {
      len = k / 2;
      for (x_st = 0; x_st < ((x - k) + 1); x_st++)
        for (y_st = 0; y_st < ((y - k) + 1); y_st++)
      {
        x_ed = (x_st + k) - 1;
        y_ed = (y_st + k) - 1;
        r = (get_sum(x_st, x_st + (len - 1), y_st, y_ed) - bb[x_st][y_st]) - bb[x_st][y_ed];
        b = (get_sum(x_ed - (len - 1), x_ed, y_st, y_ed) - bb[x_ed][y_st]) - bb[x_ed][y_ed];
        if (r != b)
          continue;

        r = (get_sum(x_st, x_ed, y_st, y_st + (len - 1)) - bb[x_st][y_st]) - bb[x_ed][y_st];
        b = (get_sum(x_st, x_ed, y_ed - (len - 1), y_ed) - bb[x_st][y_ed]) - bb[x_ed][y_ed];
        if (r != b)
          continue;

        rslt = k;
      }


    }

    printf("Case #%d: ", ++count);
    if (rslt <= 2)
    {
      puts("IMPOSSIBLE");
      continue;
    }

    printf("%d\n", rslt);
  }

  return 0;
}


