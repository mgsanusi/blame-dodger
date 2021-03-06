#include <stdio.h>
#include <string.h>
int s[600];
int t[600];
int ans[600];
void add(int ret[600], int b[600])
{
  int i;
  int s;
  s = ret[0];
  if (b[0] > ret[0])
    s = b[0];

  for (i = 1; i <= s; i++)
  {
    ret[i] += b[i];
    if (ret[i] > 9)
      ret[i] -= 10, ret[i + 1]++;

  }

  if (ret[s + 1] != 0)
    s++;

  ret[0] = s;
}

void muti(int ret[600], int b[600], int k)
{
  int i;
  int s = b[0];
  int m = 0;
  int s[600];
  memset(s, 0, sizeof(s));
  for (i = 1; i <= s; i++)
  {
    m += b[i] * k;
    s[i] = m % 10;
    m = m / 10;
  }

  while (m > 0)
  {
    s++;
    s[s] = m % 10;
    m = m / 10;
  }

  for (i = 1; i <= s; i++)
    ret[i] = s[i];

  ret[0] = s;
}

int Main()
{
  FILE *Fin = fopen("base1.in", "r");
  FILE *Fout = fopen("base1.out", "w");
  int s;
  int i;
  int j;
  int k;
  int b10;
  int test;
  int dx;
  char ret[80];
  int b[600];
  fscanf(Fin, "%d\n", &test);
  for (b10 = 1; b10 <= test; b10++)
  {
    fgets(ret, 70, Fin);
    for (i = 0; i < 600; i++)
      b[i] = -1;

    dx = 0;
    s = strlen(ret) - 1;
    b[ret[0]] = 1;
    for (i = 1; i < s; i++)
      if (b[ret[i]] == (-1))
    {
      b[ret[i]] = dx;
      dx++;
      if (dx == 1)
        dx++;

    }


    if (dx == 0)
      dx = 2;

    memset(t, 0, sizeof(t));
    memset(ans, 0, sizeof(ans));
    t[0] = (t[1] = (ans[0] = 1));
    for (i = s - 1; i >= 0; i--)
    {
      if (b[ret[i]] > 0)
        muti(s, t, b[ret[i]]), add(ans, s);

      if (i > 0)
        muti(t, t, dx);

    }

    fprintf(Fout, "Case #%d: ", b10);
    for (i = ans[0]; i > 0; i--)
      fprintf(Fout, "%d", ans[i]);

    fprintf(Fout, "\n");
  }

  return 0;
}


