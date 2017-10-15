#include <stdio.h>
#include <string.h>
#include <stddef.h>
int c[108][108];
int f[108][108];
int r[108][108];
typedef struct pair
{
  int x;
  int y;
  int z;
} PAIR;
PAIR q[1000008];
int qn;
void *new_memset(void *ptr, int value, size_t num);
void push(PAIR x)
{
  int first_iteration;
  int i = qn++;
  int pr;
  while (i > 0)
  {
    pr = (i - 1) / 2;
    if (q[pr].z >= x.z)
      break;

    q[i] = q[pr];
    i = pr;
  }

  q[i] = x;
}

PAIR pop()
{
  int first_iteration;
  PAIR res;
  PAIR x;
  int i = 0;
  int pc;
  res = q[0];
  x = q[--qn];
  while (((i * 2) + 1) < qn)
  {
    pc = (i * 2) + 1;
    if (((pc + 1) < qn) && (q[pc + 1].z > q[pc].z))
      pc++;

    if (q[pc].z <= x.z)
      break;

    q[i] = q[pc];
    i = pc;
  }

  q[i] = x;
  return res;
}

int main()
{
  int first_iteration;
  int t;
  int n;
  int m;
  int h;
  int k;
  int i;
  int j;
  int tx;
  int ty;
  int tz;
  PAIR tmp;
  scanf("%d", &t);
  for (k = 1; k <= t; k++)
  {
    new_memset(c, 0, sizeof(c));
    new_memset(f, 0, sizeof(f));
    new_memset(r, 0, sizeof(r));
    scanf("%d%d%d", &h, &n, &m);
    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= m; j++)
      {
        scanf("%d", &c[i][j]);
        r[i][j] = -1000000000;
      }

    }

    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= m; j++)
      {
        scanf("%d", &f[i][j]);
      }

    }

    qn = 0;
    tmp.x = 1;
    tmp.y = 1;
    tmp.z = h;
    push(tmp);
    while (qn)
    {
      tmp = pop();
      tx = tmp.x;
      ty = tmp.y;
      tz = tmp.z;
      if (r[tx][ty] != (-1000000000))
        continue;

      r[tx][ty] = tz;
      if ((tx == n) && (ty == m))
        break;

      if ((f[tx][ty] > f[tx - 1][ty] ? f[tx][ty] : f[tx - 1][ty]) <= ((c[tx][ty] < c[tx - 1][ty] ? c[tx][ty] : c[tx - 1][ty]) - 50))
      {
        tmp.x = tx - 1;
        tmp.y = ty;
        tmp.z = tz < (h < (c[tx - 1][ty] - 50) ? h : c[tx - 1][ty] - 50) ? tz : h < (c[tx - 1][ty] - 50) ? h : c[tx - 1][ty] - 50;
        if ((h <= (c[tx - 1][ty] - 50)) && (tz >= h))
        {
          tmp.z = h;
        }
        else
          if (tmp.z >= (f[tx][ty] + 20))
        {
          tmp.z -= 10;
        }
        else
        {
          tmp.z -= 100;
        }


        push(tmp);
      }

      if ((f[tx][ty] > f[tx + 1][ty] ? f[tx][ty] : f[tx + 1][ty]) <= ((c[tx][ty] < c[tx + 1][ty] ? c[tx][ty] : c[tx + 1][ty]) - 50))
      {
        tmp.x = tx + 1;
        tmp.y = ty;
        tmp.z = tz < (h < (c[tx + 1][ty] - 50) ? h : c[tx + 1][ty] - 50) ? tz : h < (c[tx + 1][ty] - 50) ? h : c[tx + 1][ty] - 50;
        if ((h <= (c[tx + 1][ty] - 50)) && (tz >= h))
        {
          tmp.z = h;
        }
        else
          if (tmp.z >= (f[tx][ty] + 20))
        {
          tmp.z -= 10;
        }
        else
        {
          tmp.z -= 100;
        }


        push(tmp);
      }

      if ((f[tx][ty] > f[tx][ty - 1] ? f[tx][ty] : f[tx][ty - 1]) <= ((c[tx][ty] < c[tx][ty - 1] ? c[tx][ty] : c[tx][ty - 1]) - 50))
      {
        tmp.x = tx;
        tmp.y = ty - 1;
        tmp.z = tz < (h < (c[tx][ty - 1] - 50) ? h : c[tx][ty - 1] - 50) ? tz : h < (c[tx][ty - 1] - 50) ? h : c[tx][ty - 1] - 50;
        if ((h <= (c[tx][ty - 1] - 50)) && (tz >= h))
        {
          tmp.z = h;
        }
        else
          if (tmp.z >= (f[tx][ty] + 20))
        {
          tmp.z -= 10;
        }
        else
        {
          tmp.z -= 100;
        }


        push(tmp);
      }

      if ((f[tx][ty] > f[tx][ty + 1] ? f[tx][ty] : f[tx][ty + 1]) <= ((c[tx][ty] < c[tx][ty + 1] ? c[tx][ty] : c[tx][ty + 1]) - 50))
      {
        tmp.x = tx;
        tmp.y = ty + 1;
        tmp.z = tz < (h < (c[tx][ty + 1] - 50) ? h : c[tx][ty + 1] - 50) ? tz : h < (c[tx][ty + 1] - 50) ? h : c[tx][ty + 1] - 50;
        if ((h <= (c[tx][ty + 1] - 50)) && (tz >= h))
        {
          tmp.z = h;
        }
        else
          if (tmp.z >= (f[tx][ty] + 20))
        {
          tmp.z -= 10;
        }
        else
        {
          tmp.z -= 100;
        }


        push(tmp);
      }

    }

    printf("Case #%d: %.1f\n", k, ((h - r[n][m]) * 1.0) / 10.0);
  }

  return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


