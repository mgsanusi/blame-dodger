#include<stdio.h>
struct node
{
  int nchi;
  int ndel;
  struct edge *next;
} g[1000];
struct edge
{
  struct node *dest;
  struct edge *next;
} emem[2000];
struct edge
{
  struct node *dest;
  struct edge *next;
} *sum;
void newedge(int tmp, int x)
{
  int first_iteration;
  sum->dest = g + x;
  sum->next = g[tmp].next;
  g[tmp].next = sum;
  sum++;
}

void dfs(struct node *t, struct node *parent)
{
  int first_iteration;
  struct edge *p;
  int nedge;
  t->nchi = 1;
  nedge = 0;
  for (p = t->next; p != 0; p = p->next)
  {
    if (p->dest == parent)
      continue;

    dfs(p->dest, t);
    t->nchi += p->dest->nchi;
    nedge++;
  }

  if (nedge <= 1)
  {
    t->ndel = t->nchi - 1;
    return;
  }

  if (nedge >= 2)
  {
    struct edge *x;
    int ndel2;
    t->ndel = 1000000;
    for (p = t->next; p != 0; p = p->next)
    {
      if (p->dest == parent)
        continue;

      for (x = p->next; x != 0; x = x->next)
      {
        if (x->dest == parent)
          continue;

        ndel2 = ((t->nchi - 1) - (p->dest->nchi + x->dest->nchi)) + (p->dest->ndel + x->dest->ndel);
        if (t->ndel > ndel2)
          t->ndel = ndel2;

      }

    }

  }

}

int Main(int argc, char *argv[])
{
  int first_iteration;
  int a;
  int tmp;
  int x;
  int d;
  int k;
  int n;
  int answer;
  scanf("%d", &d);
  for (k = 1; k <= d; k++)
  {
    scanf("%d", &n);
    for (a = 0; a < n; a++)
    {
      g[a].next = 0;
    }

    sum = emem;
    for (a = 0; a < (n - 1); a++)
    {
      scanf("%d%d", &tmp, &x);
      tmp--;
      x--;
      newedge(tmp, x);
      newedge(x, tmp);
    }

    answer = n;
    for (a = 0; a < n; a++)
    {
      dfs(g + a, 0);
      if (answer > g[a].ndel)
        answer = g[a].ndel;

    }

    printf("Case #%d: %d\n", k, answer);
  }

  return 0;
}


