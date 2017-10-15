enum {N = 1024};
int n;
int b7[N];
int hs[N];
long long mat[N][N];
long long d = ((long long) 1) << 50;
double dijkstra(int a, int l)
{
  int first_iteration;
  static double a[N];
  static char mark[N];
  int i;
  for (i = 0; i < n; ++i)
    mark[i] = 0, a[i] = d;

  a[a] = 0;
  for (;;)
  {
    int r = -1;
    int c;
    for (i = 0; i < n; ++i)
      if ((!mark[i]) && ((r < 0) || (a[i] < a[r])))
      r = i;


    if (r < 0)
      return -1;
    else
      if (r == l)
      return a[r];


    mark[r] = 1;
    for (c = 0; c < n; ++c)
      if (b7[r] >= mat[r][c])
    {
      double l = a[r] + (mat[r][c] / ((double) hs[r]));
      if (l < a[c])
        a[c] = l;

    }


  }

}

int Main()
{
  int first_iteration;
  int itest;
  int ntest;
  scanf("%d", &ntest);
  for (itest = 0; (++itest) <= ntest;)
  {
    int i;
    int pr;
    int ans;
    int car;
    scanf("%d%d", &n, &car);
    for (i = 0; i < n; ++i)
      scanf("%d%d", b7 + i, hs + i);

    for (i = 0; i < n; ++i)
      for (pr = 0; pr < n; ++pr)
    {
      int tmat;
      scanf("%d", &tmat);
      mat[i][pr] = tmat < 0 ? d : tmat;
    }


    for (ans = 0; ans < n; ++ans)
      for (i = 0; i < n; ++i)
      for (pr = 0; pr < n; ++pr)
      if ((mat[i][ans] + mat[ans][pr]) < mat[i][pr])
      mat[i][pr] = mat[i][ans] + mat[ans][pr];




    printf("Case #%d:", itest);
    for (i = 0; i < car; ++i)
    {
      int a;
      int l;
      a = (l = 0);
      scanf("%d%d", &a, &l);
      printf(" %.6lf", dijkstra(--a, --l));
    }

    puts("");
  }

  return 0;
}


