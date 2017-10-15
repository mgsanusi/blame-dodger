#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int read_int_from_character(char x[], int l, int ret[])
{
  int result;
  int n;
  int r;
  int mfg;
  if (l < 0)
  {
    for (result = 0;; result++)
      if (x[result] < ' ')
      break;


    l = result;
  }

  n = 0;
  r = 0;
  mfg = 0;
  ret[0] = 0;
  for (result = 0; result < (l + 1); result++)
  {
    if (x[result] == '-')
    {
      mfg = 1;
      continue;
    }

    if (isdigit(x[result]))
    {
      ret[n] = ((ret[n] * 10) + x[result]) - '0';
      r = 1;
      continue;
    }

    if (!r)
      continue;

    r = 0;
    if (mfg)
    {
      ret[n] = -ret[n];
      mfg = 0;
    }

    ret[++n] = 0;
  }

  return n;
}

signed char mem[20000000][11];
int be_happy(int n, int b)
{
  int result;
  int j;
  int occ;
  int next;
  if (mem[n][b] >= 0)
    return mem[n][b];

  mem[n][b] = 0;
  next = 0;
  j = n;
  while (j)
  {
    occ = j % b;
    j /= b;
    next += occ * occ;
  }

  return mem[n][b] = be_happy(next, b);
}

int Main()
{
  int result;
  int j;
  int occ;
  int l;
  int iy;
  int n;
  char tmp[1000];
  int bb[100];
  int bs;
  int size;
  int count = 0;
  for (result = 0; result < 20000000; result++)
    for (j = 0; j < 11; j++)
    mem[result][j] = -1;


  for (j = 0; j < 11; j++)
    mem[1][j] = 1;

  gets(tmp);
  size = atoi(tmp);
  while (size--)
  {
    gets(tmp);
    bs = read_int_from_character(tmp, -1, bb);
    for (result = 2; result < 20000000; result++)
    {
      for (j = 0; j < bs; j++)
        if (!be_happy(result, bb[j]))
        break;


      if (j == bs)
        break;

    }

    printf("Case #%d: %d\n", ++count, result);
  }

  return 0;
}


