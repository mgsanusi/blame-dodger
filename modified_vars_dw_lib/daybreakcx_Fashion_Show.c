#include <stdio.h>
#include <string.h>

#include <stddef.h>
int ti;
int tn;
int n;
int ent;
int i;
int arrcpy;
int k;
char a[101][101];
char ans;
char b[101][101];
char rela[200][200];
char exx[200];
char exy[200];
int pairx[200];
int pairy[200];
int visit[200];
void * new_memset(void *ptr, int value, int num);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int dfs(int, int);
int dfs(int ni, int rn)
{
  int first_iteration;
  int qy;
  for (qy = 0; qy < rn; ++qy)
    if (rela[ni][qy] && (!visit[qy]))
  {
    visit[qy] = 1;
    if ((pairy[qy] == (-1)) || dfs(pairy[qy], rn))
    {
      pairx[ni] = qy;
      pairy[qy] = ni;
      return 1;
    }

  }


  return 0;
}

int Main()
{
  int first_iteration;
  fscanf(stdin, "%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
  {
    fprintf(stdout, "Case #%d: ", ti);
    fscanf(stdin, "%d %d\n", &n, &ent);
    new_memset(a, 0, sizeof(a));
    new_memset(b, 0, sizeof(b));
    for (i = 0; i < ent; ++i)
    {
      fscanf(stdin, "%c %d %d\n", &ans, &arrcpy, &k);
      if (ans == '+')
        b[arrcpy - 1][k - 1] = (a[arrcpy - 1][k - 1] = 2);
      else
        if (ans == 'x')
        b[arrcpy - 1][k - 1] = (a[arrcpy - 1][k - 1] = 1);
      else
        b[arrcpy - 1][k - 1] = (a[arrcpy - 1][k - 1] = 3);


    }

    new_memset(rela, 0, sizeof(rela));
    new_memset(exx, 0, sizeof(exx));
    new_memset(exy, 0, sizeof(exy));
    for (i = 0; i < n; ++i)
      for (arrcpy = 0; arrcpy < n; ++arrcpy)
      if (a[i][arrcpy] & 1)
      exx[i] = (exy[arrcpy] = 1);



    for (i = 0; i < n; ++i)
      for (arrcpy = 0; arrcpy < n; ++arrcpy)
      if (((!exx[i]) && (!exy[arrcpy])) && (!(a[i][arrcpy] & 1)))
      rela[i][arrcpy] = 1;



    new_memset(pairx, -1, sizeof(pairx));
    new_memset(pairy, -1, sizeof(pairy));
    for (i = 0; i < n; ++i)
      if (pairx[i] == (-1))
    {
      new_memset(visit, 0, sizeof(visit));
      dfs(i, n);
    }


    for (i = 0; i < n; ++i)
      if (pairx[i] != (-1))
      b[i][pairx[i]] |= 1;


    new_memset(rela, 0, sizeof(rela));
    new_memset(exx, 0, sizeof(exx));
    new_memset(exy, 0, sizeof(exy));
    for (i = 0; i < n; ++i)
      for (arrcpy = 0; arrcpy < n; ++arrcpy)
      if (a[i][arrcpy] & 2)
      exx[i + arrcpy] = (exy[((n - 1) - i) + arrcpy] = 1);



    for (i = 0; i < n; ++i)
      for (arrcpy = 0; arrcpy < n; ++arrcpy)
      if (((!exx[i + arrcpy]) && (!exy[((n - 1) - i) + arrcpy])) && (!(a[i + arrcpy][((n - 1) - i) + arrcpy] & 2)))
      rela[i + arrcpy][((n - 1) - i) + arrcpy] = 1;



    new_memset(pairx, -1, sizeof(pairx));
    new_memset(pairy, -1, sizeof(pairy));
    for (i = 0; i < ((n << 1) - 1); ++i)
    {
      new_memset(visit, 0, sizeof(visit));
      dfs(i, (n << 1) - 1);
    }

    for (i = 0; i < ((n << 1) - 1); ++i)
      if (pairx[i] != (-1))
      b[(((i - pairx[i]) + n) - 1) >> 1][((i + pairx[i]) - (n - 1)) >> 1] |= 2;


    for (i = (ent = (k = 0)); i < n; ++i)
      for (arrcpy = 0; arrcpy < n; ++arrcpy)
    {
      if (b[i][arrcpy] == 3)
        ent += 2;
      else
        if (b[i][arrcpy])
        ent += 1;


      if (b[i][arrcpy] != a[i][arrcpy])
        ++k;

    }


    fprintf(stdout, "%d %d\n", ent, k);
    for (i = 0; i < n; ++i)
      for (arrcpy = 0; arrcpy < n; ++arrcpy)
      if (a[i][arrcpy] != b[i][arrcpy])
      fprintf(stdout, "%c %d %d\n", b[i][arrcpy] == 3 ? 'o' : b[i][arrcpy] == 1 ? 'x' : '+', i + 1, arrcpy + 1);



  }

  return 0;
}



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}