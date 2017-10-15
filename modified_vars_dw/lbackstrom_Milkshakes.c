int like[2001][2001];
int count[2001];
int happy[2001];
int malted[2001];
int Main()
{
  int first_iteration;
  int g;
  int pp;
  int extra_needed;
  int ans;
  int total;
  int patrick;
  int ti;
  int r;
  int l;
  int changed;
  int unhappy;
  scanf("%d", &g);
  for (ti = 1; ti <= g; ti++)
  {
    for (r = 0; r < 2001; r++)
    {
      malted[r] = 0;
      count[r] = 0;
    }

    scanf("%d%d", &pp, &extra_needed);
    for (r = 0; r < extra_needed; r++)
    {
      scanf("%d", &ans);
      count[r] = ans;
      for (l = 0; l < ans; l++)
      {
        scanf("%d%d", &total, &patrick);
        like[r][l] = total * ((patrick * 2) - 1);
      }

    }

    changed = 1;
    while (changed)
    {
      unhappy = 0;
      changed = 0;
      for (r = 0; r < extra_needed; r++)
      {
        happy[r] = 0;
      }

      for (r = 0; r < extra_needed; r++)
      {
        for (l = 0; l < count[r]; l++)
        {
          if ((like[r][l] > 0) && malted[like[r][l]])
          {
            happy[r] = 1;
          }
          else
            if ((like[r][l] < 0) && (!malted[-like[r][l]]))
          {
            happy[r] = 1;
          }


        }

      }

      for (r = 0; r < extra_needed; r++)
      {
        if (!happy[r])
        {
          unhappy++;
          for (l = 0; l < count[r]; l++)
          {
            if ((like[r][l] > 0) && (!malted[like[r][l]]))
            {
              malted[like[r][l]] = 1;
              changed = 1;
            }

          }

        }

      }

    }

    if (unhappy)
      printf("Case #%d: IMPOSSIBLE\n", ti);
    else
    {
      printf("Case #%d:", ti);
      for (r = 1; r <= pp; r++)
      {
        printf(" %d", malted[r]);
      }

      printf("\n");
    }

  }

}


