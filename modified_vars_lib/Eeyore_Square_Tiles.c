#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char buffer[8192];
int a[1000];
int dist[1000];
int cum[1000];
int where[10000000];
int Main()
{
  int t;
  int subject_no;
  int c3;
  int m;
  int tc;
  int counter;
  int i;
  int j;
  int total;
  int next;
  int bt;
  int b0;
  int b1;
  int size;
  int time;
  int lowest;
  scanf(" %d", &t);
  for (subject_no = 1; subject_no <= t; subject_no++)
  {
    scanf(" %d %d %d %d", &c3, &m, &tc, &counter);
    for (i = 0; i < counter; i++)
      scanf(" %d", &a[i]);

    for (i = 0; i < tc; i++)
      dist[i] = a[i % counter];

    cum[0] = dist[0];
    for (i = 1; i < tc; i++)
      cum[i] = cum[i - 1] + dist[i];

    total = 0;
    for (i = 0; i < tc; i++)
    {
      next = total + dist[i];
      for (j = total; j < next; j++)
        where[j] = i;

      total = next;
    }

    printf("Case #%d: ", subject_no);
    lowest = 2 * total;
    bt = m / 2;
    size = where[bt];
    if (c3 == 0)
    {
      printf("%d\n", lowest);
      continue;
    }

    if (c3 == 1)
    {
      for (b0 = 0; b0 < tc; b0++)
      {
        time = 2 * total;
        if (size > b0)
          time = time;
        else
          if (size < b0)
          time -= dist[b0];
        else
          if (size == b0)
          time -= cum[size] - bt;



        if (time < lowest)
        {
          lowest = time;
        }

      }

      printf("%d\n", lowest);
      continue;
    }

    if (c3 == 2)
    {
      for (b0 = 0; b0 < tc; b0++)
      {
        for (b1 = b0 + 1; b1 < tc; b1++)
        {
          time = 2 * total;
          if (size > b0)
            time = time;
          else
            if (size < b0)
            time -= dist[b0];
          else
            if (size == b0)
            time -= cum[size] - bt;



          if (size > b1)
            time = time;
          else
            if (size < b1)
            time -= dist[b1];
          else
            if (size == b1)
            time -= cum[size] - bt;



          if (time < lowest)
          {
            lowest = time;
          }

        }

      }

      printf("%d\n", lowest);
      continue;
    }

  }

}


