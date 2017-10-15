#include <stdio.h>
#include <string.h>
#include <stddef.h>
int ti;
int tn;
int n;
int m;
int i;
int j;
int k;
char a[101][101];
char ch;
char b[101][101];
char rela[200][200];
char exx[200];
char exy[200];
int pairx[200];
int pairy[200];
int visited[200];
void *new_memset(void *ptr, int value, size_t num);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
int dfs(int, int);
int dfs(int u, int rn)
{
  int first_iteration;
  int v;
  for (v = 0; v < rn; ++v)
    if (rela[u][v] && (!visited[v]))
  {
    visited[v] = 1;
    if ((pairy[v] == (-1)) || dfs(pairy[v], rn))
    {
      pairx[u] = v;
      pairy[v] = u;
      return 1;
    }

  }


  return 0;
}

int main()
{
  int first_iteration;
  fscanf(stdin, "%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
  {
    fprintf(stdout, "Case #%d: ", ti);
    fscanf(stdin, "%d %d\n", &n, &m);
    new_memset(a, 0, sizeof(a));
    new_memset(b, 0, sizeof(b));
    for (i = 0; i < m; ++i)
    {
      fscanf(stdin, "%c %d %d\n", &ch, &j, &k);
      if (ch == '+')
        b[j - 1][k - 1] = (a[j - 1][k - 1] = 2);
      else
        if (ch == 'x')
        b[j - 1][k - 1] = (a[j - 1][k - 1] = 1);
      else
        b[j - 1][k - 1] = (a[j - 1][k - 1] = 3);


    }

    new_memset(rela, 0, sizeof(rela));
    new_memset(exx, 0, sizeof(exx));
    new_memset(exy, 0, sizeof(exy));
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
      if (a[i][j] & 1)
      exx[i] = (exy[j] = 1);



    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
      if (((!exx[i]) && (!exy[j])) && (!(a[i][j] & 1)))
      rela[i][j] = 1;



    new_memset(pairx, -1, sizeof(pairx));
    new_memset(pairy, -1, sizeof(pairy));
    for (i = 0; i < n; ++i)
      if (pairx[i] == (-1))
    {
      new_memset(visited, 0, sizeof(visited));
      dfs(i, n);
    }


    for (i = 0; i < n; ++i)
      if (pairx[i] != (-1))
      b[i][pairx[i]] |= 1;


    new_memset(rela, 0, sizeof(rela));
    new_memset(exx, 0, sizeof(exx));
    new_memset(exy, 0, sizeof(exy));
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
      if (a[i][j] & 2)
      exx[i + j] = (exy[((n - 1) - i) + j] = 1);



    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
      if (((!exx[i + j]) && (!exy[((n - 1) - i) + j])) && (!(a[i + j][((n - 1) - i) + j] & 2)))
      rela[i + j][((n - 1) - i) + j] = 1;



    new_memset(pairx, -1, sizeof(pairx));
    new_memset(pairy, -1, sizeof(pairy));
    for (i = 0; i < ((n << 1) - 1); ++i)
    {
      new_memset(visited, 0, sizeof(visited));
      dfs(i, (n << 1) - 1);
    }

    for (i = 0; i < ((n << 1) - 1); ++i)
      if (pairx[i] != (-1))
      b[(((i - pairx[i]) + n) - 1) >> 1][((i + pairx[i]) - (n - 1)) >> 1] |= 2;


    for (i = (m = (k = 0)); i < n; ++i)
      for (j = 0; j < n; ++j)
    {
      if (b[i][j] == 3)
        m += 2;
      else
        if (b[i][j])
        m += 1;


      if (b[i][j] != a[i][j])
        ++k;

    }


    fprintf(stdout, "%d %d\n", m, k);
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
      if (a[i][j] != b[i][j])
      fprintf(stdout, "%c %d %d\n", b[i][j] == 3 ? 'o' : b[i][j] == 1 ? 'x' : '+', i + 1, j + 1);



  }

  return 0;
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


