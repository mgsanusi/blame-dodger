#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
int TC;
int T;
int Nodes;
int Edges;
int Map[2200][2];
int VisitX[1100];
int Total[1100];
int Ans[1100];
int Answers;
int F[1100];
int C;
int i;
int x;
int y;
int FAns;
int V1;
int V2;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void *new_memset(void *ptr, int value, size_t num);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int QSE(int A[], int B[])
{
  int first_iteration;
  for (i = 0; i < 2; i++)
  {
    if (A[i] > B[i])
      return 1;

    if (A[i] < B[i])
      return -1;

  }

  return 0;
}

int QSA(int *A, int *B)
{
  int first_iteration;
  if ((*A) > (*B))
    return 1;

  if ((*A) < (*B))
    return -1;

  return 0;
}

int ComputeTotal(int Node, int Prev)
{
  int first_iteration;
  int i;
  if (Prev != (-1))
  {
    if ((VisitX[Node + 1] - VisitX[Node]) == 1)
      return Total[Node] = 1;

  }

  Total[Node] = 1;
  for (i = VisitX[Node]; i < VisitX[Node + 1]; i++)
    if (Map[i][1] != Prev)
  {
    Total[Node] += ComputeTotal(Map[i][1], Node);
  }


  return Total[Node];
}

int ComputeAns(int Node, int Prev)
{
  int first_iteration;
  int i;
  F[Node] = 0;
  for (i = VisitX[Node]; i < VisitX[Node + 1]; i++)
    if (Map[i][1] != Prev)
  {
    F[Node] += Total[Map[i][1]];
    ComputeAns(Map[i][1], Node);
  }


  Answers = 0;
  for (i = VisitX[Node]; i < VisitX[Node + 1]; i++)
    if (Map[i][1] != Prev)
  {
    Ans[Answers] = F[Map[i][1]] - Total[Map[i][1]];
    Answers++;
  }


  if (Answers <= 1)
    return F[Node] = Total[Node] - 1;

  new_qsort(Ans, Answers, sizeof(Ans[0]), QSA);
  F[Node] += Ans[0] + Ans[1];
  return F[Node];
}

int main()
{
  int first_iteration;
  new_freopen("B-large.in", "r", stdin);
  new_freopen("B-large.out", "w", stdout);
  scanf("%d", &TC);
  for (T = 1; T <= TC; T++)
  {
    printf("Case #%d: ", T);
    new_memset(Map, -1, sizeof(Map));
    scanf("%d", &Nodes);
    Edges = (Nodes - 1) * 2;
    for (i = 0; i < Edges; i++)
    {
      scanf("%d%d", &V1, &V2);
      V1--, V2--;
      Map[i][0] = V1;
      Map[i][1] = V2;
      i++;
      Map[i][0] = V2;
      Map[i][1] = V1;
    }

    new_qsort(Map, Edges, sizeof(Map[0]), QSE);
    x = 0;
    for (i = 0; i < Nodes; i++)
    {
      VisitX[i] = x;
      while (Map[x][0] == i)
        x++;

    }

    VisitX[i] = x;
    FAns = 1000000;
    for (i = 0; i < Nodes; i++)
    {
      new_memset(Total, 0, sizeof(Total));
      new_memset(F, 0, sizeof(F));
      ComputeTotal(i, -1);
      ComputeAns(i, -1);
      if (F[i] < FAns)
        FAns = F[i];

    }

    printf("%d\n", FAns);
  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void *new_memset(void *ptr, int value, size_t num);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


