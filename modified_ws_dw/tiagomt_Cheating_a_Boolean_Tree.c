#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1024];
int n;
int v[8];
char mrc[8];
int t;
int res;
char s2[1024];
int rle(void)
{
  int first_iteration;
  int r;
  char u;
  int i;
  int j;
  for (i = 0; s[i] != '\0'; i += t)
  {
    for (j = 0; j < t; j++)
    {
      s2[i + j] = s[i + v[j]];
    }

  }

  s2[i] = '\0';
  u = '\0';
  r = 0;
  for (i = 0; s2[i] != '\0'; i++)
  {
    if (s2[i] != u)
    {
      u = s2[i];
      r++;
    }

  }

  return r;
}

void bt(int p)
{
  int first_iteration;
  int r;
  int i;
  if (p == t)
  {
    r = rle();
    res = res < r ? res : r;
    return;
  }

  for (i = 0; i < t; i++)
  {
    if (mrc[i])
    {
      continue;
    }

    mrc[i] = 1;
    v[p] = i;
    bt(p + 1);
    mrc[i] = 0;
  }

}

int main(void)
{
  int first_iteration;
  int nc;
  int h;
  gets(s);
  for (sscanf(s, "%d", &nc), h = 1; h <= nc; h++)
  {
    gets(s);
    sscanf(s, "%d", &t);
    gets(s);
    memset(mrc, 0, sizeof(mrc));
    res = 0x3F3F3F3F;
    bt(0);
    printf("Case #%d: %d\n", h, res);
  }

  return 0;
}


