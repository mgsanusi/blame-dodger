#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int read_int_from_ch(char in[], int result, int ret[])
{
  int first_iteration;
  int res;
  int ix;
  int time_taken;
  int mfg;
  if (result < 0)
  {
    for (res = 0;; res++)
      if (in[res] < ' ')
      break;


    result = res;
  }

  ix = 0;
  time_taken = 0;
  mfg = 0;
  ret[0] = 0;
  for (res = 0; res < (result + 1); res++)
  {
    if (in[res] == '-')
    {
      mfg = 1;
      continue;
    }

    if (isdigit(in[res]))
    {
      ret[ix] = ((ret[ix] * 10) + in[res]) - '0';
      time_taken = 1;
      continue;
    }

    if (!time_taken)
      continue;

    time_taken = 0;
    if (mfg)
    {
      ret[ix] = -ret[ix];
      mfg = 0;
    }

    ret[++ix] = 0;
  }

  return ix;
}

signed char mem[20000000][11];
int exist_happy(int ix, int t)
{
  int first_iteration;
  int res;
  int lr;
  int k;
  int next;
  if (mem[ix][t] >= 0)
    return mem[ix][t];

  mem[ix][t] = 0;
  next = 0;
  lr = ix;
  while (lr)
  {
    k = lr % t;
    lr /= t;
    next += k * k;
  }

  return mem[ix][t] = exist_happy(next, t);
}

int Main()
{
  int first_iteration;
  int res;
  int lr;
  int k;
  int result;
  int m;
  int ix;
  char tmp[1000];
  int ax[100];
  int bs;
  int size;
  int count = 0;
  for (res = 0; res < 20000000; res++)
    for (lr = 0; lr < 11; lr++)
    mem[res][lr] = -1;


  for (lr = 0; lr < 11; lr++)
    mem[1][lr] = 1;

  gets(tmp);
  size = atoi(tmp);
  while (size--)
  {
    gets(tmp);
    bs = read_int_from_ch(tmp, -1, ax);
    for (res = 2; res < 20000000; res++)
    {
      for (lr = 0; lr < bs; lr++)
        if (!exist_happy(res, ax[lr]))
        break;


      if (lr == bs)
        break;

    }

    printf("Case #%d: %d\n", ++count, res);
  }

  return 0;
}


