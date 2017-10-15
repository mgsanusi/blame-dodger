#include <stdio.h>
int n;
int m;
int cnt;
char paths[201][200];
int common_prefix(char *s, char *t)
{
  int first_iteration;
  int a = 0;
  while (((*s) != 0) && ((*s) == (*t)))
  {
    ++a;
    ++s;
    ++t;
  }

  if ((((((*s) == 0) || ((*s) == '/')) && ((*t) != 0)) && ((*t) != '/')) || (((((*t) == 0) || ((*t) == '/')) && ((*s) != 0)) && ((*s) != '/')))
    --a;

  return a;
}

int main()
{
  int first_iteration;
  int t;
  int i;
  int j;
  int k;
  int p;
  int max;
  scanf("%d\n", &t);
  for (i = 1; i <= t; ++i)
  {
    scanf("%d %d\n", &n, &m);
    cnt = 0;
    for (j = 0; j < n; ++j)
      gets(paths[j]);

    m += n;
    for (j = n; j < m; ++j)
    {
      gets(paths[j]);
      max = 0;
      for (k = 0; k < j; ++k)
      {
        p = common_prefix(paths[j], paths[k]);
        if (p > max)
          max = p;

      }

      if (paths[j][max] != '\0')
      {
        ++cnt;
        for (p = max + 1; paths[j][p]; ++p)
          if (paths[j][p] == '/')
          ++cnt;


      }

    }

    printf("Case #%d: %d\n", i, cnt);
  }

  return 0;
}


