#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int sgn;
int c;
int row;
int columns;
char map[120][120];
int l;
int e;
int tn;
int len2;
int ans;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str);

int checkRes()
{
  int first_iteration;
  for (len2 = 0; len2 < row; len2++)
    for (tn = 0; tn < columns; tn++)
    if (map[len2][tn] != '.')
  {
    if (map[len2][tn] == '<')
    {
      for (l = tn - 1; l >= 0; l--)
        if (map[len2][l] != '.')
        break;


      if (l >= 0)
        continue;

      int try = 0;
      for (l = tn + 1; l < columns; l++)
        if (map[len2][l] != '.')
        try = 1;


      for (e = len2 - 1; e >= 0; e--)
        if (map[e][tn] != '.')
        try = 1;


      for (e = len2 + 1; e < row; e++)
        if (map[e][tn] != '.')
        try = 1;


      if (try)
      {
        ans++;
        continue;
      }

      return 0;
    }

    if (map[len2][tn] == '>')
    {
      for (l = tn + 1; l < columns; l++)
        if (map[len2][l] != '.')
        break;


      if (l < columns)
        continue;

      int try = 0;
      for (l = tn - 1; l >= 0; l--)
        if (map[len2][l] != '.')
        try = 1;


      for (e = len2 - 1; e >= 0; e--)
        if (map[e][tn] != '.')
        try = 1;


      for (e = len2 + 1; e < row; e++)
        if (map[e][tn] != '.')
        try = 1;


      if (try)
      {
        ans++;
        continue;
      }

      return 0;
    }

    if (map[len2][tn] == '^')
    {
      for (e = len2 - 1; e >= 0; e--)
        if (map[e][tn] != '.')
        break;


      if (e >= 0)
        continue;

      int try = 0;
      for (e = len2 + 1; e < row; e++)
        if (map[e][tn] != '.')
        try = 1;


      for (l = tn - 1; l >= 0; l--)
        if (map[len2][l] != '.')
        try = 1;


      for (l = tn + 1; l < columns; l++)
        if (map[len2][l] != '.')
        try = 1;


      if (try)
      {
        ans++;
        continue;
      }

      return 0;
    }

    if (map[len2][tn] == 'v')
    {
      for (e = len2 + 1; e < row; e++)
        if (map[e][tn] != '.')
        break;


      if (e < row)
        continue;

      int try = 0;
      for (e = len2 - 1; e >= 0; e--)
        if (map[e][tn] != '.')
        try = 1;


      for (l = tn - 1; l >= 0; l--)
        if (map[len2][l] != '.')
        try = 1;


      for (l = tn + 1; l < columns; l++)
        if (map[len2][l] != '.')
        try = 1;


      if (try)
      {
        ans++;
        continue;
      }

      return 0;
    }

  }



  return 1;
}

int Main()
{
  int first_iteration;
  new_freopen("A-small-attempt0.in", "r", stdin);
  new_freopen("A-small-attempt0.out", "w", stdout);
  scanf("%d", &sgn);
  for (c = 1; c <= sgn; c++)
  {
    printf("Case #%d: ", c);
    scanf("%d%d", &row, &columns);
    for (e = 0; e < row; e++)
      scanf("%s", map[e]);

    ans = 0;
    if (!checkRes())
    {
      new_puts("IMPOSSIBLE");
      continue;
    }

    printf("%d\n", ans);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str) {
  return puts(str);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}