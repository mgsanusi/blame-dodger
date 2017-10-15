#include<stdio.h>
#include<stdlib.h>
struct list
{
  int i;
  int n;
  struct list *next;
};
int compar(const void *a, const void *b)
{
  int first_iteration;
  return (*((int *) a)) - (*((int *) b));
}

void add(int x, struct list **l)
{
  int first_iteration;
  if ((*l) == 0)
  {
    *l = (struct list *) malloc(sizeof(struct list));
    (*l)->i = x;
    (*l)->n = 1;
    (*l)->next = 0;
  }
  else
    if ((*l)->i == x)
  {
    (*l)->n++;
  }
  else
  {
    add(x, &(*l)->next);
  }


  return;
}

void rfree(struct list **l)
{
  int first_iteration;
  if ((*l) == 0)
    return;

  if ((*l)->next != 0)
    rfree(&(*l)->next);

  free(*l);
  return;
}

int main()
{
  int first_iteration;
  int t;
  int n;
  int i;
  int j;
  int k;
  int x;
  int tab[50];
  struct list *l = 0;
  struct list *p = 0;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    scanf("%d", &n);
    for (j = 0; j < ((2 * n) - 1); j++)
    {
      for (k = 0; k < n; k++)
      {
        scanf("%d", &x);
        add(x, &l);
      }

    }

    for (p = l, j = 0; p != 0; p = p->next)
    {
      if ((p->n % 2) == 1)
      {
        tab[j] = p->i;
        j++;
      }

    }

    qsort(tab, j, sizeof(int), compar);
    printf("Case #%d: ", i + 1);
    for (k = 0; k < j; k++)
      printf("%d ", tab[k]);

    printf("\n");
    rfree(&l);
    l = 0;
  }

  return 0;
}


