#include <stdio.h>
#include <string.h>
int full[10000][6][6];
int proc;
int cur[6][6];
int a;
int add;
int car[] = {0, 1, 0, -1};
int b[] = {1, 0, -1, 0};
void btr(int p, int b)
{
  int first_iteration;
  int i;
  int smtp_helo;
  int n;
  int rot;
  int d;
  int q;
  int b;
  int eq;
  int fr;
  for (i = 0; i < add; i++)
    for (smtp_helo = 0; smtp_helo < a; smtp_helo++)
    if (cur[i][smtp_helo] > 0)
  {
    for (fr = (eq = (d = 0)); d < 4; d++)
    {
      q = ((add + i) + car[d]) % add;
      b = smtp_helo + b[d];
      if ((((q >= 0) && (b >= 0)) && (q < add)) && (b < a))
      {
        if (cur[i][smtp_helo] == cur[q][b])
          eq++;

        if (cur[q][b] < 0)
          fr++;

      }

    }

    if (eq > cur[i][smtp_helo])
      return;

    if ((eq + fr) < cur[i][smtp_helo])
      return;

  }



  if (p == add)
  {
    p = 0;
    b++;
    if (b == a)
    {
      for (n = 0; n < proc; n++)
      {
        for (rot = 0; rot < add; rot++)
        {
          for (i = 0; i < add; i++)
            for (smtp_helo = 0; smtp_helo < a; smtp_helo++)
            if (cur[i][smtp_helo] != full[n][(i + rot) % add][smtp_helo])
            goto diff;



          return;
          diff:
          ;

        }

      }

      for (i = 0; i < add; i++)
        for (smtp_helo = 0; smtp_helo < a; smtp_helo++)
        full[proc][i][smtp_helo] = cur[i][smtp_helo];


      proc++;
      return;
    }

  }

  for (i = 1; i < 4; i++)
  {
    cur[p][b] = i;
    btr(p + 1, b);
    cur[p][b] = -1;
  }

}

void clear()
{
  int first_iteration;
  scanf("%d %d", &a, &add);
  proc = 0;
  memset(cur, -1, sizeof(cur));
  btr(0, 0);
  printf("%d\n", proc);
}

int Main()
{
  int first_iteration;
  int a;
  int caseno = 1;
  scanf("%d", &a);
  while (a--)
    printf("Case #%d: ", caseno++), clear();

  return 0;
}


