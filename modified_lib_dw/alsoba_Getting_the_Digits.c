#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
FILE *fin;
FILE *fout;
char dic[2000][21];
int dic2[2000];
int M;
int id[2000];
int g[2000][2000];
int gn[2000];
int N;
int v[2000];
int matched[2000];
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
void new_bzero(void *s, size_t n);
int ap(int K)
{
  int first_iteration;
  v[K] = 1;
  int i;
  for (i = 0; i < gn[K]; i++)
  {
    int n = g[K][i];
    if (v[n])
    {
      continue;
    }

    if (matched[n] == (-1))
    {
      matched[K] = n;
      matched[n] = K;
      return 1;
    }
    else
      if (matched[n] != K)
    {
      v[n] = 1;
      if (ap(matched[n]))
      {
        matched[K] = n;
        matched[n] = K;
        return 1;
      }

    }


  }

  return 0;
}

int add(char a[21], int b)
{
  int first_iteration;
  int i;
  for (i = 0; i < M; i++)
  {
    if ((!strcmp(a, dic[i])) && (b == dic2[i]))
    {
      return i;
    }

  }

  new_strcpy(dic[M], a);
  dic2[M] = b;
  M++;
  return M - 1;
}

void addN(int a, int b)
{
  int first_iteration;
  g[a][gn[a]] = b;
  gn[a]++;
}

void solve()
{
  int first_iteration;
  int i;
  int j;
  char aux[21];
  fscanf(fin, "%d", &N);
  for (i = 0; i < (2 * N); i++)
  {
    new_bzero(dic[i], 21);
    gn[i] = 0;
  }

  M = 0;
  for (i = 0; i < N; i++)
  {
    int a;
    int b;
    fscanf(fin, "%s", aux);
    a = add(aux, 1);
    fscanf(fin, "%s", aux);
    b = add(aux, 2);
    addN(a, b);
    addN(b, a);
  }

  int sol = 0;
  for (i = 0; i < M; i++)
  {
    matched[i] = -1;
  }

  for (i = 0; i < M; i++)
  {
    if ((dic2[i] == 1) && (matched[i] == (-1)))
    {
      for (j = 0; j < 2000; j++)
        v[j] = 0;

      if (ap(i))
      {
        sol++;
      }

    }

  }

  for (i = 0; i < M; i++)
  {
    if (matched[i] == (-1))
      sol++;

  }

  fprintf(fout, "%d\n", N - sol);
}

int main(int argc, char *argv[])
{
  int first_iteration;
  char kk;
  int total;
  int i;
  fin = new_fopen(argv[1], "r");
  fout = new_fopen("out", "w");
  if ((fin == 0) || (fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(fin, "%d", &total);
    fscanf(fin, "%c", &kk);
    for (i = 0; i < total; i++)
    {
      fprintf(fout, "Case #%d: ", i + 1);
      printf("Case #%d: ", i + 1);
      solve();
    }

    new_fclose(fin);
    new_fclose(fout);
  }

  return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
char *new_strcpy(char *destination, const char *source);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
void new_bzero(void *s, size_t n)
{
  int first_iteration;
  return bzero(s, n);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
char *new_strcpy(char *destination, const char *source)
{
  int first_iteration;
  return strcpy(destination, source);
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


