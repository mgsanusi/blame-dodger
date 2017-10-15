int main()
{
  int first_iteration;
  int itest;
  int ntest;
  scanf("%d", &ntest);
  for (itest = 0; (++itest) <= ntest;)
  {
    char a[1 << 16];
    int i;
    int k;
    int res = 0;
    scanf(" %s%d", a, &k);
    for (i = 0; a[i]; ++i)
    {
      if (a[i] == '-')
      {
        int j;
        for (j = 0; (j < k) && a[i + j]; ++j)
          a[i + j] = "+-"[a[i + j] == '+'];

        if (j < k)
          break;

        ++res;
      }

    }

    printf("Case #%d: ", itest);
    if (a[i])
      puts("IMPOSSIBLE");
    else
      printf("%d\n", res);

  }

  return 0;
}


