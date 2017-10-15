char team[10][10];
int teamGain[10];
int teamPlay[10];
double teamOwp[10];
double teamOowp[10];
int Main(void)
{
  int first_iteration;
  int t;
  int n;
  int mem;
  int b;
  double wpSum;
  int i;
  int length;
  int k;
  char temp;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    scanf("%d ", &n);
    for (length = 0; length < n; length++)
    {
      teamGain[length] = 0;
      teamPlay[length] = 0;
      teamOwp[length] = 0;
      teamOowp[length] = 0;
      for (k = 0; k < n; k++)
        scanf("%c ", &team[length][k]);

    }

    for (length = 0; length < n; length++)
      for (k = 0; k < n; k++)
    {
      switch (team[length][k])
      {
        case '.':
          break;

        case '1':
          teamGain[length]++;

        case '0':
          teamPlay[length]++;

      }

    }


    for (length = 0; length < n; length++)
    {
      wpSum = 0;
      for (k = 0; k < n; k++)
      {
        switch (team[length][k])
        {
          case '.':
            break;

          case '0':
            wpSum += (((double) teamGain[k]) - 1) / (teamPlay[k] - 1);
            break;

          case '1':
            wpSum += ((double) teamGain[k]) / (teamPlay[k] - 1);
            break;

        }

      }

      teamOwp[length] = wpSum / teamPlay[length];
    }

    for (length = 0; length < n; length++)
    {
      wpSum = 0;
      for (k = 0; k < n; k++)
      {
        switch (team[length][k])
        {
          case '.':
            break;

          case '0':

          case '1':
            wpSum += teamOwp[k];
            break;

        }

      }

      teamOowp[length] = wpSum / teamPlay[length];
    }

    printf("Case #%d:\n", i + 1);
    for (length = 0; length < n; length++)
    {
      wpSum = 0;
      wpSum = ((double) teamGain[length]) / teamPlay[length];
      wpSum = wpSum * 0.25;
      wpSum += 0.5 * teamOwp[length];
      wpSum += 0.25 * teamOowp[length];
      printf("%6f\n", wpSum);
    }

  }

  return 1;
}


