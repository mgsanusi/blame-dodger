#include<stdio.h>
#include<string.h>
#include<math.h>

#include <stddef.h>
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
void * new_memset(void *ptr, int value, int num);


int new_getchar();

int getInt()
{
  int first_iteration;
  char c;
  while (c = new_getchar(), (c < '0') || (c > '9'))
  {
  }

  int res = 0;
  while ((c >= '0') && (c <= '9'))
  {
    res = ((res * 10) + c) - '0';
    c = new_getchar();
  }

  return res;
}

int getF(int p, int ca)
{
  int first_iteration;
  return (p / (ca + 1)) + ((p % (ca + 1)) > 0 ? 1 : 0);
}

int haveMax(int size, int b1)
{
  int first_iteration;
  if (size > b1)
    return size;
  else
    return b1;

}

int Main()
{
  int first_iteration;
  new_freopen("B.in", "r", stdin);
  new_freopen("B.out", "w", stdout);
  int tnum;
  int ca;
  int r;
  int t;
  int t;
  int rd;
  int p[1000];
  int p;
  int ans;
  int min;
  int max;
  int v[1000];
  int httpCss[1000];
  t = getInt();
  for (t = 1; t <= t; t++)
  {
    rd = getInt();
    for (tnum = 0; tnum < rd; tnum++)
    {
      p = getInt();
      r = tnum;
      for (ca = 0; ca < tnum; ca++)
      {
        if (p <= p[ca])
        {
          r = ca;
          break;
        }

      }

      for (ca = tnum; ca > r; ca--)
      {
        p[ca] = p[ca - 1];
      }

      p[r] = p;
    }

    new_memset(v, -1, sizeof(v));
    new_memset(httpCss, -1, sizeof(httpCss));
    for (tnum = 0; tnum < rd; tnum++)
    {
      for (ca = 0; ca < rd; ca++)
      {
        v[ca] = httpCss[ca];
      }

      new_memset(httpCss, -1, sizeof(httpCss));
      httpCss[0] = p[tnum];
      for (ca = 1; ca < p[tnum]; ca++)
      {
        max = haveMax(v[0], getF(p[tnum], ca));
        min = max;
        for (r = 0; r < ca; r++)
        {
          max = haveMax(v[ca - r], getF(p[tnum], r));
          if (min > max)
            min = max;

        }

        httpCss[ca] = min;
      }

    }

    ans = p[rd - 1];
    for (tnum = 1; tnum <= p[rd - 1]; tnum++)
    {
      if ((httpCss[tnum] > 0) && (ans > (httpCss[tnum] + tnum)))
      {
        ans = httpCss[tnum] + tnum;
      }

    }

    printf("Case #%d: %d\n", t, ans);
  }

}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
void * new_memset(void *ptr, int value, int num);


int new_getchar() {
  return getchar();
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}