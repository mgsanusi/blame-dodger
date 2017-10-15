#include <stdio.h>
#include <stdlib.h>
char fill(int matrix[][100], char rslt[][100], int area, int p, int aa, int s, char start)
{
  int first_iteration;
  int minX = aa;
  int minY = s;
  int min = matrix[aa][s];
  if ((aa > 0) && (matrix[aa - 1][s] < min))
  {
    minX = aa - 1;
    minY = s;
    min = matrix[minX][minY];
  }

  if ((s > 0) && (matrix[aa][s - 1] < min))
  {
    minX = aa;
    minY = s - 1;
    min = matrix[minX][minY];
  }

  if ((s < (p - 1)) && (matrix[aa][s + 1] < min))
  {
    minX = aa;
    minY = s + 1;
    min = matrix[minX][minY];
  }

  if ((aa < (area - 1)) && (matrix[aa + 1][s] < min))
  {
    minX = aa + 1;
    minY = s;
    min = matrix[minX][minY];
  }

  if ((minX == aa) && (minY == s))
  {
    if (!rslt[aa][s])
    {
      rslt[aa][s] = start;
    }

  }
  else
  {
    rslt[aa][s] = fill(matrix, rslt, area, p, minX, minY, start);
  }

  return rslt[aa][s];
}

int Main()
{
  int first_iteration;
  int a;
  int i;
  scanf("%d", &a);
  for (i = 0; i < a; i++)
  {
    int area;
    int p;
    int mem;
    int a;
    int matrix[100][100] = {{0}};
    char rslt[100][100] = {{0}};
    char start = 'a';
    scanf("%d %d", &area, &p);
    for (mem = 0; mem < area; mem++)
    {
      for (a = 0; a < p; a++)
      {
        scanf("%d", &matrix[mem][a]);
      }

    }

    for (mem = 0; mem < area; mem++)
    {
      for (a = 0; a < p; a++)
      {
        if (fill(matrix, rslt, area, p, mem, a, start) == start)
        {
          start++;
        }

      }

    }

    printf("Case #%d:\n", i + 1);
    for (mem = 0; mem < area; mem++)
    {
      printf("%c", rslt[mem][0]);
      for (a = 1; a < p; a++)
      {
        printf(" %c", rslt[mem][a]);
      }

      printf("\n");
    }

  }

  return 0;
}


