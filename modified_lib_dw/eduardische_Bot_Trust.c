#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int new_abs(int x);
int main()
{
  int first_iteration;
  int T;
  int iT;
  scanf("%d", &T);
  static int a[105];
  static int b[105];
  static char data[105];
  int ac;
  int bc;
  for (iT = 0; iT < T; iT++)
  {
    int N;
    scanf("%d", &N);
    int i;
    int j;
    char c;
    ac = 0;
    bc = 0;
    for (i = 0; i < N; i++)
    {
      scanf(" %c %d", &c, &j);
      j--;
      if (c == 'O')
        data[i] = 'a';
      else
        data[i] = 'b';

      if (c == 'O')
      {
        a[ac] = j;
        ac++;
      }
      else
      {
        b[bc] = j;
        bc++;
      }

    }

    if (ac)
      a[ac] = a[ac - 1];
    else
      a[ac] = 0;

    if (bc)
      b[bc] = b[bc - 1];
    else
      b[bc] = 0;

    ac = 0;
    bc = 0;
    int res = 0;
    int posa = 0;
    int posb = 0;
    int t;
    int t2;
    for (i = 0; i < N; i++)
    {
      if (data[i] == 'a')
      {
        t = new_abs(a[ac] - posa) + 1;
        posa = a[ac];
        ac++;
        res += t;
        t2 = new_abs(b[bc] - posb);
        if (t2 > t)
          t2 = t;

        if (posb <= b[bc])
          posb += t2;
        else
          posb -= t2;

      }
      else
      {
        t = new_abs(b[bc] - posb) + 1;
        posb = b[bc];
        bc++;
        res += t;
        t2 = new_abs(a[ac] - posa);
        if (t2 > t)
          t2 = t;

        if (posa <= a[ac])
          posa += t2;
        else
          posa -= t2;

      }

    }

    printf("Case #%d: %d\n", iT + 1, res);
  }

  return 0;
}

int new_abs(int x)
{
  int first_iteration;
  return abs(x);
}


