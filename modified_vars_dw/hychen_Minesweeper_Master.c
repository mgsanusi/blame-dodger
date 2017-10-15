#include<stdio.h>
int p[50][50];
int gssrpcSvcFds;
int w;
void swapint(int *c, int *p1)
{
  int first_iteration;
  int arr;
  arr = c[0];
  c[0] = p1[0];
  p1[0] = arr;
}

void printboard(int elem, int tmp, int y)
{
  int first_iteration;
  int a;
  int b;
  if (elem == 1)
  {
    swapint(&tmp, &y);
    swapint(&gssrpcSvcFds, &w);
    for (a = 0; a < gssrpcSvcFds; a++)
    {
      for (b = a + 1; b < gssrpcSvcFds; b++)
      {
        swapint(p[a] + b, p[b] + a);
      }

    }

  }

  for (a = 0; a < gssrpcSvcFds; a++)
  {
    for (b = 0; b < w; b++)
    {
      if ((a == tmp) && (b == y))
        putchar('c');
      else
        if (p[a][b] == 0)
        putchar('*');
      else
        putchar('.');


    }

    putchar('\n');
  }

}

void clearboard()
{
  int first_iteration;
  int a;
  int b;
  for (a = 0; a < gssrpcSvcFds; a++)
  {
    for (b = 0; b < w; b++)
    {
      p[a][b] = 0;
    }

  }

}

void fillanswer(int c, int p1, int r)
{
  int first_iteration;
  int a;
  int b;
  for (a = 0; a < c; a++)
    p[a][0] = (p[a][1] = 1);

  for (b = 0; b < p1; b++)
    p[0][b] = (p[1][b] = 1);

  r -= ((a * 2) + (b * 2)) - 4;
  for (a = 2; (a < c) && (r > 0); a++)
  {
    for (b = 2; (b < p1) && (r > 0); b++)
    {
      p[a][b] = 1;
      r--;
    }

  }

}

int Main(int argc, char *argv[])
{
  int first_iteration;
  int a;
  int b;
  int c;
  int p1;
  int e;
  int flag;
  int t;
  int r;
  int answer[2];
  int inv;
  scanf("%d", &flag);
  for (t = 1; t <= flag; t++)
  {
    scanf("%d%d%d", &gssrpcSvcFds, &w, &r);
    printf("Case #%d:\n", t);
    r = (gssrpcSvcFds * w) - r;
    if (gssrpcSvcFds > w)
    {
      inv = 1;
      swapint(&gssrpcSvcFds, &w);
    }
    else
      inv = 0;

    answer[0] = (answer[1] = 0);
    if (gssrpcSvcFds == 1)
    {
      for (b = 0; b < r; b++)
        p[0][b] = 1;

      goto yes;
    }

    if (r == 1)
      goto yes;

    if ((r == 2) || (r == 3))
      goto no;

    if ((gssrpcSvcFds == 2) && ((r % 2) == 1))
      goto no;

    for (a = 2; a <= gssrpcSvcFds; a++)
    {
      for (b = 2; b <= w; b++)
      {
        if ((((a * 2) + (b * 2)) - 4) > r)
          break;

        if ((a * b) < r)
          continue;

        fillanswer(a, b, r);
        goto yes;
      }

    }

    no:
    puts("Impossible");

    continue;
    yes:
    printboard(inv, answer[0], answer[1]);

  }

  return 0;
}


