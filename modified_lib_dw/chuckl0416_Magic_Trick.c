#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int TC;
int T;
int Row;
int Map[10][10];
int Ans[20];
int i;
int x;
int y;
int FAns;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_puts(const char *str);
int Check()
{
  int first_iteration;
  FAns = 0;
  for (i = 1; i <= 16; i++)
  {
    if (Ans[i] == 2)
    {
      if (FAns)
        return 0;

      FAns = i;
    }

  }

  return 1;
}

int main()
{
  int first_iteration;
  new_freopen("A-small-attempt0.in", "r", stdin);
  new_freopen("A-small-attempt0.out", "w", stdout);
  scanf("%d", &TC);
  for (T = 1; T <= TC; T++)
  {
    printf("Case #%d: ", T);
    memset(Ans, 0, sizeof(Ans));
    for (i = 0; i < 2; i++)
    {
      scanf("%d", &Row);
      for (y = 1; y <= 4; y++)
        for (x = 0; x < 4; x++)
        scanf("%d", &Map[y][x]);


      for (x = 0; x < 4; x++)
        Ans[Map[Row][x]]++;

    }

    if (!Check())
      new_puts("Bad magician!");
    else
    {
      if (FAns)
        printf("%d\n", FAns);
      else
        new_puts("Volunteer cheated!");

    }

  }

  return 0;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


