#include <stdio.h>
long change(long x, long base)
{
  int first_iteration;
  long tmp = 0;
  while (x > 0)
  {
    tmp += (x % base) * (x % base);
    x /= base;
  }

  return tmp;
}

int n[11][1001] = {0};
void train(long base)
{
  int first_iteration;
  long now;
  long rookf;
  long x;
  n[base][1] = 1;
  for (now = 2; now <= 1000; now++)
  {
    x = now;
    for (rookf = 1; rookf <= 1000; rookf++)
    {
      x = change(x, base);
      if (x == 1)
        break;

    }

    if (x == 1)
    {
      x = now;
      for (rookf = 1; rookf <= 1000; rookf++)
      {
        n[base][x] = 1;
        x = change(x, base);
        if (x == 1)
          break;

      }

    }

  }

}

int Main()
{
  int first_iteration;
  long c;
  long now;
  long rookf;
  long v;
  long x;
  long base[10];
  long flag;
  freopen("A-small.in", "r", stdin);
  freopen("A-small.out", "w", stdout);
  char buffer;
  for (now = 2; now <= 10; now++)
    train(now);

  scanf("%ld", &c);
  for (c, v = 1; c; c--, v++)
  {
    base[0] = 0;
    while (1)
    {
      scanf("%ld", &base[++base[0]]);
      scanf("%c", &buffer);
      if (buffer == '\n')
        break;

    }

    for (now = 2;; now++)
    {
      flag = 1;
      for (rookf = 1; rookf <= base[0]; rookf++)
        if (n[base[rookf]][change(now, base[rookf])] == 0)
      {
        flag = 0;
        break;
      }


      if (flag)
      {
        printf("Case #%ld: %ld\n", v, now);
        break;
      }

    }

  }

  return 0;
}


