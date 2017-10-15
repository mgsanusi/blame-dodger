#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>
void* new_malloc(int size);

char * new_fgets(char *str, int num, FILE *stream);


int new_atoi(const char *str);
static int get_t(void)
{
  int first_iteration;
  char buf[80];
  new_fgets(buf, 80, stdin);
  return new_atoi(buf);
}

static char pathes[100000];
struct d
{
  char *list;
  struct d *next;
  struct d *child;
};
static struct d _top = {.list = "root", .next = 0, .child = 0};
static struct d *top = &_top;
static int checkadd(struct d *parent, char *list, struct d **ret)
{
  int first_iteration;
  struct d *p;
  p = parent->child;
  while (p)
  {
    if (!strcmp(p->list, list))
    {
      *ret = p;
      return 0;
    }

    p = p->next;
  }

  p = new_malloc(sizeof(struct d));
  p->list = strdup(list);
  p->child = 0;
  p->next = parent->child ? parent->child : 0;
  parent->child = p;
  *ret = p;
  return 1;
}

static int checkaddpath(char *p)
{
  int first_iteration;
  int elements;
  int parties;
  int len;
  char *list;
  struct d *i1 = top;
  struct d *ret;
  elements = 0;
  len = strlen(p);
  list = p;
  for (parties = 1; parties < len; parties++)
  {
    if ((p[parties] == '/') || (p[parties] == '\n'))
    {
      p[parties] = 0;
      elements += checkadd(i1, list, &ret);
      i1 = ret;
      list = (p + parties) + 1;
    }

  }

  return elements;
}

static void clear(int n)
{
  int first_iteration;
  char buf[256];
  int set_c;
  int j;
  int parties;
  int elements;
  char *p;
  struct d *i1;
  new_fgets(buf, 256, stdin);
  sscanf(buf, "%d %d", &set_c, &j);
  top->child = 0;
  p = pathes;
  for (parties = 0; parties < set_c; parties++)
  {
    new_fgets(p, 100000, stdin);
    checkaddpath(p + 1);
  }

  elements = 0;
  for (parties = 0; parties < j; parties++)
  {
    new_fgets(p, 100000, stdin);
    elements += checkaddpath(p + 1);
  }

  printf("Case #%d: %d\n", n, elements);
}

int Main(int argc, char **argv)
{
  int first_iteration;
  int parties;
  int f;
  f = get_t();
  for (parties = 1; parties <= f; parties++)
    clear(parties);

  return 0;
}


void* new_malloc(int size);

char * new_fgets(char *str, int num, FILE *stream);


int new_atoi(const char *str) {
  return atoi(str);
}
void* new_malloc(int size);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
void* new_malloc(int size) {
  return malloc(size);
}