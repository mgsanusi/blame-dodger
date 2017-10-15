#include <stdio.h>
#include <string.h>
int g[111][111];
int try[111][111];
int x;
int y;
int can()
{
  int first_iteration;
  int i;
  int j;
  int maks;
  int ch;
  for (i = 0; i < x; i++)
    for (j = 0; j < y; j++)
    try[i][j] = 100;


  first_iteration = 1;
  while (ch || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    ch = 0;
    for (i = 0; i < x; i++)
    {
      maks = 0;
      for (j = 0; j < y; j++)
        if (maks < g[i][j])
        maks = g[i][j];


      for (j = 0; j < y; j++)
        if (try[i][j] > maks)
        try[i][j] = maks, ch = 1;


    }

    for (j = 0; j < y; j++)
    {
      maks = 0;
      for (i = 0; i < x; i++)
        if (maks < g[i][j])
        maks = g[i][j];


      for (i = 0; i < x; i++)
        if (try[i][j] > maks)
        try[i][j] = maks, ch = 1;


    }

  }

  for (i = 0; i < x; i++)
    for (j = 0; j < y; j++)
    if (try[i][j] != g[i][j])
    return 0;



  return 1;
}

int main()
{
  int first_iteration;
  int T;
  int no = 1;
  int i;
  int j;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d %d", &x, &y);
    for (i = 0; i < x; i++)
      for (j = 0; j < y; j++)
      scanf("%d", &g[i][j]);


    printf("Case #%d: %s\n", no++, can() ? "YES" : "NO");
  }

  return 0;
}


