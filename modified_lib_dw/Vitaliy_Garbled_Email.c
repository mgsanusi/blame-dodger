#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
struct vertex
{
  int flags;
  int child[26];
};
struct vertex *ver[100000000];
char s[10000];
int r[10000][6];
int *rr;
int n;
FILE *new_fopen(const char *filename, const char *mode);
void *new_malloc(size_t size);
int new_fscanf(FILE *stream, const char *format, ...);
void new_assert(int expression);
int count(struct vertex *v, int p, int t, int dif)
{
  int first_iteration;
  if (t > 4)
  {
    t = 4;
  }

  if (v->flags)
  {
    if (r[p][t] >= dif)
    {
      r[p][t] = dif;
    }

  }

  if (p == n)
  {
    return 0;
  }

  int q = s[p] - 'a';
  int e = v->child[q];
  if (e >= 0)
  {
    count(ver[e], p + 1, t + 1, dif);
  }

  if (t == 4)
  {
    int i;
    for (i = 0; i < 26; i++)
      if (i != q)
    {
      int e = v->child[i];
      if (e >= 0)
      {
        count(ver[e], p + 1, 0, dif + 1);
      }

    }


  }

  return 0;
}

void solve(void)
{
  int first_iteration;
  new_assert(scanf("%s\n", s) == 1);
  int i;
  int j;
  n = strlen(s);
  for (i = 0; i <= 5; i++)
  {
    r[0][i] = 0;
  }

  for (i = 1; i <= n; i++)
    for (j = 0; j <= 5; j++)
    r[i][j] = n;


  for (i = 0; i < n; i++)
    for (j = 0; j <= 4; j++)
  {
    if ((j == 4) || (r[i][j] < r[i][j + 1]))
    {
      count(ver[1], i, j, r[i][j]);
    }

  }


  int best = n;
  for (i = 0; i <= 5; i++)
    if (r[n][i] < best)
  {
    best = r[n][i];
  }


  printf("%d\n", best);
}

int vn = 1;
int alloc_vertex(void)
{
  int first_iteration;
  struct vertex *v = new_malloc(sizeof(*v));
  v->flags = 0;
  int i;
  for (i = 0; i < 26; i++)
    v->child[i] = -1;

  new_assert(vn < 100000000);
  ver[vn++] = v;
  return vn - 1;
}

void add(struct vertex *v, char *s)
{
  int first_iteration;
  if (!(*s))
  {
    v->flags |= 1;
    return;
  }

  int i = (*s) - 'a';
  if (v->child[i] == (-1))
  {
    v->child[i] = alloc_vertex();
  }

  add(ver[v->child[i]], s + 1);
}

int main()
{
  int first_iteration;
  FILE *f = new_fopen("/home/vvaltman/Downloads/garbled_email_dictionary.txt", "rt");
  new_assert(alloc_vertex() == 1);
  while (fscanf(f, "%s\n", s) >= 1)
  {
    add(ver[1], s);
  }

  int _;
  new_assert(scanf("%d\n", &_) > 0);
  int __;
  for (__ = 0; __ < _; __++)
  {
    printf("Case #%d: ", __ + 1);
    solve();
  }

  return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
void *new_malloc(size_t size);
int new_fscanf(FILE *stream, const char *format, ...);
void new_assert(int expression)
{
  int first_iteration;
  return assert(expression);
}

FILE *new_fopen(const char *filename, const char *mode);
void *new_malloc(size_t size)
{
  int first_iteration;
  return malloc(size);
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}


