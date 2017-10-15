#include <stdio.h>
int n;
int c;
int dp[10002];
int ans[10002];
int val[10002];
int din[3][10002];
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int min(int a, int y)
{
  return a < y ? a : y;
}

int clear(int v, int nodo)
{
  int result = 1 << 22;
  int carry;
  int temps = nodo;
  if (nodo > c)
    return val[nodo] == v ? 0 : 1 << 22;

  if (din[v][nodo] != (-1))
    return din[v][nodo];

  if (ans[nodo] == 1)
  {
    if (dp[nodo] == 1)
      carry = 0;
    else
      carry = 1;

    if (v == 0)
    {
      result = min((clear(0, temps * 2) + clear(1, (temps * 2) + 1)) + carry, result);
      result = min((clear(1, temps * 2) + clear(0, (temps * 2) + 1)) + carry, result);
      result = min((clear(0, temps * 2) + clear(0, (temps * 2) + 1)) + carry, result);
    }

    if (v == 1)
    {
      result = min((clear(1, temps * 2) + clear(1, (temps * 2) + 1)) + carry, result);
    }

    if (dp[nodo] == 0)
      carry = 0;
    else
      carry = 1;

    if (v == 0)
    {
      result = min((clear(0, temps * 2) + clear(0, (temps * 2) + 1)) + carry, result);
    }

    if (v == 1)
    {
      result = min((clear(0, temps * 2) + clear(1, (temps * 2) + 1)) + carry, result);
      result = min((clear(1, temps * 2) + clear(0, (temps * 2) + 1)) + carry, result);
      result = min((clear(1, temps * 2) + clear(1, (temps * 2) + 1)) + carry, result);
    }

  }
  else
  {
    if (dp[nodo] == 1)
    {
      if (v == 0)
      {
        result = min(clear(0, temps * 2) + clear(1, (temps * 2) + 1), result);
        result = min(clear(1, temps * 2) + clear(0, (temps * 2) + 1), result);
        result = min(clear(0, temps * 2) + clear(0, (temps * 2) + 1), result);
      }

      if (v == 1)
      {
        result = min(clear(1, temps * 2) + clear(1, (temps * 2) + 1), result);
      }

    }

    if (dp[nodo] == 0)
    {
      if (v == 0)
      {
        result = min(clear(0, temps * 2) + clear(0, (temps * 2) + 1), result);
      }

      if (v == 1)
      {
        result = min(clear(0, temps * 2) + clear(1, (temps * 2) + 1), result);
        result = min(clear(1, temps * 2) + clear(0, (temps * 2) + 1), result);
        result = min(clear(1, temps * 2) + clear(1, (temps * 2) + 1), result);
      }

    }

  }

  return din[v][nodo] = result;
}

int Main()
{
  int casos;
  int r;
  int f;
  int pos;
  int set;
  int v;
  new_freopen("a.in", "r", stdin);
  new_freopen("a.out", "w", stdout);
  for (scanf("%d", &casos), set = 1; set <= casos; set++)
  {
    scanf("%d %d", &n, &v);
    c = (n - 1) / 2;
    for (pos = 1, f = 0; f < c; f++, pos++)
    {
      scanf("%d %d", &dp[pos], &ans[pos]);
    }

    for (f = 0; pos <= n; f++, pos++)
    {
      scanf("%d", &val[pos]);
    }

    memset(din, -1, sizeof(din));
    r = clear(v, 1);
    printf("Case #%d: ", set);
    if (r == (1 << 22))
      printf("IMPOSSIBLE\n");
    else
      printf("%d\n", r);

  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
