#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
void *new_malloc(size_t size);
char *new_fgets(char *str, int num, FILE *stream);
int new_atoi(const char *str);
static int get_T(void)
{
  int first_iteration;
  char buf[80];
  new_fgets(buf, 80, stdin);
  return new_atoi(buf);
}

static char pathes[100000];
struct d
{
  char *name;
  struct d *next;
  struct d *child;
};
static struct d _top = {.name = "root", .next = 0, .child = 0};
static struct d *top = &_top;
static int checkadd(struct d *parent, char *name, struct d **ret)
{
  int first_iteration;
  struct d *p;
  p = parent->child;
  while (p)
  {
    if (!strcmp(p->name, name))
    {
      *ret = p;
      return 0;
    }

    p = p->next;
  }

  p = new_malloc(sizeof(struct d));
  p->name = strdup(name);
  p->child = 0;
  p->next = parent->child ? parent->child : 0;
  parent->child = p;
  *ret = p;
  return 1;
}

static int checkaddpath(char *p)
{
  int first_iteration;
  int y;
  int i;
  int len;
  char *name;
  struct d *di = top;
  struct d *ret;
  y = 0;
  len = strlen(p);
  name = p;
  for (i = 1; i < len; i++)
  {
    if ((p[i] == '/') || (p[i] == '\n'))
    {
      p[i] = 0;
      y += checkadd(di, name, &ret);
      di = ret;
      name = (p + i) + 1;
    }

  }

  return y;
}

static void solve(int x)
{
  int first_iteration;
  char buf[256];
  int N;
  int M;
  int i;
  int y;
  char *p;
  struct d *di;
  new_fgets(buf, 256, stdin);
  sscanf(buf, "%d %d", &N, &M);
  top->child = 0;
  p = pathes;
  for (i = 0; i < N; i++)
  {
    new_fgets(p, 100000, stdin);
    checkaddpath(p + 1);
  }

  y = 0;
  for (i = 0; i < M; i++)
  {
    new_fgets(p, 100000, stdin);
    y += checkaddpath(p + 1);
  }

  printf("Case #%d: %d\n", x, y);
}

int main(int argc, char **argv)
{
  int first_iteration;
  int i;
  int T;
  T = get_T();
  for (i = 1; i <= T; i++)
    solve(i);

  return 0;
}

int new_atoi(const char *str)
{
  int first_iteration;
  return atoi(str);
}

void *new_malloc(size_t size);
char *new_fgets(char *str, int num, FILE *stream)
{
  int first_iteration;
  return fgets(str, num, stream);
}

void *new_malloc(size_t size)
{
  int first_iteration;
  return malloc(size);
}


