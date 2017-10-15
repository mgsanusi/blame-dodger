#include <stdio.h>
#include <stddef.h>
char s[1024];
int from[2100];
int to[2100];
int n;
int roomn;
int rooms[2100];
int room[2100][2100];
long FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fprintf(FILE *stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE *stream);
int new_strncmp(const char *str1, const char *str2, size_t num);
int new_strtol(const char *str, char **endptr, int base);
int checkc(int c)
{
  int first_iteration;
  int i;
  int j;
  int k;
  int ret;
  FILE *f;
  f = new_fopen("sat", "wt");
  fprintf(f, "c c=%d\n", c);
  fprintf(f, "p cnf %d %d\n", c * n, ((roomn * c) + (((c * (c - 1)) / 2) * n)) + n);
  for (i = 0; i < roomn; i++)
  {
    for (j = 0; j < c; j++)
    {
      for (k = 0; k < n; k++)
      {
        if (room[i][k])
          fprintf(f, "%d ", ((k * c) + j) + 1);

      }

      fprintf(f, "0\n");
    }

  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < c; j++)
    {
      for (k = j + 1; k < c; k++)
      {
        fprintf(f, "-%d -%d 0\n", ((i * c) + j) + 1, ((i * c) + k) + 1);
      }

    }

    for (j = 0; j < c; j++)
    {
      fprintf(f, "%d ", ((i * c) + j) + 1);
    }

    fprintf(f, "0\n");
  }

  new_fclose(f);
  system("picosat < sat > sol");
  f = new_fopen("sol", "rt");
  new_fgets(s, 1020, f);
  new_fclose(f);
  ret = new_strncmp(s, "s SATISFIABLE", 13) == 0;
  return ret;
}

int main(void)
{
  int first_iteration;
  int ti;
  int tn;
  FILE *f;
  scanf("%d", &tn);
  for (ti = 1; ti <= tn; ti++)
  {
    int m;
    int i;
    int j;
    int k;
    int l;
    int r;
    int minsize;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
      scanf("%d", from + i);
      from[i]--;
    }

    for (i = 0; i < m; i++)
    {
      scanf("%d", to + i);
      to[i]--;
    }

    roomn = 1;
    rooms[0] = n;
    for (i = 0; i < n; i++)
    {
      room[0][i] = 1;
    }

    for (i = 0; i < m; i++)
    {
      int size = 0;
      for (j = 0; j < roomn; j++)
      {
        if (room[j][from[i]] && room[j][to[i]])
          break;

      }

      for (k = 0; k < n; k++)
      {
        room[roomn][k] = 0;
      }

      rooms[roomn] = 2;
      room[roomn][from[i]] = 1;
      room[roomn][to[i]] = 1;
      for (k = from[i] + 1; k < to[i]; k++)
      {
        if (room[j][k])
        {
          room[j][k] = 0;
          room[roomn][k] = 1;
          rooms[roomn]++;
          rooms[j]--;
        }

      }

      roomn++;
    }

    minsize = n;
    for (i = 0; i < roomn; i++)
    {
      if (rooms[i] < minsize)
        minsize = rooms[i];

    }

    l = 1;
    r = minsize;
    while (l < r)
    {
      int m = l + (((r - l) + 1) / 2);
      if (checkc(m))
        l = m;
      else
        r = m - 1;

    }

    printf("Case #%d: %d\n", ti, l);
    f = new_fopen("sol", "rt");
    new_fgets(s, 1020, f);
    k = 0;
    while (k < n)
    {
      char *p;
      new_fgets(s, 1020, f);
      p = s + 2;
      while ((i = new_strtol(p, &p, 10)) != 0)
      {
        if (i > 0)
        {
          printf("%d ", ((i - 1) % l) + 1);
          fflush(stdout);
          k++;
        }

      }

    }

    printf("\n");
    new_fclose(f);
  }

  return 0;
}

long FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fprintf(FILE *stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE *stream);
int new_strncmp(const char *str1, const char *str2, size_t num);
int new_strtol(const char *str, char **endptr, int base)
{
  int first_iteration;
  return strtol(str, endptr, base);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fprintf(FILE *stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE *stream);
int new_strncmp(const char *str1, const char *str2, size_t num)
{
  int first_iteration;
  return strncmp(str1, str2, num);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fprintf(FILE *stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE *stream)
{
  int first_iteration;
  return fgets(str, num, stream);
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}

int new_fclose(FILE *stream)
{
  int first_iteration;
  return fclose(stream);
}


