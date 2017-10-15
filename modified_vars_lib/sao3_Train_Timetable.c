#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ansa;
int ansb;
typedef struct 
{
  int dep;
  int array;
  int sta;
} time;
time train[201];
int h[201];
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

void readtime(int *s)
{
  char pr;
  *s = 0;
  scanf("%c", &pr);
  *s += (pr - '0') * 600;
  scanf("%c", &pr);
  *s += (pr - '0') * 60;
  scanf("%c", &pr);
  scanf("%c", &pr);
  *s += (pr - '0') * 10;
  scanf("%c", &pr);
  *s += pr - '0';
  scanf("%c", &pr);
}

int cmp(const void *s, const void *p)
{
  return ((const time *) s)->dep - ((const time *) p)->dep;
}

void tn()
{
  int tn;
  int score;
  int t;
  int tmp;
  int n;
  char pr;
  ansa = (ansb = 0);
  scanf("%d%d%d%c", &t, &tmp, &n, &pr);
  for (tn = 0; tn < (tmp + n); tn++)
  {
    readtime(&train[tn].dep);
    readtime(&train[tn].array);
    train[tn].array += t;
    train[tn].sta = tn < tmp ? 0 : 1;
  }

  memset(h, 0, sizeof(h));
  new_qsort(train, tmp + n, sizeof(time), cmp);
  for (tn = 0; tn < (tmp + n); tn++)
  {
    if (h[tn] == 0)
    {
      if (train[tn].sta == 0)
        ansa++;
      else
        ansb++;

    }

    for (score = 0; (score < (tmp + n)) && (((train[tn].array > train[score].dep) || (train[tn].sta == train[score].sta)) || (h[score] == 1)); score++)
      ;

    h[score] = 1;
  }

}

int Main()
{
  int tn;
  int h;
  new_freopen("B.in", "r", stdin);
  new_freopen("B.out", "w", stdout);
  scanf("%d", &h);
  for (tn = 1; tn <= h; tn++)
  {
    tn();
    printf("Case #%d: %d %d\n", tn, ansa, ansb);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}