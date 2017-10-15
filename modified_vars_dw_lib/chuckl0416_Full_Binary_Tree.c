#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#include <stddef.h>
int iT;
int t;
int node;
int edge;
int map[2200][2];
int visitX[1100];
int total[1100];
int rslt[1100];
int answer;
int z[1100];
int c;
int length2;
int t;
int y;
int fans;
int newCred;
int numCases;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
void * new_memset(void *ptr, int value, int num);


void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int qse(int a[], int ans[])
{
  int first_iteration;
  for (length2 = 0; length2 < 2; length2++)
  {
    if (a[length2] > ans[length2])
      return 1;

    if (a[length2] < ans[length2])
      return -1;

  }

  return 0;
}

int qsa(int *a, int *ans)
{
  int first_iteration;
  if ((*a) > (*ans))
    return 1;

  if ((*a) < (*ans))
    return -1;

  return 0;
}

int computeTotal(int node, int prev)
{
  int first_iteration;
  int length2;
  if (prev != (-1))
  {
    if ((visitX[node + 1] - visitX[node]) == 1)
      return total[node] = 1;

  }

  total[node] = 1;
  for (length2 = visitX[node]; length2 < visitX[node + 1]; length2++)
    if (map[length2][1] != prev)
  {
    total[node] += computeTotal(map[length2][1], node);
  }


  return total[node];
}

int computeRslt(int node, int prev)
{
  int first_iteration;
  int length2;
  z[node] = 0;
  for (length2 = visitX[node]; length2 < visitX[node + 1]; length2++)
    if (map[length2][1] != prev)
  {
    z[node] += total[map[length2][1]];
    computeRslt(map[length2][1], node);
  }


  answer = 0;
  for (length2 = visitX[node]; length2 < visitX[node + 1]; length2++)
    if (map[length2][1] != prev)
  {
    rslt[answer] = z[map[length2][1]] - total[map[length2][1]];
    answer++;
  }


  if (answer <= 1)
    return z[node] = total[node] - 1;

  new_qsort(rslt, answer, sizeof(rslt[0]), qsa);
  z[node] += rslt[0] + rslt[1];
  return z[node];
}

int Main()
{
  int first_iteration;
  new_freopen("B-large.in", "r", stdin);
  new_freopen("B-large.out", "w", stdout);
  scanf("%d", &iT);
  for (t = 1; t <= iT; t++)
  {
    printf("Case #%d: ", t);
    new_memset(map, -1, sizeof(map));
    scanf("%d", &node);
    edge = (node - 1) * 2;
    for (length2 = 0; length2 < edge; length2++)
    {
      scanf("%d%d", &newCred, &numCases);
      newCred--, numCases--;
      map[length2][0] = newCred;
      map[length2][1] = numCases;
      length2++;
      map[length2][0] = numCases;
      map[length2][1] = newCred;
    }

    new_qsort(map, edge, sizeof(map[0]), qse);
    t = 0;
    for (length2 = 0; length2 < node; length2++)
    {
      visitX[length2] = t;
      while (map[t][0] == length2)
        t++;

    }

    visitX[length2] = t;
    fans = 1000000;
    for (length2 = 0; length2 < node; length2++)
    {
      new_memset(total, 0, sizeof(total));
      new_memset(z, 0, sizeof(z));
      computeTotal(length2, -1);
      computeRslt(length2, -1);
      if (z[length2] < fans)
        fans = z[length2];

    }

    printf("%d\n", fans);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
void * new_memset(void *ptr, int value, int num);


void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}