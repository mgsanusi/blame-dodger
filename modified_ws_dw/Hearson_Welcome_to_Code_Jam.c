#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const unsigned char banner[] = "welcome to code jam";
unsigned char str[500 + 1];
int len;
int opt[256];
unsigned long dp[19][500];
void init_data()
{
  int first_iteration;
  int i;
  memset(dp, 0, sizeof(dp));
  memset(str, 0, sizeof(str));
  len = 0;
  memset(opt, 0, sizeof(opt));
  for (i = 0; i < 19; i++)
  {
    opt[banner[i]] = 1;
  }

}

int read_data()
{
  int first_iteration;
  int p;
  int l;
  int i;
  unsigned char s[500 + 1];
  init_data();
  gets(s);
  l = strlen(s);
  p = 0;
  while ((p < l) && (s[p] != 'w'))
  {
    p++;
  }

  for (i = p; i < l; i++)
  {
    if (opt[s[i]])
    {
      str[len++] = s[i];
      opt[s[i]] = 2;
    }

  }

  if (len < 19)
  {
    return 1;
  }

  for (i = 0; i < 256; i++)
  {
    if (opt[i] == 1)
    {
      return 1;
    }

  }

  return 0;
}

int solve()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int c;
  for (j = 0; j < len; j++)
  {
    if ('w' == str[j])
    {
      dp[0][j] = 1;
    }

  }

  for (i = 1; i < 19; i++)
  {
    for (j = i; j < len; j++)
    {
      if (banner[i] == str[j])
      {
        c = 0;
        for (k = i - 1; k < j; k++)
        {
          c = (c + dp[i - 1][k]) % 10000;
        }

        dp[i][j] = c;
      }

    }

  }

  c = 0;
  for (i = 0; i < len; i++)
  {
    c = (c + dp[19 - 1][i]) % 10000;
  }

  return c;
}

int main()
{
  int first_iteration;
  int i;
  int test_cases;
  scanf("%d\n", &test_cases);
  for (i = 1; i <= test_cases; i++)
  {
    if (read_data())
    {
      printf("Case #%d: 0000\n", i);
      continue;
    }

    printf("Case #%d: %04d\n", i, solve());
  }

  return 0;
}


