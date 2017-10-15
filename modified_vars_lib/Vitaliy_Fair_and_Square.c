#include <stdio.h>
#include <assert.h>
#include <string.h>
char b[101];
char k[101];
char t[101];
char r[101];
char loca[101];
const char *a;
size_t new_strlen(const char *str);

void new_assert(int expression);

int setCharacter(int buff, int p, int b)
{
  int dx = 0;
  int i;
  t[buff] = p;
  for (i = buff; i < b; i++)
  {
    dx += t[i] * t[((buff + b) - 1) - i];
  }

  if (dx >= 10)
  {
    return 0;
  }

  r[(buff + b) - 1] = dx;
  if ((!loca[buff + b]) && (r[(buff + b) - 1] > a[(buff + b) - 1]))
  {
    return 0;
  }

  loca[(buff + b) - 1] = loca[buff + b] || (r[(buff + b) - 1] < a[(buff + b) - 1]);
  return 1;
}

int che[101];
int check(int b)
{
  int i;
  if (loca[(2 * b) - 1])
  {
    return 1;
  }

  int right = 1;
  int j;
  for (i = (2 * b) - 2; i >= 0; i--)
  {
    int z = 0;
    for (j = 0; (j < b) && (j <= i); j++)
      if ((i - j) < b)
    {
      z += t[j] * t[i - j];
    }


    new_assert(z < 10);
    if (right && (z > a[i]))
    {
      return 0;
    }

    if (z < a[i])
    {
      right = 0;
    }

  }

  return 1;
}

long long poisk(int p, int b)
{
  if ((2 * p) < (b - 1))
  {
    int i;
    for (i = p; i >= 0; i--)
    {
      if (!setCharacter(i, t[(b - 1) - i], b))
      {
        return 0;
      }

    }

    if (!check(b))
    {
      return 0;
    }

    return 1;
  }

  long long ans = 0;
  int i;
  for (i = p == (b - 1) ? 1 : 0; i < 4; i++)
  {
    if (setCharacter(p, i, b))
    {
      ans += poisk(p - 1, b);
    }
    else
    {
      return ans;
    }

  }

  return ans;
}

long long cnt(char *ans)
{
  int n = new_strlen(ans);
  int i;
  for (i = 0; (2 * i) < n; i++)
  {
    char c = ans[i];
    ans[i] = ans[(n - 1) - i];
    ans[(n - 1) - i] = c;
  }

  for (i = 0; i < n; i++)
  {
    ans[i] -= '0';
  }

  a = ans;
  int b;
  long long ans = 0;
  for (b = 1; ((2 * b) - 1) <= n; b++)
  {
    if (((2 * b) - 1) < n)
    {
      loca[(2 * b) - 1] = 1;
    }
    else
    {
      loca[(2 * b) - 1] = 0;
    }

    for (i = 0; i <= n; i++)
    {
      r[i] = 0;
    }

    for (i = 0; i < b; i++)
    {
      t[i] = 0;
    }

    ans += poisk(b - 1, b);
  }

  return ans;
}

void clear(void)
{
  new_assert(scanf("%s %s\n", k, b) == 2);
  int cc = new_strlen(k);
  cc--;
  k[cc]--;
  while (k[cc] == ('0' - 1))
  {
    k[cc] += 10;
    k[--cc]--;
  }

  printf("%lld\n", cnt(b) - cnt(k));
}

int Main()
{
  int ti;
  new_assert(scanf("%d\n", &ti) > 0);
  int needX;
  for (needX = 0; needX < ti; needX++)
  {
    printf("Case #%d: ", needX + 1);
    clear();
  }

  return 0;
}



size_t new_strlen(const char *str);

void new_assert(int expression) {
  return assert(expression);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}