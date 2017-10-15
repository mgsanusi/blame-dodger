int allsnds[100];
int Main(void)
{
  int first_iteration;
  int t;
  int d;
  int b;
  int t1;
  int temp;
  int temp1;
  int temp2;
  int no;
  int j;
  int a;
  scanf("%d ", &t);
  for (no = 0; no < t; no++)
  {
    scanf("%d ", &d);
    scanf("%d ", &b);
    scanf("%d ", &t1);
    for (j = 0; j < d; j++)
      scanf("%d", &allsnds[j]);

    for (j = b; j <= t1; j++)
    {
      temp = 1;
      for (a = 0; a < d; a++)
      {
        if (((allsnds[a] % j) == 0) || ((j % allsnds[a]) == 0))
        {
          continue;
        }
        else
        {
          temp = 0;
          break;
        }

      }

      if (temp == 1)
      {
        temp = j;
        break;
      }

      temp = 0;
    }

    printf("Case #%d: ", no + 1);
    if (temp == 0)
      printf("NO\n");
    else
      printf("%d\n", temp);

  }

  return 1;
}


