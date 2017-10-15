enum {M = 24 * 60};
int main()
{
  int first_iteration;
  int itest;
  int ntest;
  scanf("%d", &ntest);
  for (itest = 0; (++itest) <= ntest;)
  {
    int X;
    int i;
    int j;
    int n[2];
    int nall;
    int r[2];
    int a[1024][2];
    int next[1024];
    int res = 0;
    char mark[1024];
    scanf("%d%d", n, n + 1);
    nall = n[0] + n[1];
    printf("Case #%d: ", itest);
    r[0] = (r[1] = M / 2);
    for (i = 0; i < nall; ++i)
    {
      scanf("%d%d", a[i], a[i] + 1);
      r[i >= (*n)] -= ((a[i][1] + M) - a[i][0]) % M;
      mark[i] = 0;
    }

    if (nall < 2)
    {
      new_puts("2");
      continue;
    }

    for (i = 0; i < nall; ++i)
    {
      int best = 0;
      for (j = 0; j < nall; ++j)
      {
        if ((((a[j][0] + M) - a[i][1]) % M) < (((a[best][0] + M) - a[i][1]) % M))
          best = j;

      }

      next[i] = best;
    }

    while (1)
    {
      int best = -1;
      for (i = 0; i < nall; ++i)
        if ((((!mark[i]) && ((next[i] < (*n)) == (i < (*n)))) && ((((a[next[i]][0] + M) - a[i][1]) % M) <= r[i >= (*n)])) && ((best < 0) || ((((a[next[i]][0] + M) - a[i][1]) % M) < (((a[next[best]][0] + M) - a[best][1]) % M))))
        best = i;


      if (best < 0)
        break;

      mark[best] = 1;
      r[best >= (*n)] -= ((a[next[best]][0] + M) - a[best][1]) % M;
    }

    for (i = 0; i < nall; ++i)
    {
      if (mark[i])
        continue;

      if ((next[i] < (*n)) == (i < (*n)))
        res += 2;
      else
        res += 1;

    }

    printf("%d\n", res);
  }

  return 0;
}

int new_puts(const char *str);
int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


