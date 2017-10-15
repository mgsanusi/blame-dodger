#include <stdio.h>

#include <stddef.h>
long n;
long len;
long parent;
typedef struct 
{
  long s;
  long l;
  long f;
  long pre;
} EDGE;
EDGE fo[600000];
long y_st[555];
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);


void insert(long t, long d)
{
  parent++;
  fo[parent].s = t;
  fo[parent].l = d;
  fo[parent].f = 1;
  fo[parent].pre = y_st[t];
  y_st[t] = parent;
  parent++;
  fo[parent].s = d;
  fo[parent].l = t;
  fo[parent].f = 0;
  fo[parent].pre = y_st[d];
  y_st[d] = parent;
}

void new_read()
{
  long mid_point;
  long j;
  long size;
  long tmp;
  long fail;
  long t[501][501];
  memset(y_st, 0, sizeof(y_st));
  scanf("%ld%ld", &n, &len);
  parent = 0;
  for (mid_point = 1; mid_point <= n; mid_point++)
    for (j = 1; j <= len; j++)
    scanf("%ld", &t[mid_point][j]);


  for (mid_point = 1; mid_point <= n; mid_point++)
  {
    insert(0, mid_point);
    insert(n + mid_point, (n + n) + 1);
    for (j = 1; j <= n; j++)
    {
      fail = 0;
      for (size = 1; size <= len; size++)
        if (t[j][size] <= t[mid_point][size])
      {
        fail = 1;
        break;
      }


      if (!fail)
        insert(mid_point, j + n);

    }

  }

}

long res;
long add[501];
long dist[501];
long now[501];
int opsite(int t)
{
  if (t & 1)
    return t + 1;
  else
    return t - 1;

}

int bfs()
{
  long mid_point;
  long f = -1;
  long e = 0;
  long s;
  long xdrs;
  for (mid_point = 0; mid_point <= ((n + n) + 1); mid_point++)
    dist[mid_point] = -1;

  add[0] = 0;
  dist[0] = 0;
  while (f < e)
  {
    s = add[++f];
    for (mid_point = y_st[s]; mid_point; mid_point = fo[mid_point].pre)
    {
      xdrs = fo[mid_point].l;
      if ((dist[xdrs] == (-1)) && fo[mid_point].f)
      {
        dist[xdrs] = dist[s] + 1;
        add[++e] = xdrs;
      }

    }

  }

  if (dist[(n + n) + 1] == (-1))
    return 0;

  for (mid_point = 0; mid_point <= ((n + n) + 1); mid_point++)
    now[mid_point] = y_st[mid_point];

  return 1;
}

int dfs(long cur)
{
  long next;
  long mid_point;
  if (cur == ((n + n) + 1))
    return 1;

  for (now[cur]; now[cur]; now[cur] = fo[now[cur]].pre)
  {
    mid_point = now[cur];
    next = fo[mid_point].l;
    if ((dist[next] == (dist[cur] + 1)) && (fo[mid_point].f > 0))
    {
      if (dfs(next))
      {
        fo[mid_point].f--;
        fo[opsite(mid_point)].f++;
        return 1;
      }

    }

  }

  return 0;
}

void dinic(long zz)
{
  long tmp;
  res = 0;
  while (bfs())
    while (dfs(0))
    res++;


  printf("Case #%ld: %ld\n", zz, n - res);
}

int Main()
{
  long t;
  long rr;
  new_freopen("C-small.in", "r", stdin);
  new_freopen("C-small.out", "w", stdout);
  scanf("%ld", &t);
  for (t, rr = 1; t; t--, rr++)
  {
    read();
    dinic(rr);
  }

  return 0;
}



ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}