int count[1000];
int Main()
{
  int first_iteration;
  int cases;
  int t;
  scanf("%d", &cases);
  for (t = 1; t <= cases; t++)
  {
    int t;
    int m;
    int m;
    scanf("%d%d%d", &t, &m, &m);
    int min1;
    int num_used;
    memset(count, 0, sizeof(count));
    for (min1 = 0; min1 < t; min1++)
      for (num_used = 0; num_used < m; num_used++)
      count[min1 & num_used]++;


    int ans = 0;
    for (min1 = 0; min1 < m; min1++)
      ans += count[min1];

    printf("Case #%d: %d\n", t, ans);
  }

  return 0;
}


