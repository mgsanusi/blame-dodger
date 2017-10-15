#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fin;
FILE *fout;
int d[30];
char l[102];
int K;
int L;
int S;
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int c(int j)
{
  int first_iteration;
  int i;
  int k = 0;
  for (i = j; i < L; i++, k++)
  {
    if (l[i] != l[k])
    {
      return 0;
    }

  }

  return 1;
}

int mx(int m)
{
  int first_iteration;
  int aux;
  aux = S - L;
  return (aux / m) + 1;
}

void solve()
{
  int first_iteration;
  int i;
  char kk;
  int m;
  for (i = 0; i < 30; i++)
    d[i] = 0;

  fscanf(fin, "%d %d %d", &K, &L, &S);
  fscanf(fin, "%c", &kk);
  for (i = 0; i < K; i++)
  {
    fscanf(fin, "%c", &kk);
    d[kk - 'A']++;
  }

  fscanf(fin, "%c", &kk);
  for (i = 0; i < L; i++)
  {
    fscanf(fin, "%c", &l[i]);
  }

  l[i] = '\0';
  fscanf(fin, "%c", &kk);
  double prob = 1;
  for (i = 0; i < L; i++)
  {
    if (d[l[i] - 'A'] == 0)
    {
      fprintf(fout, "0.0\n");
      return;
    }

    prob = (prob * (d[l[i] - 'A'] * 1.0)) / (K * 1.0);
  }

  m = L;
  for (i = 1; i < L; i++)
  {
    if (c(i))
    {
      m = i;
      break;
    }

  }

  fprintf(fout, "%lf\n", ((double) mx(m)) - (prob * ((S - L) + 1)));
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


