int count[1000];
int main()
{
  int first_iteration;
  int cases;
  int p;
  scanf("%d", &cases);
  for (p = 1; p <= cases; p++)
  {
    int a;
    int b;
    int k;
    scanf("%d%d%d", &a, &b, &k);
    int i;
    int j;
    memset(count, 0, sizeof(count));
    for (i = 0; i < a; i++)
      for (j = 0; j < b; j++)
      count[i & j]++;


    int ans = 0;
    for (i = 0; i < k; i++)
      ans += count[i];

    printf("Case #%d: %d\n", p, ans);
  }

  return 0;
}


