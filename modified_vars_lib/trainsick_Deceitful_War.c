#include <stdio.h>
int currentL;
int newdiam;
int tL;
int minAct;
int exit[1024];
int plugs[1024];
int readbit(void)
{
  static char buf[20];
  int n = 0;
  char *size = buf;
  scanf("%s", buf);
  while (*size)
  {
    n = ((2 * n) + (*(size++))) - '0';
  }

  return n;
}

int bitcount(int n)
{
  int t = 0;
  while (n)
  {
    t++;
    n = n & (n - 1);
  }

  return t;
}

void readcounts(int *a)
{
  int j;
  int n;
  for (j = 0; j < tL; j++)
    a[j] = 0;

  for (j = 0; j < newdiam; j++)
  {
    n = readbit();
    a[n]++;
  }

}

int samexor(int *a, int *n, int x)
{
  int j;
  for (j = 0; j < tL; j++)
  {
    if (a[j ^ x] != n[j])
      return 0;

  }

  return 1;
}

void farm(void)
{
  int n;
  minAct = 1000;
  scanf("%d %d", &newdiam, &currentL);
  tL = 1 << currentL;
  readcounts(exit);
  readcounts(plugs);
  for (n = 0; n < tL; n++)
  {
    if (samexor(exit, plugs, n) && (bitcount(n) < minAct))
      minAct = bitcount(n);

  }

  if (minAct == 1000)
    printf("NOT POSSIBLE\n");
  else
    printf("%d\n", minAct);

}

int Main(int argc, char **argv)
{
  int n;
  int j;
  scanf("%d", &n);
  for (j = 1; j <= n; j++)
  {
    printf("Case #%d: ", j);
    farm();
  }

  return 0;
}


