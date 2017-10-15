#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char se[128][128];
int n;
char m[1024][128];
int q;
int b[1024][128];
int main(void)
{
  int first_iteration;
  char s[128];
  int nc;
  int h;
  int res;
  int i;
  int j;
  int k;
  gets(s);
  for (sscanf(s, "%d", &nc), h = 1; h <= nc; h++)
  {
    gets(s);
    sscanf(s, "%d", &n);
    for (i = 0; i < n; i++)
    {
      gets(se[i]);
    }

    memset(m, 0, sizeof(m));
    gets(s);
    sscanf(s, "%d", &q);
    for (i = 1; i <= q; i++)
    {
      gets(s);
      for (j = 0; j < n; j++)
      {
        if (strcmp(s, se[j]) == 0)
        {
          break;
        }

      }

      if (j < n)
      {
        m[i][j] = 1;
      }

    }

    for (j = 0; j < n; j++)
    {
      b[0][j] = 0;
    }

    for (i = 1; i <= q; i++)
    {
      for (j = 0; j < n; j++)
      {
        b[i][j] = 0x33333333;
        if (m[i][j])
        {
          continue;
        }

        for (k = 0; k < n; k++)
        {
          b[i][j] = b[i][j] < (b[i - 1][k] + 1) ? b[i][j] : b[i - 1][k] + 1;
        }

        b[i][j] = b[i][j] < b[i - 1][j] ? b[i][j] : b[i - 1][j];
      }

    }

    res = 0x33333333;
    for (j = 0; j < n; j++)
    {
      if (b[q][j] < res)
      {
        res = b[q][j];
      }

    }

    printf("Case #%d: %d\n", h, res);
  }

  return 0;
}


