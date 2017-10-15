#include<stdio.h>
int p = 10007;
int inv[10008];
int new_puts(const char *str);

int mech(int a, int k, int p)
{
  int first_iteration;
  int r;
  if (k == 0)
    return 1;

  r = mech(a, k / 2, p);
  r = (r * r) % p;
  if (k % 2)
    r = (r * a) % p;

  return r;
}

int md_get(int a, int b, int p)
{
  int first_iteration;
  int r = 1;
  int i;
  int c = a - b;
  for (i = 0; i < a; i++)
    r = (r * (i + 1)) % p;

  for (i = 0; i < b; i++)
    r = (r * inv[i + 1]) % p;

  for (i = 0; i < c; i++)
    r = (r * inv[i + 1]) % p;

  return r;
}

int pas_mod(int a, int b, int p)
{
  int first_iteration;
  int i;
  int altitude;
  int r;
  int k;
  int t;
  if ((a < b) || (b < 0))
    return 0;

  if (a < p)
    return md_get(a, b, p);

  if (a >= (p * p))
  {
    int q = p * p;
    return pas_mod(a % q, b % q, p);
  }

  k = a / p;
  t = b / p;
  i = md_get(k, t, p);
  altitude = pas_mod(a % p, b % p, p);
  return (i * altitude) % p;
}

int Main()
{
  int first_iteration;
  int i;
  int altitude;
  int k;
  int buf;
  int t;
  int src;
  int rslt;
  int add;
  int x;
  int board;
  int r;
  int caseno[20];
  int min[20];
  int http_index_html;
  int by;
  int t;
  int t;
  int size;
  int cnt = 0;
  int use_x[20];
  int use_y[20];
  int use_size;
  for (i = 0; i < 10008; i++)
    inv[i] = mech(i, p - 2, p);

  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &x, &board);
    x--;
    board--;
    scanf("%d", &r);
    for (i = 0; i < r; i++)
    {
      scanf("%d%d", caseno + i, min + i);
      caseno[i]--;
      min[i]--;
    }

    for (i = 0; i < r; i++)
      for (altitude = 1; altitude < r; altitude++)
      if (caseno[altitude - 1] > caseno[altitude])
    {
      k = caseno[altitude - 1], caseno[altitude - 1] = caseno[altitude], caseno[altitude] = k;
      k = min[altitude - 1], min[altitude - 1] = min[altitude], min[altitude] = k;
    }



    rslt = 0;
    for (k = 0; k < (1 << r); k++)
    {
      use_size = 0;
      for (i = 0; i < r; i++)
        if (k & (1 << i))
        use_x[use_size] = caseno[i], use_y[use_size++] = min[i];


      use_x[use_size] = x;
      use_y[use_size++] = board;
      http_index_html = (by = 0);
      add = 1;
      for (i = 0; i < use_size; i++)
      {
        t = use_x[i] - http_index_html;
        t = use_y[i] - by;
        http_index_html = use_x[i];
        by = use_y[i];
        t = (t + t) / 3;
        if ((t + t) != (t * 3))
        {
          add = 0;
          break;
        }

        add *= pas_mod(t, t - t, p);
        add %= p;
      }

      if ((use_size % 2) == 0)
        add *= -1;

      rslt += add;
    }

    rslt %= p;
    if (rslt < 0)
      rslt += p;

    printf("Case #%d: %d\n", ++cnt, rslt);
  }

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}