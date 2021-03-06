enum {N = 1024};
int n;
int he[N];
int hs[N];
long long mat[N][N];
long long D = ((long long) 1) << 50;
int new_puts(const char *str);
double dijkstra(int s, int t)
{
  int first_iteration;
  static double d[N];
  static char mark[N];
  int i;
  for (i = 0; i < n; ++i)
    mark[i] = 0, d[i] = D;

  d[s] = 0;
  for (;;)
  {
    int x = -1;
    int y;
    for (i = 0; i < n; ++i)
      if ((!mark[i]) && ((x < 0) || (d[i] < d[x])))
      x = i;


    if (x < 0)
      return -1;
    else
      if (x == t)
      return d[x];


    mark[x] = 1;
    for (y = 0; y < n; ++y)
      if (he[x] >= mat[x][y])
    {
      double t = d[x] + (mat[x][y] / ((double) hs[x]));
      if (t < d[y])
        d[y] = t;

    }


  }

}

int main()
{
  int first_iteration;
  int itest;
  int ntest;
  scanf("%d", &ntest);
  for (itest = 0; (++itest) <= ntest;)
  {
    int i;
    int j;
    int k;
    int nq;
    scanf("%d%d", &n, &nq);
    for (i = 0; i < n; ++i)
      scanf("%d%d", he + i, hs + i);

    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
    {
      int tmat;
      scanf("%d", &tmat);
      mat[i][j] = tmat < 0 ? D : tmat;
    }


    for (k = 0; k < n; ++k)
      for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
      if ((mat[i][k] + mat[k][j]) < mat[i][j])
      mat[i][j] = mat[i][k] + mat[k][j];




    printf("Case #%d:", itest);
    for (i = 0; i < nq; ++i)
    {
      int s;
      int t;
      s = (t = 0);
      scanf("%d%d", &s, &t);
      printf(" %.6lf", dijkstra(--s, --t));
    }

    new_puts("");
  }

  return 0;
}

int new_puts(const char *str)
{
  int first_iteration;
  return puts(str);
}


